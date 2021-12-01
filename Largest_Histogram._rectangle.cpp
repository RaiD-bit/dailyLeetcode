#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NSL(vector<int> &v){
        vector<int> left;
        stack<pair<int,int>> st;
        int n = v.size();
        int pseudo_index = -1;
        for(int i = 0; i<n; i++){
            if(st.size() == 0){
                left.push_back(-1);
            }
            else if(st.size() > 0 && st.top().first < v[i]){
                left.push_back(st.top().second);
            }
            else if(st.size() > 0 && st.top().first >= v[i]){
                while (st.size() > 0 && st.top().first >= v[i])
                {
                    st.pop();
                }
                if(st.size() == 0){
                    left.push_back(-1);
                }
                else{
                    left.push_back(st.top().second);
                }
                
            }
            st.push({v[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int> &v){
        vector<int> right;
        stack<pair<int,int>> st;
        int n = v.size();
        int pseudo_index = n;
        for(int i = n-1; i>=0; i--){
            if(st.size() == 0){
                right.push_back(pseudo_index);
            }
            else if(st.size() > 0 && st.top().first < v[i]){
                right.push_back(st.top().second);
            }
            else if(st.size() > 0 && st.top().first >= v[i]){
                while (st.size() > 0 && st.top().first >= v[i])
                {
                    st.pop();
                }
                if(st.size() == 0){
                    right.push_back(pseudo_index);
                }
                else{
                    right.push_back(st.top().second);
                }
                
            }
            st.push({v[i], i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        // for(auto x: left)
        // cout << x << "\t";
        // cout << endl;
        // for(auto x: right)
        // cout << x << "\t";
        // cout << endl;

        int n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, (right[i] - left[i] - 1)*heights[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> v = {6,2,5,4,5,1,6};
    Solution().largestRectangleArea(v);
}