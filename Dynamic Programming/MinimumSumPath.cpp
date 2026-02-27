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


// Same DP problem can be solved using different states and transition equations

class Solution1 {
public:
    static const int INF = 1e6;
    int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i >= n or j >= m){
            return INF;
        }
        if(i == n - 1 and j == m - 1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j] + min(f(i, j + 1, n, m, grid, dp), f(i + 1, j, n, m, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 123, vector<int>(m + 123, -1));
        return f(0,0,n,m, grid, dp);
    }
};

class Solution2 {
public:
    static const int INF = 1e6;
    int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i < 0 or j < 0){
            return INF;
        }
        if(i == 0 and j == 0){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j] + min(f(i, j - 1, n, m, grid, dp), f(i - 1, j, n, m, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 123, vector<int>(m + 123, -1));
        return f(n-1,m-1,n,m, grid, dp);
    }
};

int main(){
    optimize();
    
    return 0;
}


// Leetcode: Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/description/)