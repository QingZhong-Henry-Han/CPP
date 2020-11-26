// this is the routine for directed graph component
// In the graph there are three common search
//  // task  job scheduling:
//  given directed acyclic graph DAG)
//   order all vertices so that all edges pointer from
//   lower order to high order
// 1) TopologicalSort
//   run DES and output reverse at finishing time.
//  for V E  O(V+E)

#include <bits/stdc++.h>

using namespace std;

class Graph
{
  int numVertex;
  int numEdge;

  list<int>*  m_adj;
  list<int>   m_levels;

  
public:
  Graph(int v );
  
  // A utility function to add an edge in an 
  // directed graph. 
  void addEdge(int v, int u);

  void TSUtil(int v, bool* visited, stack<int>& result );
  void TS();
  
  void printGraph( int v) 
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

void Graph::addEdge(int v, int u) 
{
  m_adj[v].push_back(u); 
}

//TSUtil function, go from high order to lower order
void Graph::TSUtil(int v, bool* visited, stack<int>& result)
{ 
    for (auto it = m_adj[v].begin(); it != m_adj[v].end(); ++it)
     {
       TSUtil(*it, visited, result);
     }

    if (!visited[v])
      {
	visited[v] = true;
	result.push(v);
      }
} 

// Topological sort 
void Graph::TS() 
{
  stack<int> TSResult;
  // Mark all the vertices as not visited 
  bool *visited = new bool[numVertex];

  for (int v = 0; v < numVertex; v++)
    {
      visited[v] = false;
    }
  
  for( int v = 0; v < numVertex; v++)
    {
      TSUtil(v, visited, TSResult);
    }

  while(!TSResult.empty())
    {
      cout << TSResult.top()  << "  ";
      TSResult.pop();
    }
  cout << "\n";
}

int main(int argc, char* argv[] )
{
  int numNodes = 6;
  int numEdges = 6;

  Graph G(6);
  G.addEdge(5,0);
  G.addEdge(5,2);
  G.addEdge(2,3);
  G.addEdge(3,1);
  G.addEdge(4,0);
  G.addEdge(4,1);

  G.TS();
  
  return 0;
}
