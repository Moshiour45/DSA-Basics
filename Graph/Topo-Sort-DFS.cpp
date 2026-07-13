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

// TC : O(N)
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
    visited[node] = true;
    for(auto e : adj[node]){
        if(!visited[e]){
            dfs(e, adj, visited, st);
        }
    }
    st.push(node); // After traversing every child edges push it to the stack
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
    }
    
    vector<bool> visited(n + 1, false);
    stack<int> st;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}