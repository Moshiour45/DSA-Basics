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

const ll N = 1e5;
const ll MOD = 1e9 + 7;
vector<ll> fact(N + 1);
vector<ll> modInv(N + 1);

// O(log b)
ll binPow(ll a, ll b){
    if(b < 0){
        return 0;
    }
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    
    return ans;
}

// O(nlog(MOD))
void precompute(){
    fact[0] = 1;
    modInv[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        modInv[i] = binPow(fact[i], MOD - 2);
    }
}

// O(1)
ll nCr(ll n, ll r){
    if(n < 0 or r < 0 or r > n){
        return 0;
    }
    ll numerator = fact[n];
    ll invDenominator = (modInv[n - r] * modInv[r]) % MOD;
    return (numerator * invDenominator) % MOD;
}

int main(){
    optimize();
    precompute();
    int q;
    cin >> q;
    while(q--){
        ll n, r;
        cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
    return 0;
}