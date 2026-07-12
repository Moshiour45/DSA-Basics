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

void dfs(int node, vector<vector<pair<int , int>>>& adj, vector<bool> &visited, int& cnt){
    visited[node] = true;
    cnt++;
    for(auto e : adj[node]){
        if(!visited[e.first]){
            dfs(e.first, adj, visited, cnt);
        }
    }
}

int main(){
    optimize();
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }
        ll ans = (1 << 30) - 1;
        vector<vector<pair<int, int>>> temp(n + 1);
        vector<bool> visited(n + 1);
        for(int i = 29; i >= 0; i--){
            for(int j = 1; j <= n; j++){
                temp[j].clear();
                for(auto e : adj[j]){
                    if(((e.second >> i) & 1) == 0){
                        temp[j].push_back(e);
                    }
                }
            }
            ans -= (1 << i);
            fill(visited.begin(), visited.end(), false);
            int cnt = 0;
            dfs(1, temp, visited, cnt);
            if(cnt < n){
                ans += (1 << i);
            }
            if(((ans >> i) & 1) == 0){
                adj = temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// Problem : MinOr Tree(https://codeforces.com/problemset/problem/1624/G)