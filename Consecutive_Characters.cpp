#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        char c = ' ';
        int n = s.size();
        int cnt = 1;
        for(int i = 0; i<n; i++){
            if(c == s[i]){
                cnt++;
            }
            else{
                ans = max(ans,cnt);
                cnt = 1;
                c = s[i];
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};



int main(){
    string s = "abbcccddddeeeeedcba";
    cout << Solution().maxPower(s) << endl;
}