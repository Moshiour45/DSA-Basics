# include<bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

// we will be constructing answer for Min Path Sum problem

int method1(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto &u : grid){
        for(auto &v : u){
            cin >> v;
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            dp[i][j] = grid[i][j];
            if(i == n - 1 and j == m - 1){
                continue;
            }
            if(i == n - 1){
                dp[i][j] += dp[i][j + 1];
                continue;
            }
            if(j == m - 1){
                dp[i][j] += dp[i + 1][j];
                continue;
            }
            dp[i][j] += min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
    
    int i = 0, j = 0;
    while(true){
        cout << i << " " << j << endl;
        if(i == n - 1 and j == m - 1){
            break;
        }
        else if(i == n - 1){
            j++;
        }
        else if(j == m - 1){
            i++;
        }
        else if(dp[i][j + 1] < dp[i + 1][j]){
            j++;
        }else{
            i++;
        }
    }
}

int method2(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto &u : grid){
        for(auto &v : u){
            cin >> v;
        }
    }


    // 0 -> right side
    // 1 -> down side
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m, {-1, 0}));
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            dp[i][j] = {grid[i][j], -1};
            if(i == n - 1 and j == m - 1){
                continue;
            }
            if(i == n - 1){
                dp[i][j].first += dp[i][j + 1].first;
                dp[i][j].second = 0;
                continue;
            }
            if(j == m - 1){
                dp[i][j].first += dp[i + 1][j].first;
                dp[i][j].second = 1;
                continue;
            }
            if(dp[i + 1][j].first < dp[i][j + 1].first){
                dp[i][j].first += dp[i + 1][j].first;
                dp[i][j]. second = 1;
            }else{
                dp[i][j].first += dp[i][j + 1].first;
                dp[i][j]. second = 0;
            }
        }
    }
    cout << dp[0][0].first << endl;
    
    pair<int,int> tracker = {0, 0};
    while(true){
        cout << tracker.first << " " << tracker.second << endl;
        if(tracker == make_pair(n - 1, m - 1)){
            break;
        }
        if(dp[tracker.first][tracker.second].second == 0){
            tracker.second ++;
        }else{
            tracker.first ++;
        }
    }
}

int main(){
    optimize();
    
    return 0;
}