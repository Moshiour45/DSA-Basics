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


// Calculates Maximum distance for any node in In-Ward(Downside) Direction
void dfs1(ll node, ll parent, vector<vector<ll>>& adj, vector<ll>& in){
    for(auto child : adj[node]){
        if(child == parent){
            continue;
        }
        dfs1(child, node, adj, in);
        // Ans[node] = 1 + Ans[child]
        in[node] = max(in[node], 1 + in[child]);
    }
}

// Calculates Maximum distance from any node in Up-Ward (Upside) by choosing poth between upward maximum path and 
// second maximum path from that node in downward direction
void dfs2(ll node, ll parent, vector<vector<ll>>& adj, vector<ll>& out, vector<ll>& in){
    ll mx1 = -1; // Maximum path from from any node in the downward direction
    ll mx2 = -1; // Second maximum path from any node in downward direction
    ll childOnMaxPath = -1; // Marks immediate child which lies on the maximum path in downward direction
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        if(1 + in[child] > mx1){
            mx2 = mx1;
            mx1 = 1 + in[child];
            childOnMaxPath = child;
        }else if(1 + in[child] > mx2){
            mx2 = 1 + in[child];
        }
    }
    for(auto child : adj[node]){
        if(parent == child){
            continue;
        }
        
        ll longest = mx1;
        // If the child is on the maximum path, take the second longest path
        if(childOnMaxPath == child){
            longest = mx2;
        }
        // decision making step
        out[child] = 1 + max(longest, out[node]);
        dfs2(child, node, adj, out, in);
    }
}

int main(){
    optimize();
    int n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> out(n + 1,0); // Maximum Path in the outward direction
    vector<ll> in(n + 1, 0); // Maximum Path in the inward direction
    dfs1(1, 0, adj, in);
    dfs2(1, 0, adj, out, in);
    for(int i = 1; i <= n; i++){
        cout << max(in[i], out[i]) << " ";
    }
    cout << endl;
    return 0;
}

// Problem : Tree Distances I (https://cses.fi/problemset/task/1132/)