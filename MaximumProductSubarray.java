package dailyLeetcode;

public class MaximumProductSubarray{

    public static int maxProduct(int [] v){
        int ans = 0;
        int maximum_ending_here = 0;
        int minimum_ending_here = 0;
        int n = v.length;
        if(n == 1)
            return v[0];
        for(int i = 0; i<n; i++){
            int z = maximum_ending_here;
            maximum_ending_here = Math.max(v[i], Math.max(maximum_ending_here*v[i], minimum_ending_here*v[i]));
            minimum_ending_here = Math.min(v[i], Math.min(z*v[i], minimum_ending_here*v[i]));
            ans = Math.max(ans, maximum_ending_here);
        }
        return ans;
    }
    public static void main(String[] args) {
        int [] arr = {2,3,-1,4};
        System.out.println(maxProduct(arr));
    }
}
