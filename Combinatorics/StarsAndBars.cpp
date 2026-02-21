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

ll nCr(ll n, ll r){
    ll ans = 1;
    for(int i = 1; i <= min(r, n - r); i++){
        ans = (ans * (n - i + 1))/i;
    }
    return ans;
}

int main(){
    optimize();
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << nCr(n - 1, k - 1) << endl;
    }
    return 0;
}


// Problem: Marbles (https://www.spoj.com/problems/MARBLES/)