# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'


// Implimenting Stack using a vector and taking advantage of in build functions that already exists
class Stack{
    vector<int> v;
public:
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v.back();
    }
    bool empty(){
        return (v.size() <= 0);
    }
};

int main(){
    //optimize();
    Stack st;
    for(int i = 0; i <= 5; i++){
        st.push(i);
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}