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

void bfs(int root, vector<vector<int>> &adj){
    queue<pair<int,int>> q; // First -> nodes Second -> Parent
    q.push({root, 0}); // push level - 0 into the queue

    // mechanism for level by level traversal
    while(!q.empty()){
        // store parent and node for level - x
        int node = q.front().first;
        int parent = q.front().second;
        q.pop(); // staring popping nodes of level - x
        cout << node << " ";
        // keep on pushing nodes of level - (x + 1)
        for(auto child : adj[node]){
            if(parent == child) {
                continue;
            }
            q.push({child, node});
        }
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

    bfs(1, adj);


    return 0;
}