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

// Generate all primes from l to r using segmented sieve in O((r - l) log (r) + sqrt(r))
vector<ll> segmentedSieve(ll l, ll r){
    ll limit = sqrt(r);
    auto primes = sieve(limit);
    ll size = r - l + 1;
    vector<bool> block(size + 1, true);
    for(auto p : primes){
        ll start = max(p * p, ((l + p - 1)/p) * p);
        for(ll i = start; i <= r; i += p){
            block[i - l] = false;
        }
    }
    vector<ll> primesInSegment;
    for(ll i = l; i <= r; i++){
        if(block[i - l]){
            primesInSegment.push_back(i);
        }
    }
    return primesInSegment;
}

int main(){
    optimize();
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        auto v = segmentedSieve(l, r);
        for(auto u : v){
            cout << u << endl;
        }
    }
    return 0;
}

// https://www.spoj.com/problems/PRINT/