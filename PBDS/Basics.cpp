# include<bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'



int main(){
    optimize();
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& u : v){
        cin >> u;
    }


    // Solution without using PBDS

    // multiset<int> left, right;
 
    // auto balance = [&](){
    //     int m = (k + 1)/2;
    //     while(left.size() > m){
    //         right.insert(*left.rbegin());
    //         left.erase(prev(left.end()));
    //     }
    //     while(left.size() < m and !right.empty()){
    //         left.insert(*right.begin());
    //         right.erase(right.begin());
    //     }
    // };
 
 
    // auto autoInserter = [&](int x){
    //     if(!right.empty() and x >= *right.begin()){
    //         right.insert(x);
    //     }else{
    //         left.insert(x);
    //     }
    // };
 
    // for(int i = 0; i < k; i++){
    //     autoInserter(v[i]);
    //     balance();
    // }
 
    // cout << *left.rbegin() << " ";
 
    // for(int i = k; i < n; i++){
    //     auto it = left.find(v[i - k]);
    //     if(it != left.end()){
    //         left.erase(it);
    //     }else{
    //         it = right.find(v[i - k]);
    //         if(it != right.end()){
    //             right.erase(it);
    //         }
    //     }
 
    //     autoInserter(v[i]);
    //     balance();
    //     cout << *left.rbegin() << " ";
    // }
    // cout << endl;


    

    // <-------------------------------------------------------------->



    // solution using PBDS 
    pbds s;
    
    // first window
    for(int i = 0; i < k; i++){
        s.insert({v[i], i});
    }

    cout << s.find_by_order((k - 1)/2) -> first << " ";

    // sliding the window
    for(int i = k; i < n; i++){
        s.erase({v[i - k], i - k});
        s.insert({v[i], i});
        cout << s.find_by_order((k - 1)/2) -> first << " ";
    }
    cout << endl;

    return 0;
}

// Problem : Sliding Window Median (https://cses.fi/problemset/task/1076/)