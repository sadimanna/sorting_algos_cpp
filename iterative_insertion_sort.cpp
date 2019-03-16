//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//1.Implement the iterative version of insertion sort.
//PSEUDOCODE
/*
insertion_sort(a, i, j)
{
	for k = i+1 to j−1
		// insert a[k] into a[i..k)
		x = a[k]
		p = k−1
		while (p >= i and x < a[p])
			a[p+1] = a[p]
			−−p
		a[p+1] = x
}
*/
void insertion_sort(int *arr, int arrlen)
{
	int temp,j,k;
	cout << "Length of array:: " << arrlen << endl;
	for (int i=1;i<arrlen;i++)
	{
		cout << endl << "Loop:: " << i << endl;
		j = 0;
		temp = arr[i];
		while(temp < arr[i-1-j] && i-1-j >= 0)
		{
			arr[i-j] = arr[i-1-j];
			j++;
			
			//Visualizing the shifting process
			for(k=0;k<arrlen;k++)
				k!=i-j ? cout << arr[k]<<" " : cout << "_" << " ";
			cout << endl;
		}
		//Assigning the key value
		arr[i-j] = temp;

		//Displaying the array after each iteration
		for(k=0;k<arrlen;k++)
			cout << arr[k]<<" ";
		cout << endl;
	}
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
	insertion_sort(arr, arrlen);
	//Displaying the sorted array
	cout << "Sorted array:: " << endl;
	for(i=0;i<arrlen;i++)
		cout << arr[i]<<" ";
	cout << endl;
}
