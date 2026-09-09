#ifndef PATTERN_H_INCLUDED
#define PATTERN_H_INCLUDED

template<class Type> // шаблонный класс --- можем использовать в качестве родительского класса дл€ итераторов, обрабатывающих данные –ј«Ќџ’ типов
// Type - это параметр шаблона, который будет заменен конкретным типом при создании экземпл€ра класса.
class Iterator
{
protected:
      Iterator() {}
// Ќельз€ создать экземпл€р класса Iterator напр€мую.
//  онструктор служит дл€ предотвращени€ создани€ объектов в рамках самого класса, позвол€€ только наследующим классам использовать его.
public:
      virtual ~Iterator() {}
      virtual void First() = 0; // на первый элемент
      virtual void Next() = 0; // итератор ---> следующий элемент
      virtual bool IsDone() const = 0; // true, если итераци€ закончена
      virtual Type GetCurrent() const = 0; // текущий элемент
};

template<class Type>
class IteratorDecorator : public Iterator<Type> //  используем шаблонный класс Iterator, замен€€ его параметр Type на конкретный тип данных, с которым мы хотим работать.
{
protected:
      Iterator<Type> *It; // указатель на базовый класс

public:
      IteratorDecorator(Iterator<Type> *it)
      {
            It = it;
      }

      virtual ~IteratorDecorator() { delete It; }
      void Next() {It->Next(); }
      bool IsDone() const { return It->IsDone(); }
      Type GetCurrent() const { return It->GetCurrent(); }
};
#endif // PATTERN_H_INCLUDED
