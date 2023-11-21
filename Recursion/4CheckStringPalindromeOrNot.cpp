#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(int i,string s,int n)
{
    if(i >= n/2)
    {
        // cout<<true<<endl;
        return true;
    }
    if(s[i] == s[n-i-1])
    {
        // cout<<i<<" "<<n-i-1<<endl;
        return checkPalindrome(i+1,s,n);
    }
    return false;

}
int main()
{
    string s = "madam";
    bool check = checkPalindrome(0,s,s.size());
    cout<<check;
}