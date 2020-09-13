// dynamic programming
// look for longest common substring in two string
//
// knapsack problem
//
//given a set of items, each with a weight and a value,
//determine the number of each item to include in a collection
//so that the total weight is less than or equal to a given limit
// and the total value is as large as possible

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // find longest common substring
  int LCS(string s1, string s2, string& sResult)
  {
    int n = s1.length() + 1;
    int m = s2.length() + 1;

    int nm[n][m];

    for(int i = 0; i <  n; i++)
      {
	nm[i][0] = 0; 
      }
    
    for( int j =0; j < m; j++)
      {
	nm[0][j] = 0;
      }

    
    //fill the rest of the matrix
    for(int i = 1; i < n; i++)
      {
	for(int j = 1; j < m; j++)
	{
	if( s1[i-1] == s2[j-1] )
	  {
	    nm[i][j] =  nm[i-1][j-1] +1;
	  }
	else
	  {
	    nm[i][j] = 0;
	  }
	}
      }

    printNM(s1, s2, (int*)nm, n, m);

    int result = -1;
    for(int i = 0; i < n; i++)
      {
	for(int j = 0; j < m; j++)
	  {
	    if(result < nm[i][j])
	      {
		result = nm[i][j];
	      }
	  }
      }
    
    return result;
  }

  // knapsack problem
  void Knapsack(int wt[], int val[], int n, int w)
  {
        // Populate base cases
        int mat[n + 1][w + 1];
	
        for (int r = 0; r < w + 1; r++)
	  {
            mat[0][r] = 0;
	  }
	
        for (int c = 0; c < n + 1; c++)
	  {
            mat[c][0] = 0;
	  }
        
        //logics
        for (int item = 1; item <= n; item++)
	{
            for (int capacity = 1; capacity <= w; capacity++)
	      {
                int maxValWithoutCurr = mat[item - 1][capacity];
		
		// We initialize this value to 0
                int maxValWithCurr = 0;

		// We use item -1 to account for the extra row at the top
                int weightOfCurr = wt[item - 1];
                if (capacity >= weightOfCurr)
		{
		    // We check if the knapsack can fit the current item
		    // If so, maxValWithCurr is at least the value of the current item
                    maxValWithCurr = val[item - 1];

		    // remainingCapacity must be at least 0
                    int remainingCapacity = capacity - weightOfCurr;

		    // Add the maximum value obtainable with the remaining capacity
                    maxValWithCurr += mat[item - 1][remainingCapacity];
                }

		// Pick the larger of the two
                mat[item][capacity] = max(maxValWithoutCurr, maxValWithCurr);
            }
        }

	cout << "/n output \n";
        cout << mat[n][w];
	cout << "\n"; 
	printMat((int*)mat, n, w);
	
  }

  void printNM(string s1, string s2, int *NM, int n, int m)
  {
    cout << "\n";
    cout << "....";
    for( int i = 0; i < s1.length(); i++)
      {
	cout << s1[i] << " :";
      }
    cout << "\n";
    
    for(int i = 0; i < n; i++)
      {
	if( i > 0 )
	  {
	    cout << s2[i-1] << " :";
	  }
	else
	  {
	    cout << "...";
	  }
	
	for( int j = 0; j < m; j++)
	  {
	    cout << *((NM+i*n) + j) << " :";
	  }
	cout << "\n";
      }
  }
  
  void printMat(int *mat, int n, int w)
  {
    cout << "\n";
    
    for(int i = 0; i <= n; i++)
      {
	for( int j = 0; j <= w; j++)
	  {
	    cout << *((mat+i*(w+1)) + j) << " :";
	  }
	cout << "\n";
      }
  }

  void Test()
  {
    string s1 = "tutorialhorizon";
    string s2 = "dynamictutorialProgramming";
    string sResult;
    cout << "LCS length : " << LCS(s1, s2, sResult) << " : " << sResult << "\n";
  }

  void TestKnapsack()
  {
    int w = 10;
    int n = 4;
    int val[] = {10, 40, 30, 50};
    int wt[]  = {5, 4, 6, 3};
    Knapsack(wt, val, n, w);
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.Test();
   s.TestKnapsack();
   
  return 0;
}
