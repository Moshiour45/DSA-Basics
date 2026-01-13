# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

// Arrays can be used also to implement stack using both static and dynamic memory!
// Dynamic memory is covered on vector part

// Static Array
const int MAX = 50;
class Stack{
    int arr[MAX];
    int topIdx = -1;
public:
    void push(int val){
        if(topIdx == MAX - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIdx] = val;
    }
    void pop(){
        if(topIdx== -1){
            cout << "Out of bound" << endl;
            return;
        }
        topIdx--;
    }
    int top(){
        if(topIdx == -1){
            cout << "Stack is empty" << endl;
            return - 1;
        }
        return arr[topIdx];
    }
    bool empty(){
        return topIdx== -1;
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