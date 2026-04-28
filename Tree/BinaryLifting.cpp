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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& dp){
    // base case
    dp[node][0] = parent;

    // Store all the parents of the current node in dp
    for(int i = 1; i < 17; i++){
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        dfs(child, node, adj, dp);
    }
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
    // dp[node][x] = 2^x th parent of node
    // 17 is used as a size because log(1e5) is almost equal to 17. Here 1e5 is query range
    vector<vector<int>> dp(n + 1, (vector<int>(17, 0)));
    dfs(1, 0, adj, dp);
    int q;
    cin >> q;
    while(q--){
        int node, k;
        cin >> node >> k;
        int bits = 0; // tracks bit position
        while(k){
            // tracking set bits
            if(k & 1){
                node = dp[node][bits]; // jumping from one node to another by power of twos
            }
            bits++;
            k >>= 1; // shifting each bit by 1
        }
        cout << node << endl;
    }
    return 0;
}