#include<bits/stdc++.h>
using namespace std;

// better dfs

class Solution {
public:

    void dfs(unordered_map<string,vector<string>> &adj, unordered_set<string> &vis, string curr, vector<string> &all_accounts){
        vis.insert(curr);
        all_accounts.push_back(curr);
        for(auto email: adj[curr]){
            if(vis.find(email) == vis.end())
                dfs(adj,vis,email,all_accounts);
        }
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // key: first_email val vector of all connecting emails
        unordered_map<string,vector<string>> adj;
        unordered_set<string> vis;

        for(auto acc: accounts){
            string first = acc[1];
            for(int i = 2; i<acc.size(); i++){
                adj[first].push_back(acc[i]);
                adj[acc[i]].push_back(first);
            }
        }

        vector<vector<string>> ans;

        for(auto acc: accounts){
            string u_name = acc[0];
            string first = acc[1];
            vector<string> all_accounts;
            if(vis.find(first) == vis.end()){
                all_accounts.push_back(u_name);
                dfs(adj,vis,first,all_accounts);
                sort(all_accounts.begin()+1,all_accounts.end());
                ans.push_back(all_accounts);
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