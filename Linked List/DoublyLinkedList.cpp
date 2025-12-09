# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'
# define yes cout<<"YES"<<endl
# define no cout<<"NO"<<endl

class Node{
public:
    Node* prev;
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        next = prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;
public:
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }


    void pop_front(){
        if(head == NULL){
            return;
        }else{
            // The node to be deleted is pointed by this pointer
            Node* deletedNode = head;
            // head moved one step ahead
            head = head -> next;
        
            if(head == NULL){
                tail = NULL; // If list has only one element then we moved head only, tial is pointing to the 
                             // memory that is going to be deleted now. Therefore, we are making tail pointing NULL
            }else{
                head -> prev = NULL;
            }
            delete deletedNode;
        }
    }

    void pop_back(){
        if(head == NULL){
            return;
        }else{
            Node* deletedNode = tail;
            tail = tail -> prev;
            if(tail == NULL){
                head = NULL;
            }else{
                tail -> next = NULL;
            }
            delete deletedNode;
        }
    }

    void printList(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << endl;
            temp = temp -> next;
        }
    }
};

int main(){
    //optimize();
    DoublyList dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    dll.push_back(4);
    dll.push_back(5);

    dll.pop_front();

    dll.printList();
    return 0;
}