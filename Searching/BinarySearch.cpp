# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
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
    // Sorted Array
    vector<int> v= {1, 2, 3, 4, 12, 15, 19, 122, 177};
    int n = v.size(); // Size of the array
    // Search Space
    // l = (minimum possible value of ans) - 1
    // r = (maximum possible value of ans) + 1
    int l = -1, r = n, mid;
    int target;
    cin >> target;
    while(r - l > 1){
        mid = l + (r - l)/2; // middle of the search space
        if(v[mid] <= target){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << ((l == - 1 or l == n) ? -1 : l) << endl; 
    return 0;
}