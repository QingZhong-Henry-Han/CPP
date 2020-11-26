
#include <sys/time.h>
#include <bits/stdc++.h>

using namespace std;

// RadixSort
class RadixSortSolution
{

public:
  // A utility function to get maximum value in arr[] 
  int getMax(int arr[], int n) 
  { 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
      if (arr[i] > max) 
	max = arr[i]; 
    return max; 
  }

  
  // A function to do counting sort of arr[] according to 
  // the digit represented by exp. 
  void countSort(int arr[], int n, int exp) 
  { 
    int output[n]; // output array 
    int i, count[10] = {0}; 
    
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
      {
	cout << i << " arr: " << arr[i] << "  :  " << "exp:"<< exp << " : "  << (arr[i]/exp)%10 << "\n"; 
        count[ (arr[i]/exp)%10 ]++;
      }
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
  }

  
  // The main function to that sorts arr[] of size n using  
  // Radix Sort 
  void radixsort(int arr[], int n) 
  { 
    // Find the maximum number to know number of digits 
    int max = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; max/exp > 0; exp *= 10)
      {
        countSort(arr, n, exp);
    static int iteration = 0;
    if(iteration == 0)
      {
	print(arr,n);
      }
    iteration++;
	break;
      }
  } 
  
  // A utility function to print an array 
  void print(int arr[], int n) 
  { 
     for (int i = 0; i < n; i++) 
         cout << arr[i] << " "; 
  }

  void Test()
  {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, n);
    cout << "final output: \n";
    print(arr, n);
    cout << "\n";
  }
};


//In a given grid, each cell can have one of three values:

//the value 0 representing an empty cell;
//the value 1 representing a fresh orange;
//the value 2 representing a rotten orange.
//Every minute, any fresh orange that is adjacent (4-directionally)
// to a rotten orange becomes rotten.

//Return the minimum number of minutes that must elapse until no cell has a fresh orange.
//If this is impossible, return -1 instead.


// Example 1
//Input: [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4

//Example 2:

//Input: [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten,
//because rotting only happens 4-directionally.
//Example 3:

//Input: [[0,2]]
//Output: 0
//Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

class FloodFillSolution {
public:
  void printGrid(vector<vector<int>>& grid)
  {
        for(int i = 0; i < grid.size(); i++)
	  {
	    for(int j =0; j < grid[i].size(); j++)
	      {
		cout << grid[i][j];
	      }
	    cout << "\n";
	  }    
  }

  void rottingAdj(vector<vector<int>>& grid, vector<pair<int,int>> rottenGrids)
  {
    for(int k = 0; k < rottenGrids.size(); k++)
      {       
	int i = rottenGrids[k].first;
	int j = rottenGrids[k].second;
	grid[i][j] = 2;
      }    
  }

  bool findAnyLeft(vector<vector<int>>& grid)
  {
        for(int i = 0; i < grid.size(); i++)
	  {
	    for(int j =0; j < grid[i].size(); j++)
	      {
		if( grid[i][j] == 1)
		  {
		    return true;
		  }
	      }
	  }    

    return false;
  }
  
  int orangesRotting(vector<vector<int>>& grid)
  {
    int count = 0;
    bool bFinished = true;
      
    do{
        bFinished = true;
	vector<pair<int,int>> rottenOnes;
        for(int i = 0; i < grid.size(); i++)
	  {
	    for(int j =0; j < grid[i].size(); j++)
	      {
		if(grid[i][j] == 2)
		  {
		    //rotten right
		    if( i > 0 && i < grid.size())
		      {
			if(grid[i-1][j] == 1)
			  {
			    rottenOnes.push_back(make_pair(i-1,j));
			    bFinished = false; 
			  }
		      }
		  }
		//
		if(grid[i][j] == 2)
		  {
		    //rotten left
		    if( i >= 0 && i < grid.size()-1)
		      {
			if(grid[i+1][j] == 1)
			  {
			    rottenOnes.push_back(make_pair(i+1,j));
			    bFinished = false; 
			  }
		      }
		  }
		if(grid[i][j] == 2)
		  {
		    //rotten top
		    if( j > 0 && j < grid[i].size())
		      {
			if(grid[i][j-1] == 1)
			  {
			    rottenOnes.push_back(make_pair(i,j-1));
			    bFinished = false; 
			  }
		      }
		  }
		if(grid[i][j] == 2)
		  {
		    //rotten bottom
		    if( j >= 0 && j < grid[i].size()-1)
		      {
			if(grid[i][j+1] == 1)
			  {
			    rottenOnes.push_back(make_pair(i,j+1));
			    bFinished = false; 
			  }
		      }
		  }
	     }
         }
	
	//	if(!bFinished)
	  {
	    count++;
	    //cout << "\n  start of print grid: " << count << "\n";
	    //printGrid(grid);
	    //cout << "\n  end of print grid: " << count << "\n";
    	    rottingAdj(grid, rottenOnes);
	    rottenOnes.clear();
	  }

      }while(!bFinished);

    if(findAnyLeft(grid))
      {
	return -1;
      }
    else
      return count-1;
    }

   void Test()
   {
     vector<vector<int>> e1{{2,1,1},{1,1,0},{0,1,1}};
     cout << orangesRotting(e1) << "\n";
     
     vector<vector<int>> e2{{2,1,1},{0,1,1},{1,0,1}};
     cout << orangesRotting(e2) << "\n";
     
     vector<vector<int>> e3{{0,2}};
     cout << orangesRotting(e3) << "\n";
   }
  
  // The Zombie 
  // Given a 2D grid, each cell is either a zombie 1 or a human 0. Zombies
  // can turn adjacent (up/down/left/right) human beings into zombies every hour.
  // Find out how many hours does it take to infect all humans?
  
  // Input:
  //[[0, 1, 1, 0, 1],
  //[0, 1, 0, 1, 0],
  //[0, 0, 0, 0, 1],
  //[0, 1, 0, 0, 0]]

  //Output: 2
  void zombies(list<list<int>>& grid, list<pair<int, int>> zombieList)
  {
    for( int k = 0; k < zombieList.size(); k++)
      {
	int i = zombieList[k].first;
	int j = zombieList[k].second;
	grid[i][j] = 1;
      }
  }
  
  int minHours(int rows, int columns, list<list<int>> grid)
  {
    int count = 0;
    bool bFinished = true;
    list<pair<int,int>> gridToZombie;
      
    do{

      for(int i = 0; i < rows; i++)
	{
	  for( int j = 0; j < columns; j++)
	    {
	      if(grid[i][j] == 1)
		{
		  if(i > 0 && i < grid[j].size())
		    {
		      if(grid[i-1][j] == 0)
			{
			  gridToZombie.push_back(make_pair(i-1, j));
			}
		    }
		}
	    }
	}

      if(gridToZombie.size() > 0)
	{
	  bFinished = false;
	  count++;
	  zombies(grid, gridToZombie);
	}
      else
	{
	  bFinished = true;
	}

    }while(!bFinished);


    return count;
  }
  
  void TestZombies()
  {
    list<list<int>> g{
		      {0, 1, 1, 0, 1},
		      {0, 1, 0, 1, 0},
		      {0, 0, 0, 0, 1},
		      {0, 1, 0, 0, 0}};
 
    cout << minHours(4, 5, g);

  }
};




int main(void)
{
#ifdef TEST_RADIX_SORT
  RadixSortSolution s;
  s.Test();
#endif

  //#ifdef TEST_FLLODFILL  
  FloodFillSolution s;
  //s.Test();
  s.TestZombies();
  //#endif
  
  return 0;
}

