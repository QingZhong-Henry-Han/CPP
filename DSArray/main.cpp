//
// for array data strcture
//1.How do you find the missing number in a given integer array of 1 to 100? (solution)
//2.How do you find the duplicate number on a given integer array? (solution)
//3.How do you find the largest and smallest number in an unsorted integer array? (solution)
//4.How do you find all pairs of an integer array whose sum is equal to a given number? (solution)
//5.How do you find duplicate numbers in an array if it contains multiple duplicates? (solution)
//6.How are duplicates removed from a given array in Java? (solution)
//7.How is an integer array sorted in place using the quicksort algorithm? (solution)
//8.How do you remove duplicates from an array in place? (solution)
//9.How do you reverse an array in place in Java? (solution)
//10.How are duplicates removed from an array without using any library? (solution)
//


#include <bits/stdc++.h>

using namespace std;


class Solution
{
  
public:

  //Q1.
  void findOneMissingNum(int &missingNum, int nums[], int N)
  {
    for( int i = 0; i < N; i++)
      {
	missingNum ^= i^nums[i];
      }
  }

  //Q2.
  void findOneDuplicateNum(int &duplicateNum, int nums[], int N)
  {
    for(int i = 0; i < N; i++)
      {
	 duplicateNum ^= nums[i];
      }
   
    for(int i = 0; i < N-1; i++)
      {
	duplicateNum ^= i;
      }
  }

  //Q3. 
  void findTheLargestNSmallestNum(int &maxNum, int &minNum, int nums[], int N)
  {
    int*  pMax = max_element(nums, nums+N);
    maxNum = *pMax;
    int* pMin = min_element(nums, nums+N);
    minNum = *pMin;
  }

  //Q4.
  void findAllPairsSumEqNum(int &count, int nums[], int N, int k)
  {
    count = 0;
    for( int i = 0; i < N; i++)
      {
	int remaining = k - nums[i];
	int* pLower = lower_bound(nums, nums+N, remaining);
	int* pUpper = upper_bound(nums, nums+N, remaining);
	count += pUpper-pLower;
      }
  }

  //5.
  void findMultiDuplicatesInArr(int nums[], int N)
  {
    int count[11] = {0};
    for(int i = 0; i < N; i++)
      {
	count[nums[i]]++;
      }

    for( int i = 0; i < N; i++)
      {
	if(count[i] > 1 )
	  {
	    cout << i << " : " << count[i] << " ; ";
	  }
      }

    cout << "\n";
  }

  //6
  void removeDuplicates(int nums[], int N)
  {
    
  }

  //7.
  void sortedinPlaceUsingQuickSort()
  {
  }

  //8.
  void removeDuplicateInPlace()
  {
  }

  //9.
  void reverseArrayInPlace()
  {
  }

  //10.
  void removeDuplicateWithoutUsingLib()
  {
    
  }

  void TestQ0()
  {
    priority_queue<int, vector<int>> maxHeap;
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(40);
    while(!maxHeap.empty())
      {
	cout << maxHeap.top() << " ";
	maxHeap.pop();
      }
    cout << "\n";
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(40);
    while(!minHeap.empty())
      {
	cout << minHeap.top() << " ";
	minHeap.pop();
      }
    cout << "\n";
  }

  void TestQ1()
  {
    int N = 10;
    int arr[] = {0,1,2,3,5,6,7,8,9,10};

    int missingNum = N;
    findOneMissingNum(missingNum, arr, N);
    if(missingNum != -1)
      {
	cout << "missing num is : " << missingNum << "\n";
      }       
  }
  
  void TestQ2()
  {
    int N = 11;
    int arr[] = {0,1,2,3,4,4,5,6,7,8,9};

    int duplicateNum = 0;
    findOneDuplicateNum(duplicateNum, arr, N);
    if(duplicateNum != 0)
      {
	cout << "duplicate number is : " << duplicateNum << "\n";
      }       
  }
  
  void TestQ3()
  {
    int N = 11;
    int arr[] = {0,1,2,63,64,4,5,6,7,8,9};

    int maxNum = 0, minNum = 0;
    findTheLargestNSmallestNum(maxNum, minNum, arr, N);
    cout << "max : " << maxNum << " min: " << minNum << "\n";
  }

  void TestQ4()
  {
    int N = 11;
    int arr[] = {0,1,2,63,64,4,5,6,7,8,9};

    sort(arr, arr+N);
    int count = 0;
    int sum = 17;
    findAllPairsSumEqNum(count, arr, N, sum);
    cout << "count : " << count << "\n";
  }  

  void TestQ5()
  {
    int N = 11;
    int arr[] = {6,4,2,3,3,4,5,6,7,8,9};

    findMultiDuplicatesInArr(arr, N);
  }  
 
  
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.TestQ0();
   //s.TestQ1();
   //s.TestQ2();
   //s.TestQ3();
   //s.TestQ4();
   s.TestQ5();
   
  return 0;
}
