#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void selectionSort(int intArray[], int MAX) 
{

   int indexMin,i,j;
	
   // loop through all numbers 
   for(i = 0; i < MAX-1; i++) { 
	
      // set current element as minimum 
      indexMin = i;
		
      // check the element to be minimum 
      for(j = i+1;j<MAX;j++)
	   {
         if(intArray[j] < intArray[indexMin])
		  {
            indexMin = j;
            
         }
      }	
         // swap the numbers 
         int temp = intArray[indexMin];
         intArray[indexMin] = intArray[i];
         intArray[i] = temp;
      }          

 } 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 {
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
}

 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
int main()
{
    int n, arr[100], choice;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    	{
    		printf("Enter the elemnet:");
    		scanf("%d\n", &arr[i]);
		}
		printf("Enter choice of sorting:\n");
		printf("1.Selection Sort\n2.Bubble Sort\n3.Insertion\n");
		printf("Enter the choice:");
		scanf("%d\n", &choice);
		switch(choice)
		{
			case 1:
				selectionSort(arr, n);
				break;
			case 2:
				bubbleSort(arr,  n);
				break;
			case 3:
				insertionSort(arr, n);
				break;
			default:
				break;
		}
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
