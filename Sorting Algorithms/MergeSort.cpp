# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'
# define yes cout<<"YES"<<endl
# define no cout<<"NO"<<endl


void merge(vector<int> &v, int l, int r, int mid){
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i <= mid and j <= r){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            temp.push_back(v[j]);
            j++;
        }
    }
    
    while(i <= mid){
        temp.push_back(v[i]);
        i++;
    }

    while(j < r){
        temp.push_back(v[j]);
    }

    for(int i = 0; i < temp.size(); i++){
        v[l + i] = temp[i];
    }
}


void mergeSort(vector<int> &v, int l, int r){
    if(l == r){
        return;
    }
    int mid = l + (r - l)/2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);

    merge(v,l,r,mid);
}

int main(){
    //optimize();
    vector<int> v = {2,5,9,2, -1, 0, 7};
    int l = 0, r = v.size() - 1;
    mergeSort(v, l, r);
    for(auto& u : v){
        cout << u << " ";
    }
    cout << endl;   
    return 0;
}