// this program is convert infix experssion to postfix experssion
// made by : ahmed mohamed taha
// id : 20210033

// input format : 
// one line contain infix experssion ex: "X^Y / (5*Z) + 2"

// output format :
// one line conatin postfix experssion ex: "XY^5Z*/2+"

#include <bits/stdc++.h>
using namespace std;

map <char, int> prio;

void fill_prio();

int main(){
    fill_prio();
    
    stack<char> op;
    string infix;  
    cout << "please enter the infix experssion : ";
    getline(cin, infix);
    
    // remove spaces from string
    infix.erase(remove_if(infix.begin(), infix.end(), ::isspace), infix.end());

    cout << "postfix experssion is : ";
    for(int i = 0; i < infix.size(); i++){
        if(isalpha(infix[i]))
            cout << infix[i];

        else{
            int bracket = 1;
            if(op.size() == 0 || infix[i] == '(')
                goto push;
            
            while (op.size() > 0 && prio[infix[i]] >= prio[op.top()]){
                // check if we are in the same parentheses
                if(op.top() == '(')
                    bracket--;
                if(bracket < 0)
                    break;

                if(op.top() != ')' && op.top() != '(')
                    cout << op.top();
                op.pop();
            }

            push:
            op.push(infix[i]);
        }
    }

    while (op.size() > 0){
        if(op.top() != ')' && op.top() != '(')
            cout << op.top();
        op.pop();
    }
}

void fill_prio(){
    prio['('] = 4;
    prio[')'] = 4;
    prio['+'] = 3;
    prio['-'] = 3;
    prio['*'] = 2;
    prio['/'] = 2;
    prio['%'] = 1;
    prio['^'] = 1;
}