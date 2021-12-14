package dailyLeetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Find_Subsequence_of_Length_K_With_the_Largest_Sum {
    public static int[] maxSubsequence(int[] nums, int k) {
        int [] ans = new int[k];
        int [] og = nums.clone();
        Arrays.sort(nums);
        int n = nums.length;
        int [] z = Arrays.copyOfRange(nums, n-k, n);
        Map<Integer,Integer> m = new HashMap<>();
        for(int i = 0; i<z.length; i++){
            if(m.containsKey(z[i])){
                m.put(z[i], m.get(z[i])+1);
            }
            else{
                m.put(z[i],1);
            }
        }
        int p = 0;
        for(int i = 0; i<og.length; i++){
            if(m.containsKey(og[i])){
                if(m.get(og[i])>0){
                    ans[p++] = og[i];
                    m.put(og[i], m.get(og[i])-1);
                }
            }
        }

        return ans; 
    }
    
    public static void main(String[] args) {
        int a[] = {2,1,3,3};
        int ans[] = maxSubsequence(a, 2);
        for(int i = 0; i<ans.length; i++){
            System.out.println(ans[i]);
        }

    }
}
