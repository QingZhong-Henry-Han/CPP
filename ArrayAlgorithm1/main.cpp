// Algorithm questions: for array
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


class Solution
{
  
public:
  
  int findNumOfPairsGreaterZero(int nums[], int N)
  {
    int count = 0;    
    sort(nums, nums+N);
    
    for(int i = 0; i < N; i++)
    {
      if(nums[i] < 0)
      {
	continue;
      }

     int j = lower_bound(nums, nums+N, -nums[i] + 1) - nums;
     count += i - j;        
    }

    return count;
  }

  // use devide and conquer method
  // analysis O(NlogN)
  int findTwoItemsEqualtoSum(int nums[], int N, int sum)
  {
    int count = 0;
    for(int i = 0; i < N-1; i++)
      {
	if((nums[i]+nums[N/2]) > sum)
	  {
	  }
	else if( (nums[i]+nums[N/2]) < sum)
	  {
	  }
	else if((nums[i]+nums[N/2]) == sum)
	  {
	    count++;
	  }
      }

    return count;
  }

  // array devide and conquer method
  int arrayDevideConquer(int nums[], int N)
  {

    return 0;
  }

// function to find the maximum no. 
// in a given array. DAC method
//Analysis: O(nlogn)
int DAC_Max(int a[], int index, int N) 
{ 
    int max;
    // if only two elements
    if (index >= N - 2)
    { 
        if (a[index] > a[index + 1])
	  {
            return a[index];
	  }
        else
	  {
            return a[index + 1];
	  }
    } 
  
    // logic to find the Maximum element 
    // in the given array. 
    max = DAC_Max(a, index + 1, N); 
  
    if (a[index] > max)
      {
        return a[index];
      }
    else
      {
        return max;
      }
} 

  void printArr(int nums[], int N)
  {
    for( int i = 0; i < N; i++)
      {
	cout << nums[i] << " ";
      }

    cout << "\n";
  }

  void testCases()
  {
    int arr[] = { 3, -2, 1 };      
    cout << findNumOfPairsGreaterZero(arr, 3) << "\n";
  }

  void testEqualToSum()
  {
    int arr[] = {1,2,3,4,5,7};
    cout << findTwoItemsEqualtoSum(arr, 6, 7);
  }

  void testDevideAndComquer()
  {
    // Initializing the array
    int N = 7;
    int arr[] = { 70, 250, 50, 80, 140, 12, 14 }; 
  
    // recursion - DAC_Max function called 
    cout << "max= " << DAC_Max(arr, 0, N) << "\n"; 
  }

  //
  //The selection sort algorithm sorts an array by repeatedly finding the minimum element
  //(considering ascending order) from unsorted part and putting it at the beginning.
  //The algorithm maintains two subarrays in a given array.
  //1) The subarray which is already sorted.
  //2) Remaining subarray which is unsorted.

  //In every iteration of selection sort, the minimum element (considering ascending order)
  //from the unsorted subarray is picked and moved to the sorted subarray.
  //Analysis: O(n*2)
  void SelectionSort(int arr[], int N)
  {
    for( int i = 0; i < N; i++ )
      {
	int min = i;
	
	for( int j = i+1; j < N; j++)
	  {
	    if( arr[min] > arr[j])
	      {
		min = j;
	      }
	  }

	// swap min  and i
	if(min != i )
	  {
	    int temp = arr[min];
	    arr[min] = arr[i];
	    arr[i] = temp;
	  }
      }
  }
  
  void testSelectionSort()
  {
    int N = 5;
    int arr[] = {64, 25, 12, 22, 11};
    SelectionSort(arr, N);
    for(int i = 0; i < N; i++)
      {
	cout << arr[i] << " ";
      }
    cout << "\n";
  }
  
//Insertion Sort
//Insertion Sort is the simplest sorting algorithm that works
//by playing card.
//Analysis: o(n*2)
  void InsertionSort(int arr[], int N)
  {
     for( int i = 0; i < N-1; i++ )
      {
	int key = i+1;
	int j = i;
	// inserting key to sorted array
	while( (arr[key] < arr[j]) && (j >= 0))
	  {
	    int temp = arr[key];
	    arr[key] = arr[j];
	    arr[j] = temp;
	    key = key-1;
	    j = j-1;
	  }
      }
  }
  
  void testInsertionSort()
  {
    int N = 5;
    int arr[] = {64, 25, 12, 22, 11};
    InsertionSort(arr, N);
    for(int i = 0; i < N; i++)
      {
	cout << arr[i] << " ";
      }
    cout << "\n";
  }

//Bubble Sort
//Bubble Sort is the simplest sorting algorithm that works
//by repeatedly swapping the adjacent elements if they are in wrong order.
//Analysis: o(n*2)
  void BubbleSort(int arr[], int N)
  {
    for( int i = 0; i < N; i++ )
      {
	for( int j = i+1; j < N; j++)
	  {
	    if( arr[i] > arr[j])
	      {
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	      }
	  }
      }
  }
  
  void testBubbleSort()
  {
    int N = 5;
    int arr[] = {64, 25, 12, 22, 11};
    BubbleSort(arr, N);
    for(int i = 0; i < N; i++)
      {
	cout << arr[i] << " ";
      }
    cout << "\n";
  }

  //Merge Sort is a Divide and Conquer algorithm.
  //It divides input array in two halves, calls itself for the two halves
  //and then merges the two sorted halves.
  //The merge() function is used for merging two halves.
  //The merge(arr, l, m, r) is key process that assumes
  //that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
  //
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
  void mergeSort(int arr[], int l, int m, int r)
  {
    if(m > l )
      {
	mergeSort(arr,l, l+(m-l)/2, m);
      }

    if( r > (m+1))
      {
	mergeSort(arr, m+1, (m+1)+(r-m-1)/2, r);
      }
    
    // then merge these two
    merge(arr,l,m,r);
   }

  void testMergeSort()
  {
    int N = 7;
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int m = N/2;
    mergeSort(arr, 0, m, N-1);
    printArr(arr, N);
  }

//merge K sorted arrays
// Merge k sorted arrays

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

  struct KArrData
  {
    int row;
    int col;
    int data;
  };

class Compare
{
public:
  bool operator() (KArrData& rhl, KArrData& lhl )
  {
    return rhl.data > lhl.data;
  }
};

// use a defined compare class and priority queue
//to accomplish
void mergeKSortedArrays(int inputs[4][4], int rowNum, int colNum)
{
  int result[16];  
  priority_queue<KArrData, vector<KArrData>,  Compare> pq;
  //priority_queue<KArrData, vector<KArrData>,  [](KArrData& rhl, KArrData& lhl){ return rhl.data > lhl.data;}> pq;
  
  // populate the first K elements
  for( int row = 0; row < rowNum; row++)
  {
    KArrData temp;
    temp.row = row;
    temp.col  = 0;
    temp.data = inputs[row][temp.col];
    pq.push(temp);    
  }

  int index = 0;
  do
    {
      KArrData top = pq.top();
      pq.pop();

      result[index] = top.data;
      index++;
      int currRow = top.row;
      int nextCol = top.col + 1;

      if(nextCol < colNum)
	{
	  KArrData temp;
	  temp.row = currRow;
	  temp.col = nextCol;
	  temp.data = inputs[currRow][nextCol];
	  pq.push(temp);
	}      
    }while(!pq.empty());

  
  
  printArr(result, 16);
  //print_queue(min_queue);
}


  void testMergeKSortedArrays()
  {
    int k = 4;
    int m = 4;
  
    int inputs[4][4]        = {{1, 10, 11, 15},
			       {2,  4,  9, 14},
			       {5,  6,  8, 16},
			       {3,  7, 12, 13}};
    int output;
    mergeKSortedArrays(inputs, k, m);
  
    //Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.testCases();
   //s.testDevideAndComquer();
   //s.testSelectionSort();
   //s.testInsertionSort();
   //s.testBubbleSort();
   // s.testMergeSort();
   s.testMergeKSortedArrays();

   
  return 0;
}
