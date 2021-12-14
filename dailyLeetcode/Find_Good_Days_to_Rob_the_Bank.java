package dailyLeetcode;

import java.util.ArrayList;
import java.util.List;

public class Find_Good_Days_to_Rob_the_Bank {
    
    public static List<Integer> goodDaysToRobBank(int[] security, int time) {
        List<Integer> ans = new ArrayList<>();
        int n = security.length;
        List<Integer> prefix = new ArrayList<Integer>(n);
        List<Integer> suffix = new ArrayList<Integer>(n);
        for(int i = 0; i<n; i++){
            prefix.add(0);
            suffix.add(0);
        }
        System.out.println(prefix.size());
        int cnt = 1;
        prefix.add(0, cnt);

        for(int i = 1; i<n; i++){
            if(security[i] <= security[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            prefix.set(i, cnt);
        }

        cnt = 1;
        suffix.add(n-1, cnt);
        for(int i = n-2; i>=0;i--){
            if(security[i] <= security[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            suffix.set(i, cnt);
        }

        for(int i = 0; i<n; i++){
            if(prefix.get(i)-1 >= time && suffix.get(i)-1 >= time){
                ans.add(i);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int [] arr = {5,3,3,3,5,6,2};
        int time = 2;
        List<Integer> ans = goodDaysToRobBank(arr, time);
        for(Integer index: ans){
            System.out.print(index + " ");
        }
    }
}
