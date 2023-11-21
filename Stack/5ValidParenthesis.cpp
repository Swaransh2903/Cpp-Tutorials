//  [{()}]  -> valid , [{]})()( -> invalid

#include<iostream>
using namespace std;
#include<stack>
bool isValid(stack<char> &s,string &expression, int size)
{
    int i = 0;
    while(i<size)
    {
        char val = expression[i];
        if(val == '[' || val == '{' || val == '(')
            s.push(val);

        //  this check we are adding in order to check that we don't end up matching numbers in an expression
        else if(val == ']' || val == '}' || val == ')')
        {
            // if stack was already empty that means we are encountering a closing braces corresponding to which no
            // opening braces was present and hence that wouldn't be a valid expression.
            if(s.empty())
                return false;
            char top = s.top();

            // the checks within see if we are getting the correct match for every closing braces else it would result
            // in termination due to mismatching.
            if(val == ']')
            {
                if(top == '[')
                    s.pop();
                else
                    return false;
            }
            if(val == '}')
            {
                if(top == '{')
                    s.pop();
                else
                    return false;
            }
            if(val == ')')
            {
                if(top == '(')
                    s.pop();
                else
                    return false;
            }
        }
        i++;
    }
    //  at the end of the iteration if the stack was empty, that means for every opening braces we were able to find
    // a closing match and so we return true else false.
    if(s.empty())
        return true;
    else
        return false;
}
int main()
{
    string expression = "[1+2{=3)]";
    stack<char> s;
    // s.push('[');
    // s.push('1');
    // s.push('+');
    // s.push('2');
    // s.push('{');
    // s.push('=');
    // s.push('3');
    // s.push('}');
    // s.push(']');

    cout<<isValid(s,expression,expression.size());
}