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

Insertion sort : 
The core concept behind this code is that we assume the first element of the array to be sorted and the rest
of the elements to be unsorted. Therefore, we start from the second element of the array and we find the 
right place for that element in the sorted section. Until we find the correct position we keep on shifting
things and when we find the correct place we place the element in the correct place.


*/

void insertionSort(vector<int> &v){
    int n = v.size();
    // Traversing through the unsorted array
    for(int i = 1; i < n; i++){
        // storing the current element
        int curr = v[i];
        // the previous element of the current element
        int prevIdx = i - 1;

        // keep on shifting until found a correct place
        while(prevIdx >= 0 and v[prevIdx] > curr){
            v[prevIdx + 1] = v[prevIdx];
            prevIdx--;
        }
        // placing the number in a correct place
        v[prevIdx + 1] = curr;
    }
}


int main(){
    //optimize();
    vector<int> v = {2,5,9,2, -1, 0, 7};
    insertionSort(v);
    for(auto& u : v){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}