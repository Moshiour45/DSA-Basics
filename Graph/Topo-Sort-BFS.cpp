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

// TC : O(N)
void bfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& in, vector<int>& topoSort){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto e : adj[node]){
            in[e]--;
            if(in[e] == 0){
                q.push(e);
                visited[e] = true;
            }
        }
    }
}

int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> topoSort;

    for(int i = 1; i <= n; i++){
        if(in[i] == 0 & !visited[i]){
            bfs(i, adj, visited, in, topoSort);
        }
    }

    for(auto u : topoSort){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}