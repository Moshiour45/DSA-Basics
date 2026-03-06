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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m), last(m);
        
        for(int j = m - 1; j >= 0; j--){
            dp[j] = grid[n - 1][j] + (j < m - 1 ? dp[j + 1] : 0);
            last[j] = dp[j];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                dp[j] = grid[i][j];
                if(j == m - 1){
                    dp[j] += last[j];
                }else{
                    dp[j] += min(dp[j + 1], last[j]);
                }
                last = dp;
            }
        }
        return dp[0];
    }
};

int main(){
    optimize();
    
    return 0;
}

// Leetcode: Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/description/)