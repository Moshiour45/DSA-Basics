# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'


// Implimenting Stack using a linked and taking advantage of in build functions that already exists
class Stack{
    list<int> ll; // This is doubly linked list in-built
public:
    void push(int val){
        ll.push_front(val); // As we are updating head
    }
    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front();
    }
    bool empty(){
        return (ll.size() <= 0);
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