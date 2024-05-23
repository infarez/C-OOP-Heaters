#ifndef HEATERS_H_INCLUDED
#define HEATERS_H_INCLUDED

using namespace std;

enum class FuelType : int
{
      ELECTRIC = 0,
      WOOD = 1,
      GAS = 2,
      Unknown = -1
};

enum class HeaterType : int
{
      Kamin,
      Sauna_Bake,
      Bake_Talk,
      Unknown = -1
};
class Heaters
{
protected:
      FuelType Fuel;
      int Firewood; // сколько дров
      int vsauna; // объЄм сауны, который может отапливать обогреватель


public:
      Heaters() :  Firewood(0), vsauna(0) {}
      virtual ~Heaters() {}
      virtual void New() = 0; // новый ли обогреватель
      virtual bool Sound() const { return false; } // есть ли звук?
      FuelType GetFuel() const {return Fuel; }
      virtual HeaterType GetType() const = 0;
      int GetSaunaVolume() const { return vsauna; }
      int GetHetersFirewood() const { return Firewood; }
      virtual bool Stone() const { return false; } //камни есть?
      virtual bool WaterTank() const {return false;} // бак с водой есть?

};

typedef Heaters *HeatersPtr;

class Kamin : public Heaters
{
public:
      Kamin(FuelType fuel, int firewood, int saunaVolume) : Heaters()
      {
            Fuel = fuel;
            Firewood = firewood;
            vsauna = saunaVolume;
      }

      virtual void New() {wcout << L" амин" << endl;}
      FuelType GetFuel() const {return Fuel;}
      HeaterType GetType() const { return HeaterType::Kamin; }
      bool Sound() const { return true; }


};



class Sauna_Bake : public Heaters
{
public:
      Sauna_Bake(FuelType fuel, int firewood, int saunaVolume) : Heaters()
      {
            Fuel = fuel;
            Firewood = firewood;
            vsauna = saunaVolume;
      }

      virtual void New() {wcout << L"Ѕанна€ печь нова€" << endl;}
      FuelType GetFuel() const {return Fuel;}
      HeaterType GetType() const { return HeaterType::Sauna_Bake; }
      bool WaterTank() const {return false;}

};
class Bake_Talk : public Heaters
{
public:
      Bake_Talk(FuelType fuel, int firewood, int saunaVolume) : Heaters()
      {
            Fuel = fuel;
            Firewood = firewood;
            vsauna = saunaVolume;
      }

      virtual void New() {wcout << L"ѕечь из талька нова€" << endl;}
      FuelType GetFuel() const {return Fuel;}
      HeaterType GetType() const { return HeaterType::Bake_Talk; }
      bool Stone() const { return false; }
};



//  онтейнеры
class HeatersContainer // базовый класс
{
private:
      HeatersPtr *HeatersBox; // указатель на указатель
      int HeatersCount;
      int MaxSize;

public:
      HeatersContainer(int MaxSize);
      virtual ~HeatersContainer();
      void AddHeaters(HeatersPtr newHeaters); // добавить
      int GetCount() const {return HeatersCount; };
      virtual HeatersPtr GetByIndex(int index) const {return HeatersBox[index];} // посчитать

};



class VectorHeatersContainer : public HeatersContainer
{
private:
      vector<HeatersPtr> HeatersBox;
public:

      void AddHeaters(HeatersPtr newHeaters) {HeatersBox.push_back(newHeaters);}
      int GetCount() const { return HeatersBox.size(); }
      HeatersPtr GetByIndex(int index) const {return HeatersBox[index];}
};




class ListHeatersContainer : public HeatersContainer
{
private:
      list<HeatersPtr> HeatersBox;

public:
      void AddHeaters(HeatersPtr newHeaters) {HeatersBox.push_back(newHeaters);}
      int GetCount() const { return HeatersBox.size(); }

};



#endif // HEATERS_H_INCLUDED
