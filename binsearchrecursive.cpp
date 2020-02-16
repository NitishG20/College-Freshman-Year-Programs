#include<iostream>
using namespace std;
int binsearchrecursive(int ar[], int top, int bottom, int ele,int count=0)
{   count++;
	if(top>bottom)
	{	
		cout<<"Element not present"<<endl;
		return count;
	}
	int mid=(top+bottom-1)/2;
	count++;
	if(ele==ar[mid])
	{	
	
		cout<<"Element found"<<endl;
		return count;
	
	
	}
	count++;
	if(ele>ar[mid])
	{
		
		count=binsearchrecursive(ar, mid+1, bottom, ele, count);
}
	else
	{
		count++;
			count=binsearchrecursive(ar, top, mid-1, ele, count);
}
	return count;		
}
int main()
{
	int ar[100000], size;
	int se;
	cout<<"Enter no. of array elements:\n";
	cin>>size;
	for(int i=0;i<size; i++)
		ar[i]=i;
	cout<<"Enter element to be searched:\n";
	cin>>se;
	cout<<binsearchrecursive(ar, 0, size-1, se)<<endl;		
	
}
