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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>> &dp){
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        dfs(child, node, adj, dp);
        // if not picked for matching
        dp[node][0] += max(dp[child][0], dp[child][1]);
        // As I can't guarantee all values of dp[child][0] will be available therefore it can't be done
        // // if picked for matching
        // dp[node][1] = max(dp[node][1], 1 + dp[node][0] - dp[child][0]);
    }
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        // if picked for matching
        dp[node][1] = max(dp[node][1], 1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1]));
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

    /*

    state:
    dp[node][flag] = The maximum number of matching if node is picked or not
    
    transition:

    when,
    flag = 0:
    dp[node][0] += max(dp[child][0], dp[child][1]): for all child

    when, 
    flag = 1:
    dp[node][1] = max(default value, 1 guaranteed matching after picked the node + matched nodes contribution + rest of the nodes contribution)
    dp[node][1] = max(d[node][1] , 1 + dp[child][0] + dp[node][0] - dp[child][0])

    base case:
    for leaf node there are no nodes below.
    dp[leaf][0] = 0
    dp[leaf][1] = 0

    */

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dfs(1, 0, adj, dp);
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}

// Problem : Tree Matching (https://cses.fi/problemset/task/1130/)