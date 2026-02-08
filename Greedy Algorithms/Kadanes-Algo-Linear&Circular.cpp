# include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

class Solution {
public:
    // Kadane's Algorithm is used for maximum subarray sum and min subarray sum
    int maxSubarraySumCircular(vector<int>& v) {
        int n = v.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int sum1 = 0, sum2 = 0, totalSum = 0;
        for(auto &u : v){
            totalSum += u;
            sum1 += u;
            sum2+= u;
            maxSum = max(maxSum, sum1);
            minSum = min(minSum, sum2);
            if(sum1 < 0){
                sum1 = 0;
            } 
            if(sum2 > 0){
                sum2 = 0;
            }
        }
        return ((maxSum < 0 ? maxSum : max(maxSum, (totalSum - minSum))));
    }
};

// Leetcode Problem : Maximum Sum Circular Subarray - (https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

int main(){
    optimize();
    
    return 0;
}
