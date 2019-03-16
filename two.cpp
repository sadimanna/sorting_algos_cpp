//CLARKSON UNIVERSITY
//CS344
//SPRING 2019
//PROJECT 1

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

/*Implement a version of quicksort that always uses the first element of the
array as pivot. Your implementation should be based on the pseudocode
given in Sect. 3.4. Use the solution to Exercise 3.4.5 as a starting point.
But modify the partitioning algorithm so it does only one scan of the array*/
//PSEUDOCODE
/*quicksort(a, i, j)
{
	if (j − i >= 2)
		choose a pivot in a[i..j)
		partition a[i..j) around the pivot
		k = new index of the pivot
		quicksort(a, i, k)
		quicksort(a, k+1, j)
}*/

/*int *realloc_1(int *arr, int arrlen)
{
	int *temparr;
	temparr = new int[arrlen+1];
	for (int i = 0; i<arrlen; i++)
		temparr[i] = arr[i];
	return temparr;
}*/

void quicksort(int *arr, int low, int high)
{
	int i,j,temp;
	if (low<high)
	{
		int pivot = arr[low];
		cout << "Pivot element -> " << pivot << endl;
		//PARTITION
		int arrpiv=low, k; //arrpiv -> index of pivot element in the array
		//PARTITIONING IN SINGLE SWEEP
		for(i=low+1;i<high;i++)
		{
			//cout<<"...."<<i<<"...."<<endl;
			//SWAPPING THE ELEMENTS
			if(arr[i] < pivot)
			{
				temp = arr[i];
				for(k=0;k<i-arrpiv;k++)
					arr[i-k] = arr[i-1-k];
				arr[arrpiv] = temp;
				arrpiv++;
			}
			//Displaying the array
			for(j=0;j<high;j++)
				cout << arr[j]<<" ";
			cout << endl;
		}
		//DISPLAYING THE PARTITIONED ARRAYS
		cout << "..Partitioned Array.." << endl;
		for(i=low;i<high;i++)
			arr[i]!=pivot?cout<<arr[i]<<" ":cout<<"|"<<arr[i]<<"| ";
		cout << endl;
		
		//RECURSIVE CALLS
		quicksort(arr,low,arrpiv); //LEFT PARTITION
		quicksort(arr,arrpiv+1,high); //RIGHT PARTITION
	}
	else
		cout << "||" << endl;
}
	
int main()
{
	int i=0,arrlen,*arr;
	cout << "Enter number of elements to sort:: "<<endl;
	cin >> arrlen;
	arr = new int[arrlen];
	//Taking inputs
	for(i=0;i<arrlen;i++)
		cin >> arr[i];
	//Displaying the array taken as input
	cout << "Entered Array:: " << endl;
	for(i=0;i<arrlen;i++)
		cout << arr[i]<<" ";
	cout << endl;
	//Calling the function for Insertion Sort
	quicksort(arr, 0, arrlen);
	//Displaying the sorted array
	cout << endl << "Sorted array:: " << endl;
	for(i=0;i<arrlen;i++)
		cout << arr[i]<<" ";
	cout << endl;
}

