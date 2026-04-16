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

// Calculation of height using DFS
void dfs(int node, vector<vector<int>>& adj, int parent, vector<int>& level, int l = 0){
    level[node] = l; // mark the level of the current node
    for(auto child : adj[node]){
        if(child == parent){
            continue;
        }
        // move one level up when going deeper into the tree
        dfs(child, adj, node, level, l + 1);
    }
}

// Calculate height using BFS
void bfs(int root, vector<vector<int>>& adj){
    queue<pair<int,int>> q;
    int level = 0; // counts how many levels are there
    q.push({root, 0});
    while(!q.empty()){
        int k = q.size(); // marks the numbers of nodes that current level is holding
        for(int i = 0; i < k; i++){
            int node = q.front().first;
            int parent = q.front().second;
            // cout << node << " ";
            q.pop();
            for(auto child : adj[node]){
                if(child == parent){
                    continue;
                }
                q.push({child, node});
            }
        }
        level++;
        // cout << endl;
    }
    cout << level << endl;
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

    vector<int> level(n + 1, 0); // This vector determines which node is at which level
    dfs(1, adj, 0, level);
    int ans = 0;
    for(auto u : level){
        ans = max(ans, u + 1); // (maximum level + 1) is the height of the tree
    }
    cout << ans << endl;

    bfs(1, adj);

    return 0;
}