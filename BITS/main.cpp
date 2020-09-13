// Algorithm questions:
//
// 1. BITS manipulation
// 

#include <bits/stdc++.h>

using namespace std;

//Given an array of integers. find the maximum XOR subarray value in given array. Expected time complexity O(n).

//Examples:

//Input: arr[] = {1, 2, 3, 4}
//Output: 7
//The subarray {3, 4} has maximum XOR value

//Input: arr[] = {8, 1, 2, 12, 7, 6}
//Output: 15
//The subarray {1, 2, 12} has maximum XOR value

//Input: arr[] = {4, 6}
//Output: 6
//The subarray {6} has maximum XOR value

class Solution
{
  
public:

  int findMinXORValue(int arr[], int N)
  {
    int res_index = 0;

    int curr_xor = 0;
    for(int i = 0; i < N; i++)
      {
	curr_xor ^= arr[i];
      }

    int min_xor = curr_xor;

    // Traverse from   
    // element to n'th element 
    for (int i = 0; i < N; i++) { 
          
        // XOR with current item  
        // and first item of 
        // previous subarray 
        curr_xor ^= (arr[i] ^ arr[i - N]); 
  
        // Update result if needed 
        if (curr_xor < min_xor)
	{ 
            min_xor = curr_xor; 
            res_index = (i - N + 1); 
        } 
    }  
    return min_xor;
  }
  
  int findMaxXORValue(int arr[], int N)
  {
    int res_index = 0;

    int curr_xor = 0;
    for(int i = 0; i < N; i++)
      {
	curr_xor ^= arr[i];
      }

    int max_xor = curr_xor;

    // Traverse from   
    // element to n'th element 
    for (int i = 0; i < N; i++) { 
          
        // XOR with current item  
        // and first item of 
        // previous subarray 
        curr_xor ^= (arr[i] ^ arr[i - N]); 
  
        // Update result if needed 
        if (curr_xor > max_xor) { 
            max_xor = curr_xor; 
            res_index = (i - N + 1); 
        } 
    }  
    return max_xor;
  }

  void TestCases()
  {
    int N = 4;
    int arr[] = {1, 2, 3, 4};
    //Output: 7
    //  The subarray {3, 4} has maximum XOR value
    cout << "min: " <<  findMinXORValue(arr, N) << "\n";
    //    cout << "max: " <<  findMaxXORValue(arr, N) << "\n";
  }

  void SwapTwoIntegersXor()
  {
    int A = 1;
    int B = 20;
    cout << "\nA= " << A << " B= " << B << "\n";
    A = A^B;
    B = A^B;
    A = A^B;
    cout << "A= " << A << " B= " << B << "\n";
  }

  // Find nth Magic Number
  //A magic number is defined as a number
  //which can be expressed as a power of 5 or sum of unique powers of 5.
  //First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….
  //Write a function to find the nth Magic number.
  int findNthMagicNumber(int n)
  {
    int pow = 1, answer = 0; 
  
    // Go through every bit of n 
    while (n) 
    { 
       pow = pow*5; 
  
       // If last bit of n is set 
       if (n & 1) 
         answer += pow; 
  
       // proceed to next bit 
       n >>= 1;  // or n = n/2
    } 
    return answer; 
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.SwapTwoIntegersXor();
   s.TestCases();

   for( int i = 1; i < 5; i++)
     {
       cout << " i = " << i << " : " << s.findNthMagicNumber(i) << "\n";
     }
   
  return 0;
}
