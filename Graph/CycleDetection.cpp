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


/*
    if there exists a neighbour of particular node which is -
        (a) not the parent of the node
        (b) visited earlier
    a cycle is found 

*/

// Standard BFS with slight modification
bool bfs(int root, vector<vector<ll>> &adj, vector<bool>& visited){
    queue<pair<ll,ll>> q;
    q.push({0, root});
    visited[root] = true;
    while(!q.empty()){
        ll node = q.front().second;
        ll parent = q.front().first;
        q.pop();
        for(auto e : adj[node]){
            if(parent == e){
                continue;
            }else if(!visited[e]){
                q.push({node, e});
                visited[e] = true;
            }else{
                return true;
            }
        }
    }
    return false;
}

// Standard DFS with slight modification
bool dfs(ll node, ll parent, vector<vector<ll>>& adj, vector<bool>& visited){
    visited[node] = true;
    for(auto e : adj[node]){
        if(parent == e){
            continue;
        }
        else if(!visited[e]){
            // if Cycle is found leave terminate recursion
            if(dfs(e, node, adj, visited)){
                return true;
            }
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u  >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    bool hasCycle = false;

    // For disconnected graphs
    for(int node = 1; node <= n; node++){
        if(!visited[node]){
            // true is cycle is found
            if(bfs(node, adj, visited)){
                hasCycle = true;
                break;
            }
        }
    }
    if(hasCycle){
        cout << "Cycle Found" << endl;
    }else{
        cout << "No Cycle Found" << endl;
    }
    return 0;
}