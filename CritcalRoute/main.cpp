// this is to solve critical route problem
//
// algorithm
//
// undirected graph
//
// In a graph, a vertex is called an articulation point if removing it and
// all the edges associated with it results in the increase of the number of connected components in the graph.
//
// find bridge


#include <bits/stdc++.h>

using namespace std;

typedef std::vector<std::pair<int,int>> EdgesType;

void printVisitedStatus(int v, bool* visited, int numNodes);
void DFSIterative(int node, EdgesType edges, bool* visited);
void DFSRecursive(int node, EdgesType edges, bool* visited);
//void BFS(int node, int numNodes, EdgesType edges, bool* visited, int* level);
std::set<int> findArticulationPointsBruteForce(EdgesType edges, int numNodes, int numEdges);
void AP(int numNodes, std::list<int>* pEdgesList);
void findArtPoint(int v, std::list<int>* pEdgesList, bool visited[], int disc[], int low[], int parent[], bool ap[]);
void BR(int numNodes, std::list<int>* pEdgesList);

//void BreadthFirstSearch(std::vector<std::pair<int,int>> edges, int vStart, int& nDistance, bool* visited);
//std::vector<int>  findArticulationPoints(EdgesType edges, int numNodes, int numEdges);

int main(int argc, char *argv[])
{
  int numNodes = 7;
  int numEdges = 7;
  EdgesType edges ={{0,1},{0,2},{1,3},{2,3},{2,5},{5,6},{3,4}};

  std::list<int>* pEdgeList = new std::list<int>[numNodes];

  for(auto it = edges.begin(); it != edges.end(); it++)
    {
      pEdgeList[it->first].push_back(it->second);
      pEdgeList[it->second].push_back(it->first);
    }

  //#define _AP_
  
#ifdef _AP_
  
  std::cout << " begin AP: \n";
  AP(numNodes, pEdgeList);
  std::cout << "\n end of AP \n";
#endif

  #define _BRIDGE_
#ifdef _BRIDGE_

  //EdgesType brEdges = {{0,1},{0,5},{1,2},{2,3},{3,4}};
  // std::list<int>* pBREdgeList = new std::list<int>[6];
  //EdgesType brEdges = {{0,1},{1,2},{2,3},{3,4},{4,1}};
  //std::list<int>* pBREdgeList = new std::list<int>[5];
   EdgesType brEdges = {{0,1},{0,2},{1,2},{2,3}};
   std::list<int>* pBREdgeList = new std::list<int>[4];
  
  for(auto it = brEdges.begin(); it != brEdges.end(); it++)
    {
      pBREdgeList[it->first].push_back(it->second);
      pBREdgeList[it->second].push_back(it->first);
    }
  
  std::cout << " begin Bridge: \n";
  //BR(6, pBREdgeList);
  // BR(5, pBREdgeList);
  numNodes = 4;
  BR(numNodes, pBREdgeList);
  std::cout << "\n end Bridge: \n";
#endif

#ifdef  _AP_BRUTE_FORCE_
  
  std::cout << "Brute Force results: \n";
  std::set<int> results = findArticulationPointsBruteForce(edges, numNodes, numEdges);
  for(auto it = results.begin(); it != results.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";

#endif
  
  return 0;
}

void printVisitedStatus(int v, bool* visited, int numNodes)
{
  for( int i =0; i < numNodes; i++)
    {
      std::cout << visited[i] << " ";
    }
  std::cout << "end of " << v <<  " visited status \n";
}

// iterative methods
void DFSIterative(int node, EdgesType edges, bool* visited)
{
  //first set this node visted
  if(visited[node])
    {
      return;
    }
  else
    {
      visited[node] = true;
    }
  
  //keep the next level children
  std::stack<int> S;
  for(auto it = edges.begin(); it != edges.end(); it++)
    {
      if(it->first == node && !visited[it->second])
	{
	  S.push(it->second);
	}
      else if(it->second == node && !visited[it->first])
	{
	  S.push(it->first);
	}
	
    }

  while(!S.empty())    
    {
      DFSIterative(S.top(), edges, visited);
      S.pop();
    }
}

// recursive methods
void DFSRecursive(int node, EdgesType edges, bool* visited)
{
  //first set this node visted
  if(visited[node])
    {
      return;
    }
  else
    {
      visited[node] = true;
    }
  //keep the next level children
  std::list<int> L;
  for(auto it = edges.begin(); it != edges.end(); it++)
    {
      if(it->first == node && !visited[it->second])
	{
	  L.push_back(it->second);
	}
      else if (it->second == node && !visited[it->first])
	{
	  L.push_back(it->first);
	}
    }

  for( auto it = L.begin(); it != L.end(); it++)    
    {
      DFSRecursive(*it, edges, visited);
    }  
}

 // brute force throem
// step 1:  remove v from the edges:
// step 2:  test if v+1 can access all vertex
// if not,  v is articulate vertex
// The follow algorithm iterates over all the vertices
// and in one iteration applies a Depth First Search to find connected components,
// so time complexity of above algorithm is O(Vx(V+e)),
// where V is the number of vertices and E is the number of edges in the graph.
std::set<int> findArticulationPointsBruteForce(EdgesType edges, int numNodes, int numEdges)
{
  std::set<int> results;
  int totalEdges = edges.size();
  bool visited[numNodes];

  for( int v = 0; v < numNodes; v++)
    {
      // step 1
       EdgesType newEdges;
       for( auto it = edges.begin(); it != edges.end();  it++)
	 {
	   if(it->first != v && it->second != v)
	     {
	       newEdges.push_back(*it);
	     }
	 }
       
       for(int i = 0; i < numNodes; i++)
	 {
	   visited[i] = false;
         }
       
       int vTest = v+1;
       if(vTest >= numNodes)
	 {
	   vTest -= 2;
	 }
       
       DFSIterative(vTest, newEdges, visited);
	  
       for( int i = 0; i < numNodes; i++)
	 {
	     if( (i != v) && !visited[i])
	     {
	       results.insert(v);
	     }
	 }
    }
  return results;
}


// a linked list store the vertex
// Given a DFS tree of a graph, a Back Edge is an edge that connects a vertex to a vertex that is discovered before it's parent.
// back edge
//
// analysis; O(V+E)
void AP(int numNodes, std::list<int>* pEdgesList)
{
  // mark all the vertices as not visited
  bool *visited = new bool[numNodes];
  int  *disc    = new int[numNodes];
  int  *low     = new int[numNodes];
  int  *parent  = new int[numNodes];
  bool *ap      = new bool[numNodes];

  // initialize parent and visited, and articulation point arrays
  for( int i = 0; i < numNodes; i++)
    {
      parent[i] = 0;
      visited[i] = false;
      ap[i] = false;
    }

  // call the recursive helper function to find articulation points
  // in DFS tree rooted with vertex 'v'
    for(int v = 0; v < numNodes; v++)
    {
      if(!visited[v])
	{
	  findArtPoint(v, pEdgesList, visited, disc, low, parent, ap);
	}
    }

  // print out the results
  for( int i = 0; i < numNodes; i++ )
    {
      if(ap[i] == true)
	{
	  std::cout << i << " ";
	}
    }
}

void findArtPoint(int v, std::list<int>* pEdgeList, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
  static int time = 0;

  // count of children in DFS tree
  int children = 0;

  //mark the current node as visited
  visited[v] = true;

  // initialize discovery time and low value
  disc[v] = low[v] = ++time;

  //std::cout<<"started v = " << v << " visited = " << visited[v] << " disc: "<< disc[v] << " low: " << low[v] << "\n"; 


  // go through all vertices adjacent to this vertex
  for(auto it = pEdgeList[v].begin(); it != pEdgeList[v].end(); ++it)
    {
      int u = *it;

      //if u is not visited yet, then make it a child of V in DFS tree and recur for it
      if(!visited[u])
	{
	  children++;
	  parent[u] = v;

	  findArtPoint(u, pEdgeList, visited, disc, low, parent, ap);
	  //std::cout << "after children = " << children << " u= " << u << " low= " << low[u] <<"\n"; 

	  // check if the subtree rooted with u has a connection to one of the ancestors of v
	  low[v] = std::min(low[v], low[u]);

	  // u is an articulation point in the following cases
	  if(parent[v] == 0 && children > 1)
	    {
	      //std::cout << "cond 1: " << v << " children: "<< children << "\n";
	      ap[v] = true;
	    }

	  //(2) if v is not root and low value of one of its child is more than discovery value of v
	  if(parent[v] != 0 && low[u] >= disc[v])
	    {
	      //std::cout << "cond 2: " << v << " children: "<< children << " low " << low[u] << " d " << disc[v] << "\n";
	      ap[v] = true;
	    }	  
	}
      //update low value of v for parent function calls
      else if(u != parent[v])
	{
	  low[v] = std::min(low[v], disc[u]);
	  //std::cout << "v = " << v << " low " << low[v] << "  disc " << disc[v] << "\n";
	  //std::cout << "u = " << u << " low " << low[u] << "  disc " << disc[u] << "\n";
	}
    }
}

// An edge in a graph between vertices say  and  is called a Bridge,
// if after removing it, there will be no path left between v and u
// sudo function
//int dfsBR(int u, int p) {
//  low[u] = disc[u] = ++Time;
//  for (int& v : adj[u]) {
//    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
//    if (!disc[v]) { // if V has not been discovered before
//      dfsBR(v, u);  // recursive DFS call
//      if (disc[u] < low[v]) // condition to find a bridge
//        br.push_back({u, v});
//      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
//    } else // if v was already discovered means that we found an ancestor
//      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
//  }
//}
//time = 0
//function DFS(adj[][], disc[], low[], visited[], parent[], vertex, n)
//        visited[vertex] = true
//        disc[vertex] = low[vertex] = time+1
//        child = 0
//        for i = 0 to n
//                if adj[vertex][i] == true
//                        if visited[i] == false
//                                child = child + 1
//                                parent[i] = vertex
//                                DFS(adj, disc, low, visited, parent, i, n, time+1)
//                                low[vertex] = minimum(low[vertex], low[i])
//                                if low[i] > disc[vertex]
//                                        print vertex, i
//                        else if parent[vertex] != i
//                                low[vertex] = minimum(low[vertex], disc[i])
  
void dfsBR(int v, bool* visited, list<int>* pEdgeList, int* parent, vector<int>& disc, vector<int>& low,  vector<pair<int,int>>& bridges)
{

  static int time = 0;

  visited[v] = true;

  // count of children in DFS tree
  int children = 0;
  
  // initialize discovery time and low value
  disc[v] = low[v] = ++time;

  // go through all vertices adjacent to this vertex
  for(auto it = pEdgeList[v].begin(); it != pEdgeList[v].end(); ++it)
    {
      int u = *it;

      //if u is not visited yet, then make it a child of V in DFS tree and recur for it
      if( !visited[u] )
	{
	  children++;
	  parent[u] = v;
	  dfsBR(u, visited, pEdgeList, parent, disc, low, bridges);

	  low[v] = min(low[v], low[u]);
	  // if this condition met, this means a bridge
	  if( low[u] > disc[v])
	  {
	    bridges.push_back({u, v});
	  }
	}
      else if(parent[v] != u)
	{
	  low[v] = min(low[v], disc[u]);
	}
    }
}


// a linked list store the vertex
// Given a DFS tree of a graph, a Back Edge is an edge that connects a vertex
//  to a vertex that is discovered before it's parent.
// analysis; O(V+E)
//void BR() {
//  low = disc = vector<int>(adj.size());
//  Time = 0;
//  for (int u = 0; u < adj.size(); u++)
//    if (!disc[u])
//      dfsBR(u, u)
//}


void BR(int numNodes, std::list<int>* pEdgesList)
{
  vector<int>  disc(numNodes);
  vector<int>  low(numNodes);
  bool *visited = new bool[numNodes];
  int  *parent  = new int[numNodes];


  vector<pair<int,int>> bridges;

  dfsBR(0, visited, pEdgesList, parent, disc, low, bridges);

  // print out the results
    for( auto it = bridges.begin(); it != bridges.end(); it++ )
    {
      std::cout << it->first << " - " << it->second << " : ";
    }
}
