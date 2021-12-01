#include<bits/stdc++.h>
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m);
        int max_rectangle = 0;
        for(int i = 0; i<n; i++){
            if(i == 0){
                for(int j = 0; j<m; j++){
                    if(matrix[i][j] == '1'){
                        v[j] = 1;
                    }
                    else{
                        v[j] = 0;
                    }
                }
                max_rectangle = max(max_rectangle, largestRectangleArea(v));
            }
            else{
                for(int j = 0; j<m; j++){
                    if(matrix[i][j] == '1'){
                        v[j] = v[j] + 1;
                    }
                    else{
                        v[j] = 0;
                    }
                }
                max_rectangle = max(max_rectangle, largestRectangleArea(v));
            }
        }
        return max_rectangle;        
    }
};


int main(){
    vector<vector<char>> v = {
                                {'1','0','1','0','0'},
                                {'1','0','1','1','1'},
                                {'1','1','1','1','1'},
                                {'1','0','0','1','0'}
                            };
    cout << Solution().maximalRectangle(v) << endl; 
}