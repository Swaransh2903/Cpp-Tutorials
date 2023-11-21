// Variables ki mapping kisi number se hongi symbol table mein jo ki darsha rha h ki wha pe wo variable stored h

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 100;
    // printing value of num
    cout << num << endl;
    // printing address i.e the value to which num is mapped in symbol table(will come in hexadecimal format)
    cout << "address of num is: " << &num << endl;

    // creating pointer
    // yha pe ptr wle dabbe ke andar num k address store hai
    // ptr is a pointer to int data type
    int *ptr = &num;

    // * dereference operator hai isko agr pointer ke aage lgado to uss address ka value print krdega
    cout << ptr << endl;
    cout << *ptr << endl;

    // Note: pointer to hmesha address hi store krega, therefore uska size hmesha 8 bytes aane wla h.

    // Incrementing value pointer is pointing to by dereference:
    int *p = &num;
    // both give same ans
    cout << (*p)++ << endl;
    cout << num << endl;

    // copying a pointer
    int *q = p;
    cout << p << "-" << q << endl;
    cout << *p << "-" << *q << endl;

    // pointer arithmetic:

    // yha pe nums ki value ek se bdh jaega kyuki uska address p me stored h aur p ko jb dereference krte h to hme
    // value milti h n us value ko hm increment krre toh 1 se bdh jaegi
    *p = *p + 1;

    // However when we do the same thing in case of pointer toh kyuki pointer 8byte liye baitha toh ek ka increment
    // usko 8 byte aage le jaega
    p = p + 1;

    // Okay so I was going through a YouTube video wherein the guy was teaching pointers.
    // When he printed the size of an integer pointer it came out to be 8 bytes but when he did an increment
    //  on the pointer(i.e assume 'p' is a pointer that holds an integer value's address , on doing sizeof(p)
    // -> ans came out to be 8 bytes , but on doing p=p+1  , the pointer got shifted by 4 bytes only) .
    //  My question is when a pointer stores 8 bytes of data shouldn't it shift by 8 bytes on incrementing it by 1?

//     The behavior you observed is related to pointer arithmetic in C++. When you increment a pointer, it is adjusted by the size of the data type it points to, not the size of the pointer itself.

// In C++, the sizeof operator returns the size in bytes of the type of its operand. So when you use sizeof(p), where p is a pointer, it gives you the size of the pointer itself, which is typically 8 bytes on 64-bit systems.

// However, when you perform pointer arithmetic by adding an integer value to a pointer, the pointer is adjusted by a number of bytes based on the size of the data type it points to. In your case, you mentioned the pointer p holds the address of an integer value. In most systems, the size of an int is 4 bytes.

// So when you do p = p + 1, the pointer p is incremented by the size of int, which is 4 bytes in your case. This is because pointer arithmetic automatically scales the adjustment based on the size of the pointed-to type.

// To summarize, sizeof returns the size of the pointer itself, while pointer arithmetic adjusts the pointer by the size of the data type it points to.
}
