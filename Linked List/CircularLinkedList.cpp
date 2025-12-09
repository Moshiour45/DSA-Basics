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
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        next = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = head; // maintaining circularity
        }else{
            newNode -> next = head;
            head = newNode;
            tail -> next = head;        
        }
    }


    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = head;
        }else{
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode;
        }
    }


    void deleteAtHead(){
        if(head == NULL){
            return;
        }else{
            Node* deletedHead = head;
            if(head == tail){
                head = tail = NULL;
            }else{
                head = head -> next;
                tail -> next = head;
            }
            delete deletedHead;
        }
    }

    void deleteAtTail(){
        if(head == NULL){
            return;
        }else{
            Node* deletedTail = tail;
            if(head == tail){
                head = tail = NULL;
            }else{
                Node* temp = head;
                while(temp -> next != tail){
                    temp = temp -> next;
                }
                tail = temp;
                tail -> next = head;
            }
            delete deletedTail;
        }
    }

    void print(){
        if(head == NULL){
            return;
        }else{
            cout << head -> val << endl;
            Node* temp = head -> next;
            while(temp != head){
                cout << temp -> val << endl;
                temp = temp -> next;
            }
            cout << temp -> val << endl;
        }

    }
    
};

int main(){
    //optimize();
    CircularList cll;
    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    
    cll.insertAtTail(4);
    cll.insertAtTail(5);
    
    cll.deleteAtHead();
    cll.deleteAtTail();

    cll.print();
    return 0;
}