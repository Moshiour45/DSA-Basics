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




string infixToPrefix(string &infix){
    string prefix = "";
    // Reversing the infix notion
    reverse(infix.begin(), infix.end());
    // converting the braces to make a proper reverse notaion
    for(auto &u : infix){
        if(u == '('){
            u = ')';
        }else if(u == ')'){
            u = '(';
        }
    }
    
    // converting the reverse infix into postfix
    stack<char> st;

    for(auto u : infix){
        if(isalnum(u)){
            prefix += u;        
        }else if(u == '('){
            st.push(u);
        }else if(u == ')'){
            while(!st.empty() and st.top() != '('){
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() and precedence(u) < precedence(st.top())){
                prefix += st.top();
                st.pop();
            }
            st.push(u);
        }
    }

    while(!st.empty()){
        prefix += st.top();
        st.pop();
    }
    
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main(){
    //optimize();
    string infix = "(a*x)+(b*y)+c";
    cout << "Infix : " << infix << endl;
    cout << "Prefix : " << infixToPrefix(infix) << endl;
    return 0;
}