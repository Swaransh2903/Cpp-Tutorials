#include<bits/stdc++.h>
using namespace std;
void print(int *p)
{
    cout<<*p<<endl;
}
void update(int *p)
{
    p = p + 1;
}
int main()
{
    int arr[10];
    // Array ka naam uss array ke phle block ka address darsha rha hoga.
    cout<<arr<<endl;
    // dusra tareeka
    cout<<&arr[0]<<endl;
    // teesra tareeka
    cout<<&arr<<endl;

    // *arr + 1 vs *(arr+1)
    // ye phle dereference krega toh arr[0] ajaega n then uski value ek se increment hojaegi
    cout<<*arr+1<<endl;
    // ye phle increment krega. Kisko? ek pointer ko kyuki arr first address darsha rha aur uspe ek ka increment yani
    // ek memory location ka increment yaani arr[1] ke address pe ana  n then usko dereference kiya toh uski value
    // print hogyi
    cout<<*(arr+1)<<endl;

    // arr[i] = *(arr+i)

    // Pointer vs Array:
    cout<<sizeof(arr)<<endl; // 40 bytes
    int *p = arr;
    cout<<sizeof(p)<<endl; // 8 bytes
    couut<<sizeof(&arr)<<endl; //8 bytes

    arr = arr + 1; //error dega. kyu? symbol table ke content ko aap ni change kr skte , kyuki iss particular
    // arr ke liye symbol table me phle hi address assigned h

    // Array : Integer vs Character 

    char ch[6]="abcde";
    cout<<arr<<endl; //address
    cout<<ch<<endl; //abcde 
    // kya smjh aya? for int and char array cout fnc differently implemented hai

    // isilie agr aap ye krte
    char *cptr=&ch[0];
    cout<< cptr<<endl; //prints entire string

    char temp='z';
    char *newp = &z;
    cout<< newp<<endl; //jbtk null char ni milega tb tk print krega


    // Functions ke sath khelte h ab
    int value = 5 ;
    int *p1=&value;
    print(p1);

    cout<<"Before"<<p1<<endl;
    update(p1);
    cout<<"After"<<p1<<endl;
    
    // Dono me same value, aisa kyu? local variable :)
    // Hnn bt uske andar ki value update hojaegi
    cout<<*p1<<endl;
    updateval(p1);
    cout<<*p1<<endl;

    // Jb function me array pass krte ho toh wo puri array na paas hone ki jgh sirf phle location ka address pass hota h

    // isse fayda kya? tm part of array bhi pass kr skte ho
    // getSum(arr+3) -> 3rd index se end tk ka dedega sum

}

