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
class SegTree{
    vector<Node> tree;
    vector<ll> v; // Data Type may change acc to the situation
    int s; // size of the tree
    int n; // size of the array
public:
    // Update if Data Type is changed
    SegTree(vector<ll> &v, int n){
        this -> v = v;
        this -> n = n;
        this -> s = 1;
        while(s < (2 * n)){
            s = s << 1;
        }
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
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

    // TC: O(log n)
    // Never Change this function
    void update(int start, int end, int index, int queryIndex, Update &u){
        if(start == end){
            u.apply(tree[index]);
            return;
        }

        int mid = (start + end)/2;
        int left = (2 * index);
        int right = (2 * index) + 1;
        if(queryIndex <= mid){
            update(start, mid, left, queryIndex, u);
        }else{
            update(mid + 1, end, right, queryIndex, u);
        }
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
            return tree[index];
        }

        int mid = (start + end)/2;
        Node left, right, ans;
        left = query(start, mid, (2 * index), l, r);
        right = query(mid + 1, end, ((2 * index) + 1), l, r);
        ans.merge(left, right);
        return ans;
    }

public : 
    // Pass as many arguments as need acc to the situation
    void makeUpdate(int index, ll val){
        Update newUpdate = Update(val); // this may change acc to thw situation
        update(0, n - 1, 1, index, newUpdate);
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
    // Actual Update
    Update(ll val){
        this -> val = val; // This may change
    }
    // Apply update to any given node
    void apply(Node& obj){
        obj.val = this -> val; // This may change
    }
};



int main(){
    optimize();
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto& u : v){
        cin >> u;
    }
    SegTree<Node, Update> st(v, n);
    cout << st.makeQuery(0,0).val << endl;
    st.makeUpdate(0, 2);
    cout << st.makeQuery(0,0).val << endl;
    return 0;
}