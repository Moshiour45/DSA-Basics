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

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component, int cnt){
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
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<int> componet(n + 1);
    int cnt = 0; // Number of disconnected nodes
    vector<int> ans; // stores a node from each disconnected coponent

    for(int node = 1; node <= n; node++){
        if(!visited[node]){
            ans.push_back(node);
            dfs(node, adj, visited, componet, cnt);
            cnt++;
        }
    }
    
   cout << cnt - 1 << endl; // To connect N diconnected nodes, we need N - 1 edges
   int i = 1;
   while(i < cnt){
    cout << ans[i - 1] << " " << ans[i] << endl;
    i++;
   }
    return 0;
}

// Problem : Building Roads (https://cses.fi/problemset/task/1666/)