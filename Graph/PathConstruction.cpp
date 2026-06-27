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
    For any unweighted graph, 
        (a) DFS - will give you a path, if there exist any, which may or may not be the shortest path
        (b) BFS - will give you a path, if there exist any, which will always be the shortest path
    Path can be constructed, by tracking parents of each node
*/

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent){
    visited[node] = true;
    for(auto e : adj[node]){
        if(!visited[e]){
            parent[e] = node;
            dfs(e, adj, visited, parent);
        }
    }
}

void bfs(int root, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent){
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto e : adj[node]){
            if(!visited[e]){
                q.push(e);
                visited[e] = true;
                parent[e] = node;
            }
        }
    }
}

void constructPath(int start, int end, vector<int>& parent){
    // Never reached the end
    if(parent[end] == - 1 and start != end){
        cout << "No Path Exits" << endl;
        return;
    }

    int node = end;
    while(node != -1){
        cout << node << " ";
        node = parent[node];
    }
    cout << endl;
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

    int start, end; 
    cin >> start >> end;

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    // By starting traversal from start node, we ensure the parent[start] = -1
    dfs(start, adj, visited, parent);
    constructPath(start, end, parent);
   
    return 0;
}

