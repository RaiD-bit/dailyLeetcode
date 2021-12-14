#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> prefix(n);      
        vector<int> suffix(n);
        vector<int> ans;
        int cnt = 1;
        prefix[0] = cnt;
        for(int i = 1; i<n; i++){
            if(security[i] <= security[i-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            prefix[i] = cnt;
        }

        cnt = 1;
        suffix[n-1] = 1; 
        for(int i = n-2; i>=0; i--){
            if(suffix[i] <= suffix[i+1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            suffix[i] = cnt;
        }      

        for(int i = 0; i<n; i++){
            if(prefix[i] - 1 >= time && suffix[i] - 1 >= time ){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v = {5,3,3,3,5,6,2};
    int time = 2;
    vector<int> ans = Solution().goodDaysToRobBank(v,time);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
}