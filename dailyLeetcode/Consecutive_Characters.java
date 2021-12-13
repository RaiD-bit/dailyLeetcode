package dailyLeetcode;

class Consecutive_Characters{
    public static int maxPower(String s) {
        int ans = 0;
        int n = s.length();
        int cnt = 1;
        char c = ' ';
        for(int i = 0; i<n; i++){
            if(s.charAt(i) == c){
                cnt++;
            }
            else{
                ans = Math.max(ans, cnt);
                cnt = 1;
                c = s.charAt(i);
            }
        }
        ans = Math.max(ans, cnt);
        return ans;
    }


    public static void main(String[] args) {
        String s = "triplepillooooow";
        System.out.println(maxPower(s));
    }
}