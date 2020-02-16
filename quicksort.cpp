#include<iostream>
#include<conio.h>

using namespace std;

int partition(int array[],int first, int last);
int quick_sort(int array[], int up, int down);
int main()
{
	int a[5], first, last;
	first=0;
	last=4;
	int i;
	cout<<"enter elements: \n"<<endl;
	for(i=0;i<=last;i++)
	{
		cin>>a[i];
	
	}
	quick_sort(a, first, last);
	
	cout<<"\n sorted elements are:"<<endl;
	for(i=0;i<=last;i++)
	{
	cout<<" "<<a[i]; 
    }
}

int partition(int array[],int up, int down)
{
	int pivot, temp=up, t;
	pivot=array[up];
	up++;
	while (up <= down)
	{
		while (array[up] <= pivot)
		{   
			up = up+1; 
		}	
	
		while (array[down] >= pivot)
		{
			down = down - 1; 
		}	 
		if (up < down)
		{
			temp=array[up];
			array[up]=array[down];
			array[down]=temp;
		}
	}

		t=array[temp];
		array[temp]=array[down];
		array[down]=t;
//			for(int i=0;i<=9;i++)
//			{
//			cout<<" "<<array[i]; 
//		    }
   		cout<<"*"<<endl;
return down;
}

int quick_sort(int array[], int up, int down)
{
 int loc;
	if (up<down)
	{
		loc=partition(array,up,down);
	
		quick_sort(array,up,loc-1);
		quick_sort(array,loc+1,down);
	} 
}




