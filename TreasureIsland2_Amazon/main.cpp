//TREASURE ISLAND I
//You have a map that marks the locations of treasure islands. Some of the map area has jagged rocks and dangerous reefs. Other areas are safe to sail in.
// There are other explorers trying to find the treasure. So you must figure out a shortest route to one of the treasure islands.

//Assume the map area is a two dimensional grid, represented by a matrix of characters.
// You must start from one of the starting point (marked as S) of the map and can move one block up, down, left or right at a time.
//The treasure island is marked as X.
// Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks.
// You cannot leave the map area. Other areas O are safe to sail in. Output the minimum number of steps to get to any of the treasure islands.

//Example:

//Input:
//[['S', 'O', 'O', 'S', 'S'],
// ['D', 'O', 'D', 'O', 'D'],
// ['O', 'O', 'O', 'O', 'X'],
// ['X', 'D', 'D', 'O', 'O'],
// ['X', 'D', 'D', 'D', 'O']]

//Output: 3
//Explanation:
//You can start from (0,0), (0, 3) or (0, 4). The treasure locations are (2, 4) (3, 0) and (4, 0).
//Here the shortest route is (0, 3), (1, 3), (2, 3),
//Here the shortest route is (0, 3), (1, 3), (2, 3), (2, 4).  
//

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define N 5


class Solution
{

  
public:

  void dijkstra(int src, int dist[], int parent[], char grid[N][N])
  {

    int V_N = N*N;
    
    bool sptSet[V_N];

    for( int i = 0; i < V_N; i++)
      {
	dist[i] = INT_MAX;
	sptSet[i] = false;
	parent[i] = -1;
      }

    dist[src] = 0;
    
    for( int i = 0; i < V_N -1 ; i++)
      {
	int u = minDistance(dist, sptSet, V_N);
	sptSet[u] = true;
	

        for (int v = 0; v < V_N; v++)
	  {  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v]
	    int gridUV = 1;
	    bool bGridUV = false;
	    getDistanceAndBool(grid, u, v, gridUV, bGridUV );
	    
            if (!sptSet[v] && bGridUV && dist[u] != INT_MAX && dist[u] + gridUV < dist[v])
	      {
                dist[v] = dist[u] + gridUV;
		parent[v] = u;
	      }
	  }
      }
  }
  
  int minDistance( int dist[], bool sptSet[], int V_N)
  {
    // Initialize min value
    int min = INT_MAX, min_index;

    for(int v = 0; v < V_N; v++)
    {
      if(sptSet[v] == false && dist[v] <= min)
	{
	  min = dist[v];
	  min_index = v;
	}
    }

  return min_index;
 }

  void getDistanceAndBool(char grid[N][N], int u, int v,  int& dist, bool& bGridUV )
  {
 
    int i1 = u/N;
    int j1 = u%N;

    int i2 = v/N;
    int j2 = v%N;

    if( ((i1 == i2) && ((j2 == j1+1) || (j2 == j1-1))) || ( (j1==j2) && ((i2 == i1-1)||(i2==i1+1)) ))
      {
	if( grid[u][v] == 'D' || grid[u][v] == 'S')
	  {
	    bGridUV = false;
	    dist = 0;
	  }
	else
	  {
	    bGridUV = true;
	    dist = 1;
	  }
      }
    else
      {
	bGridUV = false;
	dist = 0;
      }

    if(bGridUV)
      {
	//cout << "u, v is true";
      }
  }

// A utility function to print the constructed distance array 
  void printSolution(int distMin, int parent[], int V_N, int indexTreasure, int iSrcMin, int jSrcMin) 
  { 
    cout << " step: " <<  distMin << " ";
    printPath(parent, indexTreasure, iSrcMin, jSrcMin);
  }  

 // Function to print shortest 
// path from source to j 
// using parent array 
  void printPath(int parent[], int j, int iSrcMin, int jSrcMin) 
{ 
      
    // Base Case : If j is source 
    if (parent[j] == - 1)
      {
	printf("(%d,%d) ",iSrcMin, jSrcMin);
	return;
      }

    printPath(parent, parent[j], iSrcMin, jSrcMin);

    int ii = j/N;
    int jj = j%N;
    cout << " (" << ii << ","<<jj << ") ";
}  

 
  void testTreasureIsland2()
  {
    char grid[N][N] = {{'S', 'O', 'O', 'S', 'S'},
			 {'D', 'O', 'D', 'O', 'D'},
			 {'O', 'O', 'O', 'O', 'X'},
			 {'X', 'D', 'D', 'O', 'O'},
			 {'X', 'D', 'D', 'D', 'O'}};

    vector<pair<int,int>> sPnts;
    vector<pair<int,int>> xPnts;

    for( int i = 0; i < N; i++)
      {
	for( int j = 0; j < N; j++)
	  {
	    if(grid[i][j] == 'S')
	      {
		sPnts.push_back({i,j});
	      }
	    if(grid[i][j] == 'X')
	      {
		xPnts.push_back({i,j});
	      }
	  }
      }

    int V_N = N*N;
    
    int distMin = INT_MAX;
    int iSrcMin, jSrcMin;
    int iTMin, jTMin;
    int parentMin[V_N];
    
    int dist[V_N];
    int parent[V_N];

    for(auto it = sPnts.begin(); it != sPnts.end(); ++it)
      {
	int srcIndex = it->first*N + it->second;
	dijkstra(srcIndex, dist, parent, grid);

	for(auto itX = xPnts.begin(); itX != xPnts.end(); ++itX)
	  {
	    int indexTreasure = itX->first*N + itX->second; 	
	    if(distMin > dist[indexTreasure])
	      {
		iSrcMin = it->first;
		jSrcMin = it->second;
		iTMin = itX->first;
		jTMin = itX->second;
		distMin = dist[indexTreasure];
		copy(parent, parent+V_N, parentMin);
	      }
	  }
      }
    printSolution(distMin, parent, V_N, iTMin*N+jTMin, iSrcMin, jSrcMin );
    cout<<endl;
  }


  
};


int main(int argc, char* argv[] )
{
  Solution s;
  s.testTreasureIsland2();

  return 0;
}
