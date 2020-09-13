// this is the routine for graph Maximum Independent Set
// 1. Simple algorithm
//    a. I empty
//       Assign all vertices to a candidate set of C
//       Veriex v from C is moved into I and all verices adjacent to v are removed from C
//       -> this process is repeated until C is empty.
//       -> this process is inherently serial!


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
  // undirected graph. 
  void addEdge(int u, int v);

  void MISUtil(int v, vector<bool>& visited, set<int>& iSet, set<int>& cSet, vector<int>& levels );
  void MIS(int v);
  
  void printGraph() 
  { 
     for (int v = 0; v < numVertex ; ++v) 
     {
       cout << "\n Adjacency list of vertex " << v << "\n head "; 
       for(auto it =  m_adj[v].begin(); it != m_adj[v].end(); it++)
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

//Maximum Indepedent Set Util function
void Graph::MISUtil(int v, vector<bool>& visited, set<int>& iSet, set<int>& cSet, vector<int>& levels )
{
   visited[v] = true;
 
  //cout << v << " level: ( " << levels[v] << " )  ";
  if(cSet.find(v) != cSet.end())
    {
      iSet.insert(v);
    }
  
  queue<int> Q;  
  for(auto it = m_adj[v].begin(); it != m_adj[v].end(); it++)
    {
      Q.push(*it);
      levels[*it] = levels[v] + 1;
      int nLevel = levels[v] + 1;
      if( nLevel%2 == 1)
	{
	  cSet.erase(*it);
	}
    }

  while(!Q.empty())
    {
      if(!visited[Q.front()])
	{
	  MISUtil(Q.front(), visited, iSet, cSet, levels);
	}
      Q.pop();
    }
}

// Maximum Indepdent Set
void Graph::MIS(int v )
{
  cout << "\n Maximum Indepdent Set of " << v << " \n";
  
  vector<bool> visited(numVertex, false);
  vector<int> levels(numVertex, 0);
  set<int> cSet;
  set<int> iSet;
  for( int index = 0; index < numVertex; index++)
    {
      cSet.insert(index);
    }
  
  MISUtil(v, visited, iSet, cSet, levels);

  for(auto it = iSet.begin(); it != iSet.end(); it++)
    {
      cout << *it << " ";
    }
  cout << "\n end of MIS vertex: " << v << " \n";
}

int main(int argc, char* argv[] )
{
  int numNodes = 10;
  int numEdges = 16;

  Graph G(11);
  
  G.addEdge(0,1);
  G.addEdge(0,4);
  G.addEdge(1,2);
  G.addEdge(1,3);
  G.addEdge(2,7);
  G.addEdge(2,10);
  G.addEdge(3,4);
  G.addEdge(3,6);
  G.addEdge(3,10);
  G.addEdge(4,5);
  G.addEdge(4,6);
  G.addEdge(5,8);
  G.addEdge(6,8);
  G.addEdge(6,10);
  G.addEdge(7,10);
  G.addEdge(7,8);
  G.addEdge(7,9);
  G.addEdge(8,9);

  //G.printGraph();
  G.MIS(0);

  return 0;
}
