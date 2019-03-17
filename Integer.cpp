//LIBRARIES
#include <iostream>
#include <cstdlib>
#include <ctime>
//NAMESPACE
using namespace std;

class Integer
{
	public:
		int Integer_count, intval;
		Integer(int x = 0);
		void copy(Integer i2);
		int value();
		Integer operator < (Integer i2);
		Integer operator = (Integer i2);
};
Integer::Integer(int x)
{
	intval = x;
}
void Integer::copy(Integer i2)
{
	intval = i2.value();
}
int Integer::value()
{
	return intval;
}
Integer Integer::operator < (Integer i2)
{
	Integer_count+=1;
	if(intval<i2.value())
		return true;
	else
		return false;
}
Integer Integer::operator = (Integer i2)
{
	Integer_count+=1;
	intval = i2.value();
}


int main()
{
	int i=0,arrlen,*arr;
	//SETTING SEED
	srand(time(NULL));
	cout << "Enter number of elements to sort:: "<<endl;
	cin >> arrlen;
	arr = new int[arrlen];
	Integer arrInt[arrlen];
	//Taking inputs
	for(i=0;i<arrlen;i++)
		cin >> arr[i];
	//Displaying the array taken as input
	cout << "Entered Array:: " << endl;
	for(i=0;i<arrlen;i++)
	{
		arrInt[i] = Integer(arr[i]); //CREATING OBJECTS
		cout << arrInt[i].value() << " ";
	}
	//Calling the function for Insertion Sort
	//quicksort(arr, 0, arrlen);
	//Displaying the sorted array
	cout << endl << "Sorted array:: " << endl;
	for(i=0;i<arrlen;i++)
		cout << arr[i]<<" ";
	cout << endl;
}

