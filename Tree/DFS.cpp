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

// Global variables to store entering & leaving time
map<int, pair<int,int>> m;
int t = 0;

void dfs(int node, vector<vector<int>>& adj, int parent){
    
    // Entering the node
    m[node].first = t; // Marking the entering time into a node
    t++;

    cout << node << " ";
    // Traverse all the childs of the current node, until reaching leaf node
    for(auto child : adj[node]){
        // Never traverse Parent node twice
        if(child == parent){
            continue;
        }
        // GO Deeper, recursively
        dfs(child, adj, node);
    }

    // Leaving the node
    m[node].second = t; // Marking the ending time into a node
    t++;
}

int main(){
    optimize();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, 0);
    cout << endl;

    for(auto& u : m){
        cout << u.first << " -> ( " << u.second.first << " " << u.second.second << " )" << endl; 
    }

    return 0;
}