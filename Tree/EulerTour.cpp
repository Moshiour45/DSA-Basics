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

vector<int> flat;
map<int, int> m;
int idx = 0;
void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& level, int l = 0){
    if(m.find(node) == m.end()){
        m[node] = idx;
    }
    level[node] = l;
    flat.push_back(node);
    idx++;
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        dfs(child, node, adj, level, l + 1);
        flat.push_back(node);
        idx++;
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
    vector<int> level(n + 1);

    dfs(1, 0, adj, level);
    // This is to verify Addition on AlgoVerse
    return 0;
}