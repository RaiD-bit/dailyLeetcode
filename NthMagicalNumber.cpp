#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int HCF(int a, int b){
        return b?HCF(b,a%b):a;
    }
    
    int LCM(int a, int b){
        return (a*b)/HCF(a,b);
    }
    
    // N -> X
    long long getNfromX(long long x, int a, int b){
        int lcm = LCM(a,b);
        return (x/a) + (x/b) - (x/lcm);
    }
    
    
    int nthMagicalNumber(int n, int a, int b) {
        long long lo = 1, hi= 1e17;
        n--;
        while(lo < hi){
            long long mid = lo + (hi - lo)/2;
            long long n1 = getNfromX(mid,a,b);
            if(n < n1){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        
        return lo%(1000000007);
        
    }
};

int main(){
    cout << Solution().nthMagicalNumber(3,8,9) << endl;
}

