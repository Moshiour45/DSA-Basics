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

        /*
            Traverse the  list until you reach inserted position - 1 and 
            if the the position where I want to insert is out of the the list then. 
            We don't need to traverse and in that case it is just push_back() operation!


            Here, we are only traversing until last element of the list because we want to
            avoid unnessesary crash of the code! 
        */
        while(i < idx - 1 and temp -> next != NULL){
            temp = temp -> next;
            i++;
        }
        if(temp -> next == NULL){
            push_back(val);
            return;
        }
        Node* insertedNode = new Node(val);
        insertedNode -> next = temp -> next;
        temp -> next = insertedNode;
    }

    int search(int val){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp -> val == val){
                return idx;
            }
            temp = temp -> next;
            idx++; 
        }
        return -1;
    }


    void reverse(){
        Node* currentNode = head;
        Node* prevNode = NULL;
        Node* nextNode = NULL;
        
        while(currentNode != NULL){
            
            nextNode = currentNode -> next; // pointing the node which is just next to the current node
            currentNode -> next = prevNode; // Node pointer reversing
            prevNode = currentNode; // Previous node shifted one step ahead
            currentNode = nextNode; // Current node shifted one step ahead
        }

        // At the end of the loop, prevNode is pointing to the last element of the tail of the original list!
        tail = head; // head tail switching
        head = prevNode; // head tail switching
    }

    /*
    
    Floyd’s cycle-finding algorithm or the tortoise–hare method :
    In this case, the fast pointer is taking 2 steps at a time and the slow pointer is taking 
    one step at a time, making the slow pointer our mid. We are traversing until fast reaches 
    NULL value!
    
    */
    Node* middleElement(){
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL and fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    /*
    
        Floyd’s cycle-finding algorithm or the tortoise–hare method :
        If a linked list has a cycle in itself, meaning tail of the list is pointed to another
        node then it is for sure that that at some point in time fast and slow pointer will 
        point to a same node. In other words, they are going to be same!
    */

    bool hasCycle(){
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL and fast -> next != NULL){

            // This can not be done because at first both fast and slow are in head position
            // Therefore, we need to do the operation first
            // if(fast == slow){
            //     return true;
            // }

            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return fast;
    }

    /*
    
    If for some reason there exits a cycle in a linked list. In simple word, tail is connected to 
    another node, it called that the linked list has a cycle in it.

    At first we will check if there is a cycle in the linked list and then after making sure that the 
    linked list has cycle and then we will set slow as head. We will traverse the list until both 
    fast and slow meets, the meeting point will be the starting of the cycle.
    
    */

    Node* detectTheCycle(){
        Node* fast = head;
        Node* slow = head;
        bool ok = false;
        while(fast != NULL and fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                slow = head;
                ok = true;
                break;
            }
        }

        if(!ok){
            return NULL;
        }
        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }


    void removeTheCycle(){
        Node* slow = detectTheCycle();
        if(slow == NULL){
            return;
        }
        Node* fast = slow;
        while(fast -> next != slow){
            fast = fast -> next;
        }
        fast -> next = NULL;
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
    
    l.insert(6,4);
    l.insert(1, 0);
    l.printList();
    l.push_back(7);

    int searchedIndex = l.search(100);
    if(searchedIndex != -1){
        cout << "Index : " << searchedIndex << endl;
    }else{
        cout << "Not Found in the list" << endl;
    }

    l.reverse();
    cout << "Reversed Linked list : " << endl;
    l.printList();
    cout << "Middle Element : " << l.middleElement() -> val << endl;


    if(l.hasCycle()){
        cout << "The linked list has no cycle in it" << endl;
    }else{
        cout << "The linked list has loop in it" << endl;
    }

    return 0;
}