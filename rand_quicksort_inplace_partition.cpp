//LIBRARIES
#include <iostream>
#include <cstdlib>
#include <ctime>
//NAMESPACE
using namespace std;

/*. Implement a randomized version of quicksort that uses the in-place partioning
algorithm described in Sect. 3.6.*/
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
	int i,j,k,temp,pivot,arrpiv,grtind,flag=0;
	int arrlen = high - low;
	if (low<high)
	{
		arrpiv=low + rand()%arrlen;
		grtind = arrpiv;
		//arrpiv -> index of pivot element in the array
		//SETTING PIVOT ELEMENT
		pivot = arr[arrpiv];
		cout << "Pivot element -> " << pivot << " || Index -> "<< arrpiv <<endl;
		//PARTITION
		//PARTITIONING IN SINGLE SWEEP
		
		i = low;
		while(i<high)
		{
			cout<<"Array index -> "<<i<<" Array element -> "<<arr[i]<<endl;
			//ARRANGING THE ARRAY
			if(arr[i] < pivot && arrpiv < i)
			{
				//SHIFTING THE RIGHT PARTITION ONE PLACE TOWARDS RIGHT
				//AND PLACING THE ELEMENT SMALLER THAN THE PIVOT 
				//AT THE START INDEX OF THE RIGHT PARTITION
				cout<<"Pivot > " << arr[i]<<" && "<<"Index > Pivot index"<<endl;
				temp = arr[i];
				for(k=i;k>grtind;k--)
					arr[k] = arr[k-1];
				arr[grtind] = temp;
				//UPDATING THE PIVOT INDEX
				arrpiv++;
				//UPDATING THE START OF THE RIGHT PARTITION
				grtind++;
				i++;
			}
			else if (pivot < arr[i])
			{
				cout<<"Pivot < " << arr[i]<<" && "<<"Index < Pivot index"<<endl;
				//SETTING THE INDEX OF THE FIRST ELEMENT OF THE RIGHT PARTITION
				if(flag==0)
				{
					grtind = i;
					flag = 1;
				}
				i++;						
			}
			else 
				i++;
			//Displaying the array
			for(j=0;j<high;j++)
				cout << arr[j]<<" ";
			cout << endl;
			cout << "Updated Pivot Index -> " << arrpiv << endl;
		}
		//SHIFTING THE PIVOT TO ITS PLACE
		cout<<"Shifting the PIVOT to the start of the right partition"<<endl;
		temp = arr[arrpiv];
		cout<<"Pivot -> " << temp <<" && "<<"Index -> "<<arrpiv << endl;
		for(k=arrpiv;k>grtind;k--)
			arr[k] = arr[k-1];
		arr[grtind] = temp;
		arrpiv = grtind;
		grtind++;
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
