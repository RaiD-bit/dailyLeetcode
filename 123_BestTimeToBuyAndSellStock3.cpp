#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // so we have got the following state variables :
    //     -> curr_state : curr_state of holding a stock ie at this point you have a stock or not
    //     -> k : no of transactions left to execute
    //     -> pos: at which day are we at. at each day we must make a decision.

    // what are the decision that we can make on a trading day
    //     -> sell 
    //     -> buy
    //     -> move on like nothin happened :)

    // => but if you look carefully we can only make any 2 of these choices on a particular day depending wether we have a stock or not
    //     -> let's say we have a stock on a given day then we can either sell or move on. WE CANT BUY AGAIN AS MENTIONED IN THE PROBLEM
    //         another situation will be if we dont have a sotck then we can only buy or skip 
    
    
    int fun(int curr_state, int k, int pos, vector<int> &v, vector<vector<vector<int>>> &dp){
        if(pos == v.size() || k == 0){
            return 0;
        }
        if(dp[curr_state][k][pos] != -1){
            return dp[curr_state][k][pos];
        }

        if(curr_state == 0){
            // this means we dont have stock with us at this time => ITS time to move on or BUY $$
            return dp[curr_state][k][pos] = max(fun(curr_state,k,pos+1,v,dp),fun(curr_state+1,k,pos+1,v,dp)-v[pos]);
        }
        else {
            return dp[curr_state][k][pos] = max(fun(curr_state,k,pos+1,v,dp),fun(curr_state-1,k-1,pos+1,v,dp)+v[pos]);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (3, vector<int> (n,-1)));
        return fun(0,2,0,prices,dp);
    }
};

int main(){
    // vector<int> v = {1};
    // vector<int> v = {1,2,3,4,5};
    vector<int> v = {3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit(v) << endl;
}