/*
**********  First task on  OOPcourse                                         ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 16.07.2021                                                  ****
*/


//•••Done 1___Создать класс Power, который содержит два вещественных числа.
//•••         Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
//•••         Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate,
//•••         который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
//
//•••Done 2___Написать класс с именем RGBA, который содержит 4 переменные-члена типа
//•••         std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
//•••         Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
//•••         Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
//•••         Написать функцию print(), которая будет выводить значения переменных-членов.
//
//•••Done 3___Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//•••         private-массив целых чисел длиной 10;
//•••         private целочисленное значение для отслеживания длины стека;
//•••         public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//•••         public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false,
//•••         если массив уже заполнен, и true в противном случае;
//•••         public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
//•••         public-метод с именем print(), который будет выводить все значения стека.



#include <iostream>
#include <math.h>
#include <cstdint>
#include <cassert>

using namespace std;

class Stack
{
private:
    int m_array[10]; // Our stack element massive
    int m_next; // index as a pointer for next free place for data

public:

    void reset()
    {
        m_next = 0;
        for (int i = 0; i < 10; ++i)
            m_array[i] = 0;
    }

    bool push(int value)
    {
        // if stack is full we have to return false
        if (m_next == 10)
            return false;

        m_array[m_next++] = value; // adding element at next free place and increasing m_next
        return true;
    }

    int pop()
    {
        // if no elements we can use assert (or false message)
        assert (m_next > 0);

                // m_next is pointer for next free element plase that's why our data is m_next-1.
                // int val = m_array[m_next-1]; // last element of massive with data
                // --m_next; // m_next should be decreased because we are popped out one element
                // return val; // return our value
        return m_array[--m_next];// all previous words is only one line)))
    }

    void print()
    {
        std::cout << "( ";
        for (int i = 0; i < m_next; ++i)
            std::cout << m_array[i] << ' ';
        std::cout << ")\n";
    }
};



class RGBA
{
 private:
 uint8_t m_red=0;
 uint8_t m_green=0;
 uint8_t m_blue=0;
 uint8_t m_alpha=255;

public:
 RGBA()
 {

 }
 RGBA(uint8_t red,uint8_t green,uint8_t blue, uint8_t alpha )
       :m_red(red),m_green(green),m_blue(blue),m_alpha(alpha)
 {

 }
 void print()
 {
     cout<<"RGBA Class members are:"<<endl;
     cout<<"m_red: "<<+m_red<<" n_green: "<<+m_green<<" m_blue: "<<+m_blue<<" m_alpha: "<<+m_alpha<<endl;//+  prior every variable for correct output mode
 }

};

class Power
{
private:


float val_1;
float val_2;
public:

void set(float value_1, float value_2)
{
    val_1=value_1;
    val_2=value_2;
}
void calculate()
{
    cout<<"result of val_1^val_2 is : "<<pow(val_1,val_2)<<endl;
}
void print()
{
std::cout << "Power_Value_1: "<<val_1<<endl<<"Power_Value_2: "<<val_2<<endl;
}
};
int main()
{
       cout<<"Let's begin....."<<endl;


Power data;
data.set(5,6);
data.print();
data.calculate();


RGBA Colors1;
Colors1.print();

RGBA Colors2(5,7,82,200);
Colors2.print();




Stack stack;
   stack.reset();

   stack.print();

   stack.push(3);
   stack.push(7);
   stack.push(5);
   stack.print();

   stack.pop();
   stack.print();

   stack.pop();
   stack.pop();
   stack.print();
   stack.pop();// at this line we are checking assert script

return 0;
}




