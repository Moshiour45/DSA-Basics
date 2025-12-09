# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'
# define yes cout<<"YES"<<endl
# define no cout<<"NO"<<endl


/*

Selection Sort : 
The  concept here is very simple- we split the array into two parts : Sorted and Unsorted. Place the smallest element of the unsorted array in the correct position. Some dry runs are given -

Array : 2 9 1 7 3

Let us assume the whole array to be unsorted, therefore the smallest element of the array will be the first 
element of the sorted array.

1 2 9 7 3
1 2 9 7 3
1 2 3 7 9
1 2 3 7 9
1 2 3 7 9

*/

void selectionSort(vector<int> &v){
    int n = v.size();
    // Traversing through unsorted array
    for(int i = 0; i < (n - 1); i++){
        // Smallest Element Index
        int smallestIdx = i;
        // Finding the smallest element to place it at the correct place
        for(int j = i + 1; j < n; j++){
            if(v[j] <= v[smallestIdx]){
                smallestIdx = j;
            }
        }
        // placing it correctly
        swap(v[i], v[smallestIdx]);
    }
}

int main(){
    //optimize();
    vector<int> v = {2,5,9,2, -1, 0, 7};
    selectionSort(v);
    for(auto& u : v){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}