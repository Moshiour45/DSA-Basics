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



int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<bool> visited(n + 1, false); // Marks visited nodes
    vector<pair<int, int>> edges; // stores edges of MST
    int sum = 0;
    
    // Weight, parent, child
    priority_queue<pair<int,pair<int,int>>> q; // Min heap
    q.push({0,{0,1}}); // Starting Node
    
    while(!q.empty()){
        int parent = q.top().second.first;
        int node = q.top().second.second;
        int weight = -q.top().first;
        q.pop();

        if(!visited[node]){
            visited[node] = true;
            sum += weight; // taking the min edges weight
            // Ignoring Node - 0
            if(parent != 0){
                edges.push_back({parent, node});
            }
            // Traverse Each Edge connecting node
            for(auto e : adj[node]){
                q.push({-e.second, {node, e.first}});
            }
        }
    }

    cout << sum << endl;
    for(auto [u,v] : edges){
        cout << u << " " << v << endl;
    }
    return 0;
}