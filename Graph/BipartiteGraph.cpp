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

// A Bipartite graph : A graph where each node conntected by an edge is from two different sets
bool dfs(int node, vector<vector<int>>& adj, vector<int>& colors){
    for(auto e : adj[node]){
        if(colors[e] == 0){
            colors[e] = (colors[node] == 1) ? 2 : 1;
            if(dfs(e, adj, colors)){
                return true;
            }
        }else if(colors[node] == colors[e]){
            return false;
        }
    }
    return true;
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

    vector<int> colors(n + 1, 0); // two different colors are used Black - 1 and White - 2 and No Color - 0
    bool isBipartite = false;
    // Graph may be disconnected therefore DFS is done for each unvisited node is executed
    for(int node = 1; node <= n; node++){
        if(colors[node] == 0){
            colors[node] = 1;
            if(dfs(node, adj, colors)){
                isBipartite = true;
                break;
            };
        }
    }

    if(isBipartite){
        cout << "The Graph is Bipartite" << endl;
        cout << "The Graph has Odd Length Cycle" << endl;
    }else{
        cout << "The Graph is not Bipartite" << endl;
    }

    return 0;
}