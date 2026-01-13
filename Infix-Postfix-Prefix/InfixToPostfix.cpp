# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'


// The function represents the precedence of (+,-,*,/)
int precedence(char op){
    if(op == '+' or op == '-'){
        return 1;
    }
    if(op == '*' or op == '/'){
        return 2;
    }
    return 0;
}

string infixToPostfix(string &infix){
    // Initialize an empty stack and string
    stack<char>st;
    string posfix = "";

    for(auto u : infix){
        // Returns zero if the the character is not any alphabet and number
        if(isalnum(u)){
            //insert the operands
            posfix += u;
        }else if(u == '('){
            st.push(u);
        }else if(u == ')'){
            while(st.top() !='('){
                posfix += st.top();
                st.pop();
            }
            // Erase the '(' stored in the stack at the end
            st.pop();
        }else{
            while(!st.empty() and precedence(u) <= precedence(st.top())){
                posfix += st.top();
                st.pop();
            }
            st.push(u);
        }
    }
    // pop all the remaining elements
    while(!st.empty()){
        posfix += st.top();
        st.pop();
    }
    return posfix;
}

int main(){
    //optimize();
    string infix = "(a*x)+(b*y)+c";
    cout << "Infix : " << infix << endl;
    cout << "Postfix : " << infixToPostfix(infix) << endl;
    return 0;
}