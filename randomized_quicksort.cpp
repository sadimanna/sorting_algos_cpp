//LIBRARIES
#include <iostream>
#include <cstdlib>
#include <ctime>
//NAMESPACE
using namespace std;

/*. Implement a randomized version of quicksort that uses the partioning algorithm
from the previous step.*/
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

void quicksort(int *arr, int low, int high)
{
	int i,j,k,temp,pivot,arrpiv,temparrpiv;
	int arrlen = high - low;
	if (low<high)
	{
		arrpiv=low + rand()%arrlen;
		temparrpiv = arrpiv;
		//arrpiv -> index of pivot element in the array
		pivot = arr[arrpiv];
		cout << "Pivot element -> " << pivot << " || Index -> "<< arrpiv <<endl;
		//PARTITION
		//PARTITIONING IN SINGLE SWEEP
		i = low;
		while(i<high)
		{
			cout<<"Array index -> "<<i<<" Array element -> "<<arr[i]<<endl;
			//SWAPPING THE ELEMENTS
			if(arr[i] < pivot && arrpiv < i)
			{
				cout<<"Pivot > " << arr[i]<<" && "<<"Index > Pivot index"<<endl;
				temp = arr[i];
				for(k=i;k>arrpiv;k--)
					arr[k] = arr[k-1];
				arr[arrpiv] = temp;
				arrpiv++;
				i++;
			}
			else if (pivot < arr[i] && i < arrpiv)
			{
				cout<<"Pivot < " << arr[i]<<" && "<<"Index < Pivot index"<<endl;
				temp = arr[i];
				for(k=i;k<arrpiv;k++)
					arr[k] = arr[k+1];
				arr[arrpiv] = temp;
				arrpiv--;
				i!=0?i--:i=0;
				//RESTTING THE INDEX i TO THE VALUE
				//AFTER THE INITIAL PIVOT INDEX
				//IF THE PIVOT INDEX BECOMES 0
				if (arrpiv==0)
					i=temparrpiv+1;
			}
			else
				i++;
			//Displaying the array
			for(j=0;j<high;j++)
				cout << arr[j]<<" ";
			cout << endl;
			cout << "Updated Pivot Index -> " << arrpiv << endl;
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
		cout << "{}" << endl;
}

int main()
{
	int i=0,arrlen,*arr;
	//SETTING SEED
	srand(time(NULL));
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
