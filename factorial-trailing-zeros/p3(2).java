import java.util.*;


class test{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter the no. of Minimum Trailing 0's you want: ");
        n=sc.nextInt();
        int dif=0;

        
        if (n%10==0) {
            n*=5;
            dif=n/25;
            n-=((dif-1)*5);   
        }
        else{
            n*=5;
            dif=n/25;
            n-=(dif*5);
        }
        System.out.println("The no. is: "+n);
        
     

     
    }
}
