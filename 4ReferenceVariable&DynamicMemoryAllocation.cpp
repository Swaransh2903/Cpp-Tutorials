#include<bits/stdc++.h>
using namespace std;
void update(int& n)
{
    n++;
}
int main()
{
    int i=5;
    // Reference variable bnana yha pe both i and j same address k match honge ymbol table i.e same variable but diff
    // naam i.e ek se zyada naam
    int &j = i;
    i++;
    cout<< i <<endl; //6
    j++;
    cout<< i <<endl; //7

    // Pass byy reference
    int n=5;
    cout<<n<<endl; //5
    update(n);
    cout<<n<<endl; //6

    
    // yha pe return type reference hai jo ki galat h kyuki 'a' ka scope fnc ke andar h n bahar to wo destroy hoga
    // toh local variable ka reference bahar kya dega?Same dikkat pointer return me bhi aaegi
    int& func(int a)
    {
        int num=a;
        int& ans=a; // creating reference variable
        return ans; //returning reference variable
    }

    // Question Time?

    // int n; cin>>n; int arr[n]; Why is this regarded a bad practice and why we should go for dynamic 
    // size allocation when size is not known at compile time ? Explain in very simple terms but in great depth

    // Hello Answer:

    // The code snippet you provided, int n; cin >> n; int arr[n];, is called a Variable-Length Array (VLA), 
    // where the size of the array arr is determined by the value of n entered by the user at runtime.
    //  While some compilers may support VLAs as an extension to the C++ language, they are not a standard feature 
    // in C++ and are generally considered a bad practice.

    // 1) Compiler Limitations: The C++ language standard mandates that array sizes must be known at compile time. 
    // This allows the compiler to allocate memory and optimize the code accordingly. VLAs violate this rule, 
    // as their size is determined at runtime. Consequently, not all compilers fully support VLAs, leading to 
    // compatibility issues and potential errors when compiling your code on different systems or with different 
    // compilers.

    // 2) Stack Overflow: VLAs are usually allocated on the stack, which has a limited size. The size of the stack
    //  depends on factors such as the operating system and available memory. When you create a large VLA, there's
    //  a risk of exceeding the stack size, resulting in a stack overflow. 


    // Dynamic Memory Allocation: To overcome the limitations of VLAs, dynamic memory allocation is 
    // recommended when the size is not known at compile time. In C++, you can use features such as new and 
    // delete or better yet, modern techniques like std::vector or std::array to dynamically allocate and manage 
    // memory for your array. These approaches ensure proper memory management, compatibility across different systems, and avoid the risk of stack overflow.
    // This is because during dynamic memory allocation memory is assigned using heap which is very large compared
    // to stack memory and can accomodate the large memory size specified during runtime easily.

    // new char ; character size ki memory reserve hogyi heap mein -> return krta h address toh hme store krna hoga
    // pointer mein.Wo pointer stack me store hoga.

    int num=4;
    int *p = &num; //static allocation : size of pointer 8 byte
    int *p2 = new int ; // pointer size 8 byte + 4byte memory reserve in heap , therefore p2 size 12byte
     
    int *p3=new int[5]; //array create krre heap memory ke andar

    while(true)
    {
        int p=5;
        int *q=p; // memory create hori aur bahar destroy
    }

    //bhayanak cheez

    while(true)
    {
        int *q = new int //kyuki memory heap me create hori,wha automatically destroy ni hoti isilie ek time
        // aisa ayega ki heap memory poori allocate hojaegi n then program crash.
        // kitni memory bharegi? jo heap me aari 'q' ki memory apne aap delete hojaegi kyuki wo toh stack me create
        // hora bt new int hr baar 4 byte ki memory heap me bnara wo ni delete hogi apne aap
    }

    // samasyan ka solution?

    //  manually memory delete using delete keyword.
    delete q; // variable keliye
    delete []q; // array keliye
}