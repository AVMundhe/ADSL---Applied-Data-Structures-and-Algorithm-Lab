import java.util.*;
class p3{

    public static long fact(int n){
            if(n==1){
                return 1;
            }
            if(n==0){
                return 1;
            }
            return n * fact(n-1);
    }

    public static int  NumberOfZero(long fact){
        int no=0;
        while (fact%10==0) {
            no++;
            fact/=10;
        }
        return no;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter the no. of Minimum Trailing 0's you want: ");
        n=sc.nextInt();

        

        int low=0;
        int high=n*5;
        int mid=high/2;
        int n_zero=0;
        long factorial=fact(mid);
        n_zero=NumberOfZero(factorial);
        if(n>=25){

        while(low<=high){
            if(n_zero==n){
                System.out.println("The number is: "+mid);
                break;
            }
            else if (n_zero<n) {
                low=mid+1;
            }
            else{
                high=mid;
            }
            mid=(high+low)/2;
            factorial=fact(mid);
            n_zero=NumberOfZero(factorial);
        }

    }
    else{
        if(n==5){
            System.out.println("Number is : 25");
        }
        
    }
      

    }
}