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

// Generate all primes up to limit using sieve of eratosthenes
vector<ll> sieve(ll limit){
    vector<bool> isPrime(limit + 123, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= limit; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= limit; j += i){
                isPrime[j] = false;
            }
        }   
    }
    vector<ll> primes;
    for(int i = 2; i <= limit; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

// Generate all primes from 1 to n using segmented sieve in even for higher numbers
ll segmentedSieve(ll n){
    ll limit = sqrt(n);
    auto primes = sieve(limit);
    ll ans = 0;
    const ll s = 1e4;
    for(ll k = 0; k * s <= n; k++){
        ll start = k * s;
        vector<bool> block(s, true);
        for(auto p : primes){
            ll idx = max(((start + p - 1)/ p) * p, p * p) - start;
            for(int i = idx; i < s; i += p){
                block[i] = false;
            }
        }
        if(k == 0){
            block[0] = block[1] = false;
        }
        for(int i = 0; i < s and start + i <= n; i++){
            if(block[i]){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    optimize();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << segmentedSieve(n) << endl;
    }
    return 0;
}

