# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

// NHAY - A Needle in the Haystack
// https://www.spoj.com/problems/NHAY/

const int N = 1e6 + 123;

// Modular Exponentiation
ll modExp(ll a, ll b, ll MOD){
    ll res = 1 % MOD;
    a = (a % MOD);
    while(b){
        if(b & 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
ll p1 = 137, p2 = 277;
vector<pair<ll,ll>> pw(N), ipw(N);

// This function precomputes exponentaition and inverse inverse exponentiation in O(N)
void precompute(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = (pw[i - 1].first * p1) % MOD1;
        pw[i].second = (pw[i - 1].second * p2) % MOD2;
    }
    ll ip1 = modExp(p1, MOD1 - 2, MOD1);
    ll ip2 = modExp(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        ipw[i].first = (ipw[i - 1].first * ip1) % MOD1;
        ipw[i].second = (ipw[i - 1].second * ip2) % MOD2;
    }
}

class Hash{
    int n;
    string s; // 0-based
    vector<pair<ll,ll>> prefixHash; // 1 - based
public:
    Hash(){

    }

    // Computes prefix hashes
    Hash(string &s){
        this -> n = s.size();
        this -> s = s;
        prefixHash.push_back({0, 0}); 
        for(int i = 0; i < n; i++){
            pair<ll,ll> p;
            p.first = (prefixHash[i].first + (s[i] * pw[i].first)) % MOD1;
            p.second = (prefixHash[i].second + (s[i] *pw[i].second)) % MOD2;
            prefixHash.push_back(p);
        }
    }
    // computes hash of the substring 
    pair<ll,ll> getHash(ll l, ll r){
        pair<ll,ll> ans;
        ans.first = ((prefixHash[r].first - prefixHash[l - 1].first + MOD1) * ipw[l - 1].first) % MOD1;
        ans.second = ((prefixHash[r].second - prefixHash[l - 1].second + MOD2) * ipw[l - 1].second) % MOD2;
        return ans;
    }
    
    // Computes Hash of the full string 
    pair<ll,ll> getHash(){
        return getHash(1, n);
    }
    
};

int main(){
    optimize();
    precompute();
    int n;
    while(cin >> n){
        string needle, haystack;
        cin >> needle >> haystack;
        auto hs = Hash(needle).getHash();
        Hash haystackHash(haystack);
        
        for(int i = 1; i + n - 1<= haystack.size(); i++){
            if(haystackHash.getHash(i, i + n - 1) == hs){
                cout << i - 1 << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}