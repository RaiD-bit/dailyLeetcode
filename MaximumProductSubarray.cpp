#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // is a dp question just think like kadanes
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        int maximum_ending_here = 0;
        int minimum_ending_here = 0;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        for(int i = 0; i<n; i++){
            int z = maximum_ending_here;
            maximum_ending_here = max(nums[i], max(maximum_ending_here*nums[i], minimum_ending_here*nums[i]));
            minimum_ending_here = min(nums[i], min(z*nums[i], minimum_ending_here*nums[i]));
            ans = max(ans, maximum_ending_here);
        }

        return ans;
    }
};


int main(){
    vector<int> v = {2,3,-2,4};
    // vector<int> v1 = {1,2,3,4};
    cout << Solution().maxProduct(v) << endl;

}