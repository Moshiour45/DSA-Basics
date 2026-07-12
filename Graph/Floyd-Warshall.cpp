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

const ll INF = INT_MAX;

/*

State : 
    cost[i][j] = Min cost to reach node j from node i
Transition :
    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
    here,
        1 <= k <= n
        which ensure we are selecting each and every possible middle-man node from
        the graph    


*/




int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> cost(n + 1, vector<ll>(n + 1));
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cost[i][j] = 0;
            }else{
                cost[i][j] = INF;
            }
        }
    }
    // Filling the DP with initail distances
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        cost[u][v] = min(cost[u][v], w);
    }
    // TC: O(N * N * N)
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(cost[i][k] == INF or cost[k][j] == INF){
                    continue;
                }
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == INF) cout << "INF ";
            else cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}