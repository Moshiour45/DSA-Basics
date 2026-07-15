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

void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
    visited[node] = true;
    for(auto e : adj[node]){
        if(!visited[e]){
            dfs1(e, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& temp){
    visited[node] = true;
    temp.push_back(node);
    for(auto e : adj[node]){
        if(!visited[e]){
            dfs2(e, adj, visited, temp);
        }
    }
}

int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    // adj -> Normal adjacency list
    // transAdj -> Adjacency list with edges reversed
    vector<vector<int>> adj(n + 1), transAdj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        transAdj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    stack<int>st; // Stores DFS order of the graph
    vector<vector<int>> scc; // Stores all SCCs
    vector<int> temp;
    
    // DFS to get DFS order
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs1(i, adj, visited,st);
        }
    }


    fill(visited.begin(), visited.end(), false);
    
    // Run DFS as per DFS order in the transpose adjacency list
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            dfs2(node, transAdj, visited, temp);
            scc.push_back(temp);
            temp.clear();
        }
    }

    for(auto v : scc){
        for(auto u : v){
            cout << u << " ";
        }
        cout << endl;
    }
    
    return 0;
}