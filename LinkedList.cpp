# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'
# define yes cout<<"YES"<<endl
# define no cout<<"NO"<<endl


// This class represents nodee which will be used in my linkedlist
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        next = NULL;
    }
};


// Actual Linked List which will be used to assign values and addressses to the nodes
class List{
    Node* head;
    Node * tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_back(int val){
        if(head == NULL){
            head = tail = new Node(val);
        }else{
            Node* newNode = new Node(val);
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void push_front(int val){
        if(head == NULL){
            head = tail = new Node(val);
        }else{
            Node* newNode = new Node(val);
            newNode -> next = head;
            head = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* deletedNode = head;
        head = head -> next;
        if(head == NULL){
            tail = NULL;
        }
        delete deletedNode;
    }

    void pop_back(){
        if(head == NULL){
            return;
        }

        if(head == tail){
            Node* deletedNode = tail;
            head = tail = NULL;
            delete deletedNode;
            return;
        }
        Node* prev = head;
        while(prev -> next != tail){
            prev = prev -> next;
        }
        Node* deletedNode = tail;
        tail = prev;
        tail -> next = NULL;
        delete deletedNode;
    }

    void insert(int val, int idx){
        if(idx < 0){
            return;
        }
        if(idx == 0){
            push_front(val);
            return;
        }
        if(head == NULL){
            push_back(val);
            return;
        }
        Node* temp = head;
        int i = 0;
        while(i < idx - 1){
            temp = temp -> next;
            i++;
        }
        Node* insertedNode = new Node(val);
        insertedNode -> next = temp -> next;
        temp -> next = insertedNode;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << endl;
            temp = temp -> next;
        }
    }
};

int main(){
    //optimize();
    
    List l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    
    l.insert(-1,3);
    l.insert(1, 0);
    l.printList();
    
    return 0;
}