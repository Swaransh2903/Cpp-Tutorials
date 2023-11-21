#include<iostream>
#include<stack>
using namespace std;
bool redundant(stack<char>& s,string expression,int size)
{
    for(int i=0;i<expression.size();i++)
    {
        char elem = expression[i];

        // Note : we'll say that brackets are not redundant , if there is an operator b/w the opening and closing 
        // parenthesis , so in case if we have a opening brace or an operator we push it in the stack.
        if(elem == '(' || elem == '+' || elem == '-' || elem == '*' || elem == '/')
        {
            s.push(elem);
        }
        // if suppose we encounter a closing brace, then comes the main task to see if any operator has preceeded it
        // or not before reaching the matching open brace.
        else if(elem == ')')
        {
            // initially we keep flag as true , as soon as we find an operator before reaching the opening brace, we
            // will conclude that expression within braces as not redundant and we'll set flag to false.
            bool isRedundant = true;

            // we have kept this check part in a loop , because we can encounter multiple operators before reaching 
            // a matching opening braces for a closed one.
            while(s.top()!='(')
            {
                if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                    isRedundant = false;

                // we need to keep on popping the elements until we reach the opening braces
                s.pop();
            }
            if(isRedundant == true)
                return true;
            // once we found out that the expression was not redundant , we would have popped out all the operators 
            // in b/w and so we will have to pop out the corresponding opening brace also, because let's assume that
            // if we don't do that , then in future if a closing brace comes instantly then it will be matched with 
            // the present opening brace and there might be a scenario that it might evaluate the correct 
            // expression as false , because we matched with a wrong parenthesis. 
            s.pop();
        }
    }
    return false;
}
int main()
{
    string expression = "(a+b-(c-d))";
    stack<char> s;
    // cout<<0;
    cout<<redundant(s,expression,expression.size());
}