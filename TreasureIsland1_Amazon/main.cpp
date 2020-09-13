//
//TREASURE ISLAND I
//You have a map that marks the location of a treasure island. Some of the map area has jagged rocks and dangerous reefs.
//Other areas are safe to sail in.
//There are other explorers trying to find the treasure. So you must figure out a shortest route to the treasure island.
//Assume the map area is a two dimensional grid, represented by a matrix of characters.
//You must start from the top-left corner of the map and can move one block up, down, left or right at a time.
//The treasure island is marked as ‘X’ in a block of the matrix. ‘X’ will not be at the top-left corner.
//Any block with dangerous rocks or reefs will be marked as ‘D’. You must not enter dangerous blocks. You cannot leave the map area.
//Other areas ‘O’ are safe to sail in. The top-left corner is always safe.
//Output the minimum number of steps to get to the treasure.
//e.g.
//Input
//[
//[‘O’, ‘O’, ‘O’, ‘O’],
//[‘D’, ‘O’, ‘D’, ‘O’],
//[‘O’, ‘O’, ‘O’, ‘O’],
//[‘X’, ‘D’, ‘D’, ‘O’],
//]

//Output from aonecode.com
//Route is (0, 0), (0, 1), (1, 1), (2, 1), (2, 0), (3, 0) The minimum route takes 5 steps.// this is the


#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define N 4

class Solution
{

  
public:
  void dijkstra(char grid[N][N])
  {

    int V_N = N*N;
    
    // top-left corner
    pair<int, int>  startPnt{0,0};
    int iTreasure, jTreasure;
    for( int i = 0; i < N; i++)
      {
	for( int j = 0; j < N; j++)
	  {
	    if(grid[i][j] == 'X')
	      {
		iTreasure = i;
		jTreasure = j;
	      }
	  }
      }

    pair<int, int> targetPnt{iTreasure, jTreasure};
    int indexTreasure= iTreasure*N+jTreasure;

    // cout << " get shortest path from: "<<startPnt.first << "," << startPnt.second  << " to " << targetPnt.first << "," << targetPnt.second << endl;  
    
    int dist[V_N];
    bool sptSet[V_N];
    int parent[V_N];
    map<int, vector<pair<int,int>>> paths;

    for( int i = 0; i < V_N; i++)
      {
	dist[i] = INT_MAX;
	sptSet[i] = false;
	parent[i] = -1;
      }

    dist[0] = 0;
    
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
		//paths[i].push_back({u,v});
		parent[v] = u;
	      }
	  }
      }
    
    // print the constructed distance array 
    printSolution(dist, parent, V_N, indexTreasure);
    // printPaths(paths, V_N);

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

    //    cout << u << " : " << v << " : " << " : " << i1 << " : " << j1 << " : " << i2 << " : " << j2 << endl;

    if( ((i1 == i2) && ((j2 == j1+1) || (j2 == j1-1))) || ( (j1==j2) && ((i2 == i1-1)||(i2==i1+1)) ))
      {
	if( grid[u][v] == 'D')
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
  void printSolution(int dist[], int parent[], int V_N, int indexTreasure) 
  { 
   
    cout << " step: " <<  dist[indexTreasure] << " ";
    printPath(parent, indexTreasure);
    
    //printf("Vertex \t\t Distance from Source\n");
    //for (int i = 0; i < V_N; i++)
    //  {
    //    printf("%d \t\t %d\n", i, dist[i]);

    //	cout << "(0,0)";
    //	printPath(parent, i); 
    //  }    
  }  

 // Function to print shortest 
// path from source to j 
// using parent array 
void printPath(int parent[], int j) 
{ 
      
    // Base Case : If j is source 
    if (parent[j] == - 1)
      {
	cout << " (0,0) ";
	return;
      }

    printPath(parent, parent[j]);

    int ii = j/4;
    int jj = j%4;
    cout << " (" << ii << ","<<jj << ") ";

    //printf("%d ", j); 
}  

  void printPaths(map<int, vector<pair<int,int>>> paths, int V_N) 
  { 
    printf("Vertex \t\t pathes from Source\n"); 
    for (auto it = paths.begin(); it != paths.end(); it++)
      {
	cout << it->first << ":\n";
        vector<pair<int,int>> temp = it->second;
	for(auto it1 = temp.begin(); it1 != temp.end(); it1++)
	  {
	      cout << "(" << it1->first << "," << it1->second << ")";
	  }
	cout << endl;
      }
    
  }  
 
  void testTreasureIsland1()
  {
      char  grid[N][N] = {{'O','O','O','O'},
    		          {'D','O','D','O'},
    		          {'O','O','O','O'},
    		          {'X','D','D','O'}};
      dijkstra(grid);
  }
  
  void testTreasureIsland2()
  {
    vector<vector<int>> grid{{1,1,0,0,0},
			     {1,1,0,0,0},
			     {0,0,1,0,0},
			     {0,0,0,1,1}};
    //cout << numIslands(grid) << endl;
  }
  
};


int main(int argc, char* argv[] )
{
  Solution s;
  s.testTreasureIsland1();
  //s.testCase2();

  return 0;
}
