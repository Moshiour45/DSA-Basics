# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

const lld eps = 1e-6;

// Dummy Function - 1
lld f(lld x){
    return -(((x - 3) * (x - 3)) + 5);
}
// Dummy Function - 2
ll f(ll x){
    return -(((x - 3) * (x - 3)) + 5);
}

lld TernarySearch(lld l, lld r){
    lld m1, m2;
     while(r - l > eps){
        m1 = l + (r - l)/3;
        m2 = r - (r - l)/3;
        if(f(m1) < f(m2)){
            l = m1;
        }else{
            r = m2;
        }
    }
    return l;
}

ll TernarySearch(ll l, ll r){
    ll m1, m2;
    while(r - l > 2){
        m1 = l + (r - l)/3;
        m2 = r - (r - l)/3;
        if(f(m1) < f(m2)){
            l = m1;
        }else{
            r = m2;
        }
    }

    ll best = l;
    for(ll i = 0; i < r; i++){
        if(f(i) > f(best)){
            best = i;
        }
    }
    return best;
}

int main(){
    optimize();
    
    return 0;
}