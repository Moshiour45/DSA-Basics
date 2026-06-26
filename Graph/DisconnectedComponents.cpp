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

// Standard BFS
void bfs(ll root, vector<vector<ll>>& adj,vector<bool>& visited, vector<ll>& component, ll cnt){
    queue<ll> q;
    q.push(root);
    visited[root] = false;
    component[root] = cnt;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto e : adj[node]){
            if(!visited[e]){
                q.push(e);
                visited[e] = true;
                component[e] = cnt;
            }
        }
    }
}

// Standard DFS
void dfs(ll node, vector<vector<ll>>& adj, vector<bool>& visited, vector<ll>& component, ll cnt){
    visited[node] = true;
    component[node] = cnt;
    for(auto e : adj[node]){
        if(!visited[e]){
            dfs(e, adj, visited, component, cnt);
        }
    }
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
    vector<ll> component(n + 1); // Marks each node of a disconected component of a graph with a number
    int cnt = 0;
    
    for(int node = 1; node <= n; node++){
        if(!visited[node]){
            bfs(node, adj, visited, component, cnt);
            // dfs(node, adj, visited, component, cnt);
            cnt++;
        }
    }
    
    for(auto u : component){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}