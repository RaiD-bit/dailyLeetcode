#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
            return false;
        unordered_map<int,int> umap;
        
        for(auto x: hand){
            umap[x]++;
        }
        for(int i = 0; i<n; i++){
            if(umap[hand[i]]!=0){
               
                for(int j = hand[i]; j<hand[i]+groupSize; j++){
                    if(umap[hand[j]]){
                        umap[hand[j]]--;
                    }
                }
            }
        }
        return true;
        
    }
};


int main(){
    vector<int> v1 = {1,2,3,6,2,3,4,7,8};
    int k1 = 3;
    vector<int> v2 = {1,2,3,4,5};
    int k2 = 4;
    cout << Solution().isNStraightHand(v1,k1) << endl;
    cout << Solution().isNStraightHand(v2,k2) << endl;
}