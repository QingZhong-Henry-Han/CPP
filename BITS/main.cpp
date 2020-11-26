// Algorithm questions:
//
// 1. BITS manipulation
// 2. how to check if a number is power of 2
// 3. check if X nth binary digit is 1 or 1
// 4. Count the number of ones in the binary representation of the given number.
// 5. Check if the ith bit is set in the binary form of the given number.
// 6. How to generate all the possible subsets of a set ?
// 7. Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.


#include <bits/stdc++.h>

using namespace std;

//Given an array of integers. find the maximum XOR subarray value in given array. Expected time complexity O(n).

//Examples:

// input a decimal value and output a binary

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

  // convert int n to a binary
  long long convert(int n)
  {
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0)
    {
        rem = n % 2;
        printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, rem, n / 2);
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
  }

  void testConvertDecimalToBinary()
  {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("%d in decimal = %lld in binary\n", n, convert(n));    
  }

  
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

  // Find the nth digit of a binary of a num
  int findNthDigitOfBinaryOf(int n, int d)
  {
    int nthDigit = 0;

    for( int i = 0; i < n; i++)
      {
	nthDigit = d%2;
	d /=2;
      }

    return nthDigit;
  }

  // check if a x is power of 2
  bool isPowerOf2(int x)
  {
    return  x && !(x & (x-1));
  }

  void TestIsPowerOf2()
  {
    string answer =  isPowerOf2(2) ? "2 is power of 2 " : "2 is not power of 2 ";
    cout << answer << endl;
    answer =  isPowerOf2(6) ? "6 is power of 2 " : "6 is not power of 2 ";
    cout << answer << endl;
  }
      

  // 2) Count the number of ones in the binary representation of the given number.
  void countOnesOfBinaryRepresentation(int x, int& count)
  {
    while( x > 0)
      {
	x = x & (x-1);
	count++;
      }
  }

  void TestCountOnesOfBinaryPresentation()
  {
    int x = 4;
    int count = 0;
    countOnesOfBinaryRepresentation(x, count);
    cout << x << " binary representation has " << count << " 1's" << endl;
    
  }

  //5. Check if the ith bit is set in the binary form of the given number.
  bool check(int N, int i)
  {
    if( N & (1 << i))
      {
	return true;
      }
    else
      return false;
    
  }

  // 6. How to generate all the possible subsets of a set ?
  //   Consider a set A of 3 elements.
  //   A = {a, b, c}
  //   Now, we need 3 bits, one bit for each element. 1 represent that the corresponding element is present in the subset,
  //  whereas 0 represent the corresponding element is not in the subset. Let’s write all the possible combination of these 3 bits.

  void generateAllPossibleSubsets(char A[], int N)
  {
    for(int i = 0; i < 1 << N; i++)
      {
	for(int j = N-1; j >= 0; j--)
	  {
	    if(i & 1 << j )
	      {
		cout << A[N-1-j] << ", ";
	      }
	    else
	      {
		cout << " " << ", ";
	      }
	  }

	cout << "\n";
      }
  }

  void TestGenerateAllPossibleSubsets()
  {
    char A[] = {'A', 'B', 'C'};
    generateAllPossibleSubsets(A,3);
  }

  // 5) Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.
  // Idea: Change all the bits which are at the right side of the most significant digit, to 1.
  // Property: As we know that when all the bits of a number N are 1, then N must be equal to the 2i -1 , where i is the number of bits in N.
  long findLargetPowerOf2(long N)
  {
    N = N | (N >> 1);
    N = N | (N >> 2);
    N = N | (N >> 4);
    N = N | (N >> 8);

    return (N +1) >> 1;
  }

  void TestFindLargestPower()
  {
    cout << " 2 -> " << findLargetPowerOf2(2) << endl;
    cout << " 3 -> " << findLargetPowerOf2(3) << endl;
    cout << " 4 -> " << findLargetPowerOf2(4) << endl;       
  }
};


int main(int argc, char* argv[] )
{
   Solution s;

   s.TestFindLargestPower();

   // s.TestGenerateAllPossibleSubsets();

   //s.TestCountOnesOfBinaryPresentation();
   
   //s.TestFindNthBinaryBit();

   //s.TestIsPowerOf2();
   
   //int n1 = s.findNthDigitOfBinaryOf(1, 75);
   //int n2 = s.findNthDigitOfBinaryOf(2, 75);
   //int n3 = s.findNthDigitOfBinaryOf(3, 75);
   //int n4 = s.findNthDigitOfBinaryOf(4, 75);
   //int n5 = s.findNthDigitOfBinaryOf(5, 75);
   //int n6 = s.findNthDigitOfBinaryOf(6, 75);
   //int n7 = s.findNthDigitOfBinaryOf(7, 75);
   //int n8 = s.findNthDigitOfBinaryOf(8, 75);

   //s.testConvertDecimalToBinary();
   //s.SwapTwoIntegersXor();
   //s.TestCases();

   //   for( int i = 1; i < 5; i++)
   //  {
   //    cout << " i = " << i << " : " << s.findNthMagicNumber(i) << "\n";
   //  }
   
  return 0;
}
