//  Object -> 1) state/properties , 2) behaviour , 3) instance of class.

#include<bits/stdc++.h>
using namespace std;
class Hero// ek type ka template
{
    int health,level; 
    // this keyword:  iske andar current obj ka address store hota hai, thus this is a pointer
    Hero(int health)
    {
        this->health = health;
    }
}
int main()
{
    hero h1; //object created of type hero

    // for an empty class -> 1 byte of memory is allocated to the object

    // access property using '.' (dot) operator
    h1.health -> // by default private

    // access modifiers : public,private,protected

    // static allocation
    Hero h2;

    // Dynamic allocation
    Hero *b = new Health;
    cout<< (*b).health<<endl;
    // or
    cout<< b->health<<endl;

    // jb bhi hm ek object ko create krte h automatically constructor create hota.Default constructor khudse pdha rhta
    // h ,explicitly bnane ki zaruvat ni

    // iske baad ata h Parametrized constructor

    //static
    Hero h1(10);
    //dynamic
    Hero *h2 = new Hero(10);

   //iske baad ata h copy costructor:

   Hero S(70,'C');
   S-> print();

   Hero R(S); // copy constructor invoked , S ke saari cheezein R me copied.
   
   Hero(Hero temp) //wrong
   {
      this->level = temp->level
   }

   Hero(Hero& temp)//right


   //memory deallocate krne keliye:  Destructor (tilde sign ~)
   // jo cheezein statically allocate krate h uske liye destructor automatically call hota h, but dynamic
   // walo keliye manually call krna hoga 
   delete S;

   // static keywords: class ko belong krta hai.Isko access krne keliye object bnane ki zaruvat ni pdhti    
}