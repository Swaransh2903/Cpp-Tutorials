// Encapsulation: Wrapping up of data members & functions in a single unit.

// Fully encapsulated class - saare ke saare data members are private.(info hiding)

// Advantages : Data hiding increasing security, if we want we can make class read only,helps in unit testing

#include<iostream>
using namespace std;
class Student{
    private:
        string name;
        int age;
        int height;

    public:
        int getAge()
        {
            return this->age;
        }
}
int main()
{
     
}

// Inheritance: class ki property inherit krri sub class
class Human{
    public:
    int height;
    int weight;
};
class Male: public Human{
    public:
    string colour;
};
int main()
{
    Male obj1;
    obj1.height;
}
// private data member of super class cannot be inherited.
// Types of Inheritance: Single,Multiple,MultiLvl,Hybrid,Hierarchial

// Polymorphism : many forms
// Compile Time Polymorphism (Function Overloading,Operator Overloading),Run Time Polymorphism

// Function Overloading cannot be achieved if you only change the return type,you'll have to change the i/p arguments also

// Operator Overloading:

void operator+ (B &obj)
{
    int value1 = this->a;
    int value2 =obj.a;
    cout<< value2-value1;

}

int main()
{
    B obj1,obj2;
    obj1.a=4,obj2.a=8;
    obj2-obj1;
}

// Runtime Polymorphism (Function/Method Overriding):

// same method maanlo subclass ne inherit krdia with same parameters,name & return type
//  but different implementation n agr maanlo subclass ka obj bnakr invoke kiya hmne wo method toh konsa wla
// implementation use kre? -> by default toh subclass wli implementation hogi


// Abstraction - Implementation hiding