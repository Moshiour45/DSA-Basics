# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        left = right = NULL;
    }
};

class BinaryTree{
public:

    Node* buildTree(vector<int> &v, int &i){
        // Base Case
        if( i >= v.size() or v[i] == -1){
            i++; // go to the next index
            return NULL;
        }

        Node* root = new Node(v[i]); // Created a Node
        i++; // after creation move on to the new node
        root -> left = buildTree(v, i); // Left Node
        root -> right = buildTree(v, i); // Right Node

        return root;
    }

    // Pre-Order Traversal
    // root -> left -> right
    void preOrderTraversal(Node* root){
        // Base Case
        if(root == NULL){
            return;
        }
        cout << root -> val << " ";
        preOrderTraversal(root-> left);
        preOrderTraversal(root->right);
    }

    // In - Order Traversal
    // left -> root -> right
    void inOrderTraversal(Node* root){
        // Base Case
        if(root == NULL){
            return;
        }
        inOrderTraversal(root -> left);
        cout << root -> val << " ";
        inOrderTraversal(root -> right);
    }

    // Post - Order Traversal
    // left - right - root
    void postOrderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        cout << root -> val << " ";
    }

    // Level - Order Traversal
    // Traverse level by level. First it will print level - 0, then level - 1 and so on.
    void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            cout << currNode->val << " ";

            if(currNode -> left != NULL){
                q.push(currNode->left);
            }
            if(currNode -> right != NULL){
                q.push(currNode->right);
            }
        }
    }

    // To print nodes on different lines we will use NULL as an indicator
    // NULL will indicate two things
    // 1. our current level is about to come to an end --> queue will not be empty
    // 2. we are at the dead end of our tree --> queue will be empty
    void differentLineLevelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            if(currNode == NULL){
                if(!q.empty()){
                    cout << endl;
                    q.push(NULL);
                }
            }else{
                cout << currNode -> val << " ";
                if(currNode -> left != NULL){
                    q.push(currNode -> left);
                }
                if(currNode -> right != NULL){
                    q.push(currNode -> right);
                }
            }
            
        }
    }
};

int main(){
    optimize();
    vector<int> preorderSequence = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    BinaryTree bt;
    int i = 0;
    Node* root = bt.buildTree(preorderSequence, i);
    cout << "Tree Build Successful" << endl;

    bt.preOrderTraversal(root);
    cout << endl;
    cout << "Pre-order Traversal Successful" << endl;

    bt.inOrderTraversal(root);
    cout << endl;
    cout << "In-order Traversal Successful" << endl;

    bt.postOrderTraversal(root);
    cout << endl;
    cout << "Post-order Traversal Successful" << endl;

    bt.levelOrderTraversal(root);
    cout << endl;
    cout << "Level-order Traversal Successful" << endl;
    
    bt.differentLineLevelOrderTraversal(root);
    cout << endl;
    cout << "Line by Line Level-order Traversal Successful" << endl;
    return 0;
}