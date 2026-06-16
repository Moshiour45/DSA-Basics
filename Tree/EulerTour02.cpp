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

vector<ll> flat; // flat array
int idx = 0;
vector<pair<ll, ll>> range; // storing ranges of subtree

// Euler Tour Type 02
void dfs(int node, int parent, vector<vector<ll>> &adj){
    // entering the node
    flat.push_back(node);
    range[node].first = idx;
    idx++;
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        dfs(child, node, adj);
    }
    // leaving the node
    flat.push_back(node);
    range[node].second = idx;
    idx++;
}


// Range Query Data Structure (Segment Tree)

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





// Time Complexity : O(n) + O(q log n)
void subtreeQueries(){
    int n, q;
    cin >> n >> q;

    // values stored in each node
    vector<ll> nodeVal(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nodeVal[i];
    }

    vector<vector<ll>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    range.resize(n + 1);
    dfs(1, 0, adj);
    
    // flat array storing values of each node
    vector<bool> visited(n + 1, false); // Tracks the first occurrence of a node in the flat array
    vector<ll> flatValue;

    for(auto u : flat){
        if(!visited[u]){
            flatValue.push_back(nodeVal[u]);
            visited[u] = true;
        }else{
            flatValue.push_back(0); 
        }
    }


    // Building Segment Tree
    SegTree<Node, Update> sgt(flatValue, flatValue.size());
    
    while(q--){
        int p, s, x;
        cin >> p;
        if(p == 1){
            cin >> s >> x;
            // point update
            sgt.makeUpdate(range[s].first, x);
            

        }else{
            cin >> s;
            cout << (sgt.makeQuery(range[s].first, range[s].second). val) << endl;
        }
     }
    
    
}



// Time Complexity : O(n) + O(q log n)
void pathQueries(){
    int n, q;
    cin >> n >> q;

    // values stored in each node
    vector<ll> nodeVal(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nodeVal[i];
    }

    vector<vector<ll>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    range.resize(n + 1);
    dfs(1, 0, adj);
    
    // flat array storing values of each node
    vector<bool> visited(n + 1, false); // Tracks the first occurrence of a node in the flat array
    vector<ll> flatValue;

    for(auto u : flat){
        if(!visited[u]){
            flatValue.push_back(nodeVal[u]);
            visited[u] = true;
        }else{
            flatValue.push_back(-nodeVal[u]); 
        }
    }


    // Building Segment Tree
    SegTree<Node, Update> sgt(flatValue, flatValue.size());
    
    while(q--){
        int p, s, x;
        cin >> p;
        if(p == 1){
            cin >> s >> x;
            // point update
            sgt.makeUpdate(range[s].first, x); // place +x at the first encounter
            sgt.makeUpdate(range[s].second, -x); // place -x at the second encounter
            

        }else{
            cin >> s;
            // path from root node to node - x
            cout << (sgt.makeQuery(0LL, range[s].first). val) << endl;
        }
     }
    
    
}


int main(){
    optimize();
    
    // subtreeQueries();
    pathQueries();

    return 0;
}


// Problem : Subtree Queries (https://cses.fi/problemset/task/1137/)
// Problem : Path Queries (https://cses.fi/problemset/task/1138/)
