#include<iostream>
using namespace std;
#include<vector>
vector<int> arr;

 
int main(){
int ch=1;
int flag=0;
int num;

while(ch==1){
	cout<<"No: ";
	cin>>num;
	if(num==0){
		flag=1;
		arr.push_back(num);
	}
	else if(flag==1){
		cout<<"The Input is Wrong ,No 1 after 0"<<endl;
	
	}
	else if(num==1){
		arr.push_back(num);
	}
	else{
		cout<<"Only 1's and 0's are allowed"<<endl;
	}
	
	cout<<"Want to add one more?";
	cin>>ch;
}

for (int i = 0; i < arr.size(); i++)
{
	cout<<arr[i]<<" ";
}
cout<<endl;

int low=0;
int high=arr.size()-1;
int mid=high/2;

int total=0;
while (low<=high)
{
	if (arr[mid]==1 && arr[mid+1]!=0)
	{
		low=mid+1;
	}
	else if(arr[mid]==1 && arr[mid+1]==0){
		total=arr.size()-(mid+1);
		break;
	}
	else{
		high=mid-1;
	}
	
	mid=(low+high)/2;
}

cout<<"Total NO. of 0's: "<<total<<endl;


return 0;
}
