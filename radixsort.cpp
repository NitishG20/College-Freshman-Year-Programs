// C implementation of Radix Sort
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 struct node
{
	int info;
	node *next, *prev;
};
// This  function gives maximum value in array[]
int getMax(node *start, int n)
{
    int i;
    int max = start->info;
    for (i = 1; i < n; i++){
        if (start->info > max)
            max =start->info;
	start=start->next;
    }
    return max;
}
 
// Main Radix Sort sort function
//node* radixSort(node *start, int n, node *end)
//{
//    int i,digitPlace = 1;
//    int result[n]; // resulting array
//    // Find the largest number to know number of digits
//    int largestNum = getMax(start, n);
// 	node *temp= start;
// 
//    //we run loop until we reach the largest digit place
//    while(largestNum/digitPlace >0){
// 
//        int count[10] = {0};
//         //Store the count of "keys" or digits in count[]
//        for (i = 0; i < n; i++){
//            count[ (temp->info/digitPlace)%10 ]++;
//	temp=temp->next;
//	}
// 
//        // Change count[i] so that count[i] now contains actual
//        //  position of this digit in result[]
//        //  Working similar to the counting sort algorithm
//        for (i = 1; i < 10; i++)
//            count[i] += count[i - 1];
// 	temp=end;
//        // Build the resulting array
//        for (i = n - 1; i >= 0; i--)
//        {
//            result[count[ (temp->info/digitPlace)%10 ] - 1] = temp->info;
//            count[ (temp->info/digitPlace)%10 ]--;
//	temp=temp->prev;
//        }
// 
//        // Now main array A[] contains sorted
//        // numbers according to current digit place
//	temp=start;
//        for (i = 0; i < n; i++){
//            temp->info = result[i];
//	temp=temp->next;
//	}
// 
//            // Move to next digit place
//            digitPlace *= 10;
//    }
//	return start;
//}
// 
struct node *rsort(struct node *list,  const int base, int rounds){
    int n = 1;
    struct node **bucket, *next, *temp;
    // Dyamic bucket array
    bucket = (node **)malloc(sizeof(*bucket)*base);
 
 
    for(int j = 0; j < rounds ;j++)
    {        
        //Place numbers into buckets.        
        while(list!= NULL)
        {    
 
 
                next                  = list->next;            
                list->next            = bucket[(list->info/n)%base];
                bucket[(list->info/n)%base]  = list;
                list                  = list->next;
                list                  = next;
        }
        //Rebuild list
        for(int i = 0; i < base; i++)
        {        
            while(bucket[i]!=NULL)
            {
                temp            = bucket[i]->next;
                bucket[i]->next = list;
                list            = bucket[i];
                bucket[i]       = bucket[i]->next;
                bucket[i]       = temp;
            }
        }
        n *=10;
    }
 
 
    return list;
}
// Function to print an array
void printlist(node *start, int n)
{
    int i;
    for (i = 0; i < n; i++){
	
    printf("%d ", start->info);
    start=start->next;
	}
    printf("\n");
	
}
 
// Driver program to test above functions
int main()
{	node *end;
	node *start=new node;
	node* temp= start;
	int n=10;
	for(int i=0; i<n; i++)
	{	temp->next=new node;
		temp->next->prev=temp;
		cin>>temp->info; 
		temp=temp->next;	
	}
	end=temp->prev;
    printf("Unsorted Array: ");
    printlist(start, n);
 
    start=rsort(start, 10, 2);
 
    printf("Sorted Array: ");
    printlist(start, n);
    return 0;
}
