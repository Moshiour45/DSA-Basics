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

    // TC : O(V * E) or O(n * m)
    void bellmanFord(int src, int n, vector<vector<pair<int,ll>>>& adj, vector<ll>& dist, vector<int>& parent, vector<int>& path){
        dist[src] = 0LL;
        vector<pair<ll, pair<int, int>>> edges;;
        for(int i = 1; i <= n; i++){
            for(auto e : adj[i]){
                edges.push_back({e.second, {i, e.first}});
            }
        }

        // n - 1 iterations of relaxations of nodes
        for(int i = 0; i < n - 1; i++){
            for(auto e : edges){
                if(dist[e.second.first] != INF and dist[e.second.first] + e.first < dist[e.second.second]){
                    dist[e.second.second] = dist[e.second.first] + e.first;
                    parent[e.second.second] = e.second.first; 
                }
            }
        }

        // Cycle Started from this node
        int cycleStarterNode = -1;

        // checking negative edge cycles
        for(auto e : edges){
            if(dist[e.second.first] != INF and dist[e.second.first] + e.first < dist[e.second.second]){
                cycleStarterNode = e.second.second; // This my or may not be the starting node of the negative edge cycle
                parent[e.second.second] =  e.second.first; // updating the parent because this parent will lead us to the cycle
            }
        }

        if(cycleStarterNode != -1){
            // Pigeonhole Principle
            // Tracing backward N times to make sure we are inside the cycle
            int node = cycleStarterNode;
            for(int i = 0; i <= n; i++){
                node = parent[node];
            }

            cycleStarterNode = node; // Entry point to the cycle
            path.push_back(node);
            node = parent[node];
            while(node != cycleStarterNode){
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(cycleStarterNode);
            reverse(path.begin(), path.end());
        }
    }

    int main(){
        optimize();
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,ll>>> adj(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        vector<ll> dist(n + 1, INF);
        vector<int> parent(n + 1, 0);
        vector<int> path;
        bellmanFord(1, n, adj, dist, parent, path);
        
        if(path.size() > 0){
            for(auto u : path){
                cout << u << " ";
            }
            cout << endl;
            return 0;
        }

        for(int i = 1; i <= n; i++){
            if(dist[i] == INF){
                cout << "Node-" << i << ": INF" << endl;
                continue;
            } 
            cout << "Node-" << i << ": " << dist[i] << endl;
        }

        return 0;
    }