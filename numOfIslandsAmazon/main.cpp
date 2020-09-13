// this is the

// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

//Example 1:

//Input:
//11110
//11010
//11000
//00000

//Output: 1
//Example 2:

//Input:
//11000
//11000
//00100
//00011

//Output: 3

#include <bits/stdc++.h>

using namespace std;


class Solution
{
  int N = 4;
  int M = 5;
  
public:
  bool isIland(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
  {
    visited[i][j] = true;
    bool bIMinus1J = false;
    bool bIPlus1J = false;
    bool bJMinus1I = false;
    bool bJPlus1I = false;
    
    if( i > 0)
      {
	if(visited[i-1][j] == false && grid[i-1][j] == 1)
	  {
	    bIMinus1J = isIland(i-1, j, grid, visited);
	  }
	else
	  {
	    bIMinus1J = true;
	  }
      }
    else
      {
	bIMinus1J = true;
      }

    if( i < N-1 )
      {
	if( visited[i+1][j] == false && grid[i+1][j] == 1)
	  {
	    bIPlus1J = isIland(i+1, j, grid, visited);
	  }
	else
	  {
	    bIPlus1J = true;
	  }
      }
    else
      {
	bIPlus1J =  true;
      }

    if( j > 0 )
      {
	if( visited[i][j-1] == false && grid[i][j-1] == 1)
	  {
	    bJMinus1I = isIland(i, j-1, grid, visited);
	  }
	else
	  {
	    bJMinus1I = true;
	  }
      }
    else
      {
	bJMinus1I = true;
      }

    if( j < M-1 )
      {
	if( visited[i][j+1] == false && grid[i][j+1] == 1)
	  {
	    bJPlus1I = isIland(i, j+1, grid, visited);
	  }
	else
	  {
	    bJPlus1I = true;
	  }
      }
    else
      {
	bJPlus1I =  true;
      }
    

    if( bIMinus1J && bIPlus1J && bJMinus1I && bJPlus1I)
      {
	return true;
      }
    else
      {
	if(bIMinus1J)
	  cout << "bIMinus1J" << " : ";
	if(bIPlus1J)
	  cout << "bIPlus1J" << " : ";
	if(bJMinus1I)
	  cout << "bJMinus1I" << " : ";
	if(bJPlus1I)
	  cout << "bJPlus1I" << " : ";
	cout << endl;
      }
    
	
    return false;
  }
  
  int numIslands(vector<vector<int>>& grid)
    {
      vector<vector<bool>> visited{{false, false, false, false, false},
                                   {false, false, false, false, false},
                                   {false, false, false, false, false},
                                   {false, false, false, false, false}};

      int count = 0;
      for( int i = 0; i < N; i++)
	{
	  for( int j = 0; j < M; j++)
	    {
	      if( (grid[i][j] == 1) && (visited[i][j] == false))
		{
		  if(isIland(i, j, grid, visited) == true)
		    {
		      count++;
		    }
		}
	    }
	}

      return count;
    }
  
  void testCase1()
  {
    vector<vector<int>> grid{{1,1,1,1,0},
			     {1,1,0,1,0},
			     {1,1,0,0,0},
			     {0,0,0,0,0}};

    cout << numIslands(grid) << endl;
  }
  
  void testCase2()
  {
    vector<vector<int>> grid{{1,1,0,0,0},
			     {1,1,0,0,0},
			     {0,0,1,0,0},
			     {0,0,0,1,1}};
    cout << numIslands(grid) << endl;
  }
  
};


int main(int argc, char* argv[] )
{
  Solution s;
  s.testCase1();
  s.testCase2();

  return 0;
}
