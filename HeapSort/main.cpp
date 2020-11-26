// Algorithm questions: for Heap
//
//  1. question
// Number of pairs in an array with the sum greater than 0
// Given an array arr[] of size N, the task is to find the number of distinct pairs in the array
// whose sum is > 0.
// 
// 2. question
//  given a sorted array. find the two items that euqals to a given number k.
//

#include <bits/stdc++.h>

using namespace std;


class Heap
{
  
public:

  // analysis: O(logN)
  void max_heapify (int arr[], int i, int N)
  {
    int left = 2*i;
    int right = 2*i + 1;

    int largest = i;
	  
    if(left <= N && arr[left] > arr[i] )
    {
       largest = left;
    }
    else
    {
       largest = i;
    }
	
    if(right <= N && arr[right] > arr[largest] )
    {
        largest = right;
    }
    
    if(largest != i )
    {
        swap (arr[i] , arr[largest]);
        max_heapify (arr, largest, N);
    }
  }
  

  void printArr(int nums[], int N)
  {
    for( int i = 1; i <= N; i++)
    {
	cout << nums[i] << " ";
    }

    cout << "\n";
  }

  void build_maxheap()
  {
    int N = 7;
    int arr[] = {0, 4, 5, 1, 6, 7, 3, 2};
    cout << "build max heap: \n";
    printArr(arr, N);
    for(int k = N/2; k >=1; k--)
    {
      max_heapify(arr, k, N);
    }
    cout << "max heap: \n";
    printArr(arr, N); 
  }


  void std_make_heap()
  {
    cout << "\n";
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    make_heap(numbers.begin(), numbers.end()); 
    for (auto number : numbers)
    {
      std::cout << number << ' ';
    }
    cout << "\n";
  }
};


int main(int argc, char* argv[] )
{
   Heap h;
   //h.build_maxheap();
   h.std_make_heap();
   return 0;
}
