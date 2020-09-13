// this is the routine for graph component

#include <bits/stdc++.h>

using namespace std;

int binarySearchIter(int array[], int x, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] < x)
			low = mid + 1;

		else
			high = mid - 1;
	}

	return -1;
}

int binarySearchRecur(int array[], int x, int low, int high) 
{ 
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] > x)
			return binarySearchRecur(array, x, low, mid - 1);

		return binarySearchRecur(array, x, mid + 1, high);
	}

	return -1;
} 

int main(int argc, char* argv[] )
{

  
        // test cases for recursive method
  	int array[] = {3, 4, 5, 6, 7, 8, 9}; 
	int x = 4; 
	int n = sizeof(array) / sizeof(array[0]); 
	int result = binarySearchIter(array, x, 0, n - 1); 
        if (result == -1)
		printf("Not found (iterative)\n");
	else
		printf("Element is found at index(iterative) %d\n", result);
  
	result = binarySearchRecur(array, x, 0, n - 1); 
        if (result == -1)
		printf("Not found (recursive)\n");
	else
		printf("Element is found at index(recursive) %d\n", result);
  

  return 0;
}
