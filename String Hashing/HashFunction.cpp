# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'



ll getHash(string &str){
    // Take p the closest prime number to the possible size of the string 
    const ll p = 31;
    const ll m = 1e9 + 7;
    ll base = 1;
    ll hashVal = 0;
    for(auto u : str){
        hashVal = (hashVal + ((u - 'a' + 1) * base)) % m;
        base = (base * p) % m;
    }
    return hashVal;
}

// Double Hashing
pair<ll,ll> safeGetHash(string &str){
    const ll p1 = 137;
    const ll p2 = 277;
    const ll MOD1 = 1e9 + 7;
    const ll MOD2 = 1e9 + 9;
    pair<ll,ll> base = {1, 1};
    pair<ll,ll> hashVal = {0, 0};
    for(auto u : str){
        hashVal.first = (hashVal.first + ((u - 'a' + 1) * base.first)) & MOD1;
        hashVal.second = (hashVal.second + ((u - 'a' + 1) * base.second)) & MOD2;
        base.first = base.first * p1;
        base.second = base.second * p2;
    }
    return hashVal;
}

int main(){
    optimize();
    string str1 = "bad";
    string str2 = "dab";
    pair<ll,ll> hash1 = safeGetHash(str1);
    pair<ll,ll> hash2 = safeGetHash(str2);
    cout << ((hash1 == hash2) ? "Strings are equal" : "Strings are not equal") << endl; // O(1)
    return 0;
}