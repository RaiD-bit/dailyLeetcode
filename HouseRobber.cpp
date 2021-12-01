#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int fun(int pos, int prev, vector<int> &nums, vector<vector<int>> &dp){
        // cout << prev << " " << pos << endl;
        if(dp[prev][pos] != -1)
            return dp[prev][pos];
        if(pos == nums.size()){
            return dp[prev][pos] = 0;
        }
        if(prev == false){
            return dp[prev][pos] = max(fun(pos+1,0,nums,dp), nums[pos] + fun(pos+1,1,nums,dp));
        }
        return dp[prev][pos] = fun(pos+1,0,nums,dp);
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
        return fun(0,false,nums,dp);
    }
};

int main(){
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {2,7,9,3,1};
    cout << Solution().rob(v1) << endl;
    cout << Solution().rob(v2) << endl;
}