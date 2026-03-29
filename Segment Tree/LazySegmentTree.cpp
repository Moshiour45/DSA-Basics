// Credits to Priyansh Agarwal for the inspiration
// This holds as a template for segment tree with slight changes depending on the situation

# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

template<class Node, class Update>
class LazySGT{
    vector<Node> tree; // Actual Segment Tree
    vector<bool> lazy; // Tracks pending updates in the lazy segment tree
    vector<Update> updates; // Updates are stored here
    vector<ll> v; // Data Type may change acc to the situation
    int s; // size of the tree
    int n; // size of the array
public:
    // Update if Data Type is changed
    LazySGT(vector<ll> &v, int n){
        this -> v = v;
        this -> n = n;
        this -> s = 1;
        while(s < (2 * n)){
            s = s << 1;
        }
        tree.resize(s);
        lazy.resize(s);
        updates.resize(s);
        fill(tree.begin(), tree.end(), Node());
        fill(lazy.begin(), lazy.end(), false);
        fill(updates.begin(), updates.end(), Update());
        build(0, n - 1, 1);
    }

private : 
    // TC: O(n)
    // Never change this function
    void build(int start, int end, int index){
        if(start == end){
            tree[index] = Node(v[start]);
            return;
        }
        int mid = (start + end)/2;
        int left = 2 * index;
        int right = (2 * index) + 1;
        build(start, mid, left);
        build(mid + 1, end, right);
        tree[index].merge(tree[left], tree[right]);
    }

    // Two types of function call will come to this node -
    //      1. lazy[index] = true  --> propageLazy() will call it for child nodes for propagation
    //      2. lazy[index] = false --> update() will call it for any new updates
    //
    // Both prior updates and new updates(passed in the query) will be passed in as argument  
    void applyUpdateToNode(int index, int start, int end, Update& u){
        // The node is not a leaf node
        if(start != end){
            lazy[index] = true; //  mark pending updates
            updates[index].mergeUpdate(u, start, end);
        }
        // populate update in the tree array
        u.applyUpdateToTreeNode(tree[index], start, end);
    }

    // This is used to propagate updates from parent node to it's child nodes
    void propagateLazy(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end)/2;
            applyUpdateToNode((2 * index), start, mid, updates[index]);
            applyUpdateToNode(((2 * index) + 1), mid + 1, end, updates[index]);
            lazy[index] = false;
            updates[index] = Update();
        }
    }

    // TC: O(log n)
    // Never Change this function
    void update(int start, int end, int index, int l, int r, Update &u){
        // Disjoint
        if(end < l or start > r){
            return;
        }

        // Complete Overlap
        if(start >= l and end <= r){
            applyUpdateToNode(index, start, end, u);
            return;
        }
        propagateLazy(index, start, end);
        // Partial Overlap
        int mid = (start + end)/2;
        int left = (2 * index);
        int right = (2 * index) + 1;
        update(start, mid, left, l, r, u);
        update(mid + 1, end, right, l, r, u);
        tree[index].merge(tree[left], tree[right]);
    }

    // TC : O(log n)
    // Never Change this function
    Node query(int start, int end, int index, int l, int r){
        // disjoint
        if(r < start or l > end){
            return Node();
        }
        // complete overlap
        if(start >= l and end <= r){
            propagateLazy(index, start, end); // making the tree node is in it's most updated state
            return tree[index];
        }

        propagateLazy(index, start, end); // making the tree node is in it's most updated state
        int mid = (start + end)/2;
        Node left, right, ans;
        left = query(start, mid, (2 * index), l, r);
        right = query(mid + 1, end, ((2 * index) + 1), l, r);
        ans.merge(left, right);
        return ans;
    }

public : 
    // Pass as many arguments as need acc to the situation
    void makeUpdate(int l, int r, ll val){
        Update newUpdate = Update(val); // this may change acc to thw situation
        update(0, n - 1, 1, l, r, newUpdate);
    }
    Node makeQuery(int l, int r){
        return query(0, n - 1, 1, l, r);
    }

};

class Node{
public: 
    ll val; // This may change acc to the situation
    // Identiy Node
    Node(){
        this -> val = 0; // This may change acc to the situation
    }
    // Actual Node Info
    Node(ll val){
        this -> val = val; // This may change acc to thw situation
    }
    // Merge Two child
    void merge(Node& left, Node& right){
        this -> val = left.val + right.val; // This may change
    }
};
class Update{
public: 
    ll val; // This may change

    // Indentiy Node
    Update(){
        this -> val = 0; // this may change
    }

    // Actual Update
    Update(ll val){
        this -> val = val; // This may change
    }

    // Making update in the actual tree 
    void applyUpdateToTreeNode(Node& treeNode, int start, int end){
        treeNode.val = this -> val * (end - start + 1); // This may change
    }

    // Merging Update Tree Node and Tree node
    void mergeUpdate(Update& newUpadate, int start, int end){
        this -> val = newUpadate.val; // This may change
    }
};

int main(){
    optimize();
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto& u : v){
        cin >> u;
    }
    LazySGT<Node,Update> lgt(v, n);
    cout << lgt.makeQuery(0, 1).val << endl;
    lgt.makeUpdate(0, 1, 5);
    cout << lgt.makeQuery(0,1).val << endl;
    return 0;
}