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

const ll INF = 1e18;

// // Single Source Shortest Path Algorithm - Dijkstra
// // TC : O((N + M)logN)
// void dijkstra(int src, int n, vector<vector<pair<int,ll>>>& adj, vector<ll>& dist){
//     vector<bool> marked(n + 1, false);
//     set<pair<ll,int>> s;
//     s.insert({0LL, src});
//     marked[src] = true;
//     dist[src] = 0;
//     while(!s.empty()){
//         pair<ll,int> top = *s.begin();
//         int topNode = top.second;
//         ll topDist = top.first;
//         marked[topNode] = true;
//         s.erase(top);
//         for(auto e : adj[topNode]){
//             int node = e.first;
//             ll d = e.second;
//             if(marked[node]){
//                 continue;
//             }
//             if(dist[node] > (dist[topNode] + d)){
//                 s.erase({d, node});
//                 dist[node] = dist[topNode] + d;
//                 s.insert({dist[node], node});
//             }
//         }
//     }
// }


// Using Priority Queue
// TC: O((N + M)logN)
//
// In order to track the shortest path we use parent array which tracks the parent of each node containing 
// shortest path 
void dijkstra(int src, int n, vector<vector<pair<int, ll>>>& adj, vector<ll>& dist, vector<int> &parent){
    // We are using max heap with negation trick
    priority_queue<pair<ll, int>>q;
    // Below is the actual syntax of min heap
    // priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll, int>>>q;
    q.push({-0LL, -src});
    parent[src] = -1;
    dist[src] = 0;
    while(!q.empty()){
        pair<ll, int> top = q.top();
        int topNode = -top.second;
        int topDist = -top.first;
        q.pop();
        // This tracks the previous state of any node after
        // after node distance for any node was updated second time
        if(dist[topNode] != topDist){
            continue;
        }
        for(auto e : adj[topNode]){
            int node = e.first;
            ll d = e.second;
            if(dist[node] > (dist[topNode] + d)){
                dist[node] = dist[topNode] + d;
                q.push({-dist[node], -node});
                parent[node] = topNode;
            }
        }
    }
}

// Tracks back the shortest path by backtracking
void getPath(int node, vector<int>& parent){
    while(node != -1){
        cout << node << " ";
        node = parent[node];
    }
    cout << endl;
}

int main(){
    optimize();
    // n -> number of nodes
    // m -> number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // considering the graph to be undirected
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }   

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1);
    dijkstra(1, n, adj, dist, parent);
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF){
            cout << -1 << " ";
            continue;
        }
        cout << dist[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << " Node-" << i << " : ";
        getPath(i, parent);
    }

    return 0;
}