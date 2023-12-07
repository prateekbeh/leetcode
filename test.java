public class Solution {
    public static String doesMeet(int x1,int x2,int v1,int v2){
        if (x1 < x2 && v1 <= v2) {
            return false;
        }
        if (x1 > x2 && v1 >= v2) {
            return false;
        }
 
        // Making sure that x1 is greater 
        if (x1 < x2) {
            swap(x1, x2);
            swap(v1, v2);
        }
        return ((x1 - x2) % (v1 - v2) == 0);
    }
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while(tc--) {
            int x1 = sc.nextInt();
            int v1 = sc.nextInt();
            int x2 = sc.nextInt();
            int v2 = sc.nextInt();

            if(doesMeet(x1,x2,v1,v2)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }

        }
        
    }
}