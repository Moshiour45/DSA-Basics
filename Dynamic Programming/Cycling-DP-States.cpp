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



int main(){
    optimize();
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    vector<int> v(n);
    for(auto& u : v){
        cin >> u;
        if(u == 1){
            c1++;
        }else if(u == 2){
            c2++;
        }else if(u == 3){
            c3++;
        }
    }
    vector<vector<vector<lld>>> dp(n + 1, vector<vector<lld>>(n + 1, vector<lld>(n + 1, 0)));
    // 3s --> are increasing 2s count
    // 2s --> are increasing 1s count
    // 1s --> are increaing 0s count

    // Therefore it is important to handle 3s first then 2s and then 1s
    for(int threes = 0; threes <= n; threes++){
        for(int twos = 0; twos <= n; twos++){
            for(int ones = 0; ones <= n; ones++){
                if(ones + twos + threes == 0 or ones + twos + threes > n){
                    continue;
                }
                lld ans = (lld)n;
                if(threes > 0){
                    ans += ((lld)threes * dp[threes - 1][twos + 1][ones]);
                }
                if(twos > 0){
                    ans += ((lld)twos * dp[threes][twos - 1][ones + 1]);
                }
                if(ones > 0){
                    ans += ((lld)ones * dp[threes][twos][ones - 1]);
                }
                dp[threes][twos][ones] = ans / (ones + twos + threes);
            }
        }
    }
    cout << fixed << setprecision(20) << dp[c3][c2][c1] << endl;
    return 0;
}

// AtCoder - J-Sushi (https://atcoder.jp/contests/dp/tasks/dp_j)