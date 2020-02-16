#include<iostream>
using namespace std;
void binsearchiterative(int ar[],int size,int ele)
{
	int lower=0, upper=size-1, mid, count=0;
	while(lower<upper)
	{	count++;
		mid=(lower+upper-1)/2;
		if(ar[mid]==ele)
		{	count++;
			cout<<"Element found at "<<mid+1<<"th position"<<endl;
			cout<<count<<endl;
			return;
			}	
		if(ar[mid]<ele){
		
			lower=mid+1;
			count++;
		}
		else{
		count++;
			upper=mid-1;
		}
	}
	cout<<"Element Not Found"<<endl;
	cout<<count;
}	

int main()
{
	int ar[10000], size;
	int se;
	cout<<"Enter no. of array elements:\n";
	cin>>size;
	for(int i=0;i<size; i++)
	{		ar[i]=i;
			cout<<ar[i];
			
		}
	cout<<"Enter element to be searched:\n";
	cin>>se;
	binsearchiterative(ar, size, se);		
	
}
