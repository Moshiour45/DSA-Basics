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
Bubble Sort : 
The concept for this Alogrithm is quite simple and easy. We will consider each pair and we will swap them based on what whether we want to sort in ascending and descending order. 

Lets say we have an array of size n, then we have to conduct (n - 1) swaps and on each swap our goal will be
to place each largest or smallest element of the array at the end of the array. For (n - 1) iterarion, there will be (n - i - 1) comparisions. 



*/

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < (n - 1); i++){
        for(int j = 0; j < (n - i - 1); j++){

            // Here we will the opposite of what we want
            if(v[j] >= v[j + 1]){
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(){
    //optimize();

    vector<int> v = {2,5,9,2, -1, 0, 7};
    bubbleSort(v);
    for(auto& u : v){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}