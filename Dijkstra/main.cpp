// this is the routine for graph component
// In the graph there are three common search
// 1) Breadth First Search(BFS) :  each "Level" of the tree is visited in order.
// 2) Depth First Pre-order Search (DFS) : Children nodes are visited before sibling nodes.
// 3) Depth First Post-order Search (DFS) : A node is not visited until all its children are reached.

#include <bits/stdc++.h>

using namespace std;

//#define DEPTHFIRSTSEARCH
#define BREADTHFIRSTSEARCH
#define PREORDER


class Graph
{
  int numVertex;
  int numEdge;

  list<int>*  m_adj;
  list<int>   m_levels;

  
public:
  Graph(int v );
  
  // A utility function to add an edge in an 
  // undirected graph. 
  void addEdge(int u, int v);

  void DFSUtil(int v, bool* visited); 
  void DFS(int v ); 

  void BFSUtil(int v, vector<bool>& visited, vector<int>& levels );
  void BFS(int v);
  
  void printGraph( int V) 
  { 
     for (int v = 0; v < numVertex ; ++v) 
     {
       cout << "\n Adjacency list of vertex " << v << "\n head "; 
       for(auto it =  m_adj->begin(); it != m_adj->end(); it++)
	 {
           cout << "-> " << *it; 
	 }
         printf("\n");
     } 
  }
};

// Function to fill the list
Graph::Graph(int numV )
{
  this->numVertex = numV;
  m_adj = new list<int>[numV];
}

void Graph::addEdge(int u, int v) 
{
  m_adj[u].push_back(v); 
  m_adj[v].push_back(u); 
}

//DFSUtil function
void Graph::DFSUtil(int v, bool* visited) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex
#ifdef PREORDER
    for (auto it = m_adj[v].begin(); it != m_adj[v].end(); ++it)
#else
    for (auto it = m_adj[v].rbegin(); it != m_adj[v].rend(); ++it)
#endif    
      {
	if (!visited[*it])
	  {
	      DFSUtil(*it, visited);
	  }
      }
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive 
void Graph::DFS(int v) 
{ 
    cout << "\n start traversal of " << v  << " \n ";
    // Mark all the vertices as not visited 
    bool *visited = new bool[numVertex]; 
    for (int v = 0; v < numVertex; v++) 
        visited[v] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited);
    cout << "\n finished traversal of " << v  << " \n ";
}

void Graph::BFSUtil(int v, vector<bool>& visited, vector<int>& levels )
{
  visited[v] = true;
  cout << v << " level: ( " << levels[v] << " )  ";
  
  queue<int> Q;  
#ifdef PREORDER  
  for(auto it = m_adj[v].begin(); it != m_adj[v].end(); it++)
#else
  for(auto it = m_adj[v].rbegin(); it != m_adj[v].rend(); it++)
#endif    
    {
      Q.push(*it);
      levels[*it] = levels[v] + 1;
    }

  while(!Q.empty())
    {
      if(!visited[Q.front()])
	{
	  BFSUtil(Q.front(), visited, levels);
	}
      Q.pop();
    }
}

void Graph::BFS(int v )
{
  cout << "\n start of traversal of " << v << " \n";
  vector<bool> visited(numVertex, false);
  vector<int>  levels(numVertex, 0);
  BFSUtil(v, visited, levels);
  cout << "\n end of traversal of " << v << " \n";
}

int main(int argc, char* argv[] )
{
  int numNodes = 7;
  int numEdges = 6;

  Graph G(7);
  G.addEdge(0,1);
  G.addEdge(0,2);
  G.addEdge(1,3);
  G.addEdge(1,4);
  G.addEdge(2,5);
  G.addEdge(2,6);

#ifdef DEPTHFIRSTSEARCH 
  G.DFS(0);
  G.DFS(1);
  G.DFS(2);
#elif defined(BREADTHFIRSTSEARCH)
  G.BFS(0);
  G.BFS(1);
  G.BFS(2);
#endif  

  return 0;
}
