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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& dp, vector<int>& level, int l = 0){
    // base case
    dp[node][0] = parent;
    level[node] = l;

    // Store all the parents of the current node in dp
    for(int i = 1; i < 17; i++){
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        dfs(child, node, adj, dp, level, l + 1);
    }
}


int getKthParent(int node, int k, vector<vector<int>>& dp){
    for(int i = 16; i >= 0; i--){
        if((k >> i) & 1){
            node = dp[node][i];
        }
    }
    return node;
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
    vector<int> level(n + 1, 0);
    dfs(1, 0, adj, dp, level);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        // Assuming b is at deeper level than a
        if(level[a] > level[b]){
            swap(a, b);
        }
        // difference in levels
        int k = level[b] - level[a];
        b = getKthParent(b, k, dp); // now both of the nodes are at same level
        // After they are bought back to the same level, if they represent the same node
        // then the node which was not the deepest node will be our answer
        if(a == b){
            cout << a << endl;
            continue;
        }
        for(int i = 16; i >= 0; i--){
            // moving nodes upward at unequal levels
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        // dp[a][0] or dp[b][0] holds our LCA
        cout << dp[a][0] << endl; 
    }
    return 0;
}