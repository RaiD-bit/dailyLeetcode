#include<bits/stdc++.h>
using namespace std;

// slow DFS

class Solution {
public:
    // O(n2)
    bool check(vector<string> &a, vector<string> &b){
        for(int i = 1; i<a.size(); i++){
            for(int j = 1; j<b.size(); j++){
                if(a[i] == b[j]){
                    return true;
                }
            }
        }
        return false;
    }
    
    void dfs(set<string> &s, int pos, vector<bool> &vis,vector<vector<int>> &adj, vector<vector<string>>& accounts){
        vis[pos] = true;
        for(int i = 1; i<accounts[pos].size();i++){
            s.insert(accounts[pos][i]);
        }
        for(auto x: adj[pos]){
            if(!vis[x])
                dfs(s,x,vis,adj,accounts);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<int>> v(n);
        vector<set<string>> string_set(n);
        // O(N2*K2) given k is the avg length of string
        for(int i = 0; i<n; i++){
            
            for(int j = i+1; j<n; j++){
                if(check(accounts[i],accounts[j])){
                     v[i].push_back(j);
                     v[j].push_back(i);           
                }
            }
        }

        vector<vector<string>> ans;
        vector<bool> vis(n);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                set<string> s;
                dfs(s, i, vis,v,accounts);
                vector<string> z;
                z.push_back(accounts[i][0]);
                for(auto x: s){
                    z.push_back(x);
                }
                ans.push_back(z);
            }
        }
        return ans;

        
        
    }
};

int main(){
    vector<vector<string>> accounts = 
        {
            {"John","johnsmith@mail.com","john_newyork@mail.com"},
            {"John","johnsmith@mail.com","john00@mail.com"},
            {"Mary","mary@mail.com"},
            {"John","johnnybravo@mail.com"}
        };
    Solution().accountsMerge(accounts);
}