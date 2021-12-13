package dailyLeetcode;

public class NthMagicalNumber {
    
    public static Long HCF(int a, int b){
        return (b != 0)?HCF(b,a%b):a;
    }

    public static Long LCM(int a, int b){
        return a*b/(HCF(a,b));
    }

    public static Long getNfromX(Long x, int a, int b){
        return (x/a) + (x/b) - (x/LCM(a,b));
    }

    public static int nthMagicalNumber(int n, int a, int b) {
        // System.out.println(HCF(6,64));  
        Long lo = 1L;
        Long hi = 1000000000000000001L;
        n--;
        while (lo < hi) {
            Long mid = lo + (hi - lo)/2;
            // System.out.println(mid);
            Long n1 = getNfromX(mid, a, b);
            if(n < n1){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        Long ans = lo%(1000000007);
        return ans.intValue();
    }

    public static void main(String[] args) {
        int ans = 0;
        ans = nthMagicalNumber(3,8,9);
        System.out.println(ans);

    }
}
