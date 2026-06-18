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
State : 
dp[x] = Number of child node beneath the node x

Transition:
dp[x] = {sum of dp[child] for all child nodes}

*/



const int N = 2e5;
int dp[N];
 
void dfs(int node, int parent, vector<vector<int>>& adj){
    dp[node] = 1;
    for(auto child : adj[node]){
        if(child == parent){
            continue;
        }
        dfs(child, node, adj);
        dp[node] += dp[child];
    }
    
}


int main(){
    optimize();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int u = 2;
    for(int i = 0; i < n - 1; i++){
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        u++; 
    }
 
    memset(dp, -1, sizeof(dp));
    dfs(1, 0, adj);
    for(int i = 1; i <= n; i++){
        cout << dp[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}

// Problem : Subordinates (CSES) (https://cses.fi/problemset/task/1674/)