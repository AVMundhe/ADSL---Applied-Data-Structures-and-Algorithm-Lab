#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int count=0;
int n;
int last;

void merge(int arr[],int low,int high){
    last=high;
    for (int i = low; i <= high; i++)
    {
        if (arr[i]==0)
        {     
            int flag=0;
            while (flag!=1 && i<last)
            {   if(i>=last){
                    flag=1;
                }
                if (arr[last]!=0)
                {
                    int temp=arr[last];
                    arr[last]=arr[i];
                    arr[i]=temp;
                    last--;
                    flag=1;
                }
                else{
                    last--;
                }
            }
        }
       
        
    }
}

void divide(int arr[],int low, int high){
   
    if (low >= high )
    {   
        return;
    }
 
    divide(arr,low,(low+high)/2);

    divide(arr,((low+high)/2)+1,high);
    
    merge(arr,low,high);

}


int main(){
    
    cout<<"Enter the Size of Array: ";
    cin>>n;
    int arr[n];
    last=n-1;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter at "<<i<<" index: ";
        cin>>arr[i];
    }

    cout<<"Orignal : "<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    divide(arr,0,n-1);

    
    
    cout<<endl<<"Final Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 