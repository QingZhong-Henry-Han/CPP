// this is the routine for graph component

#include <bits/stdc++.h>

using namespace std;

class Graph
{
  int numVertex;
  int numEdge;

  list<int>*           m_adjL;
  vector<vector<int>>  m_adjVV;

  //Adjacent matrix
  int** m_adjM;
  
public:
  Graph(int v );
  Graph(int v, int e);
  
  virtual ~Graph();

  // A utility function to add an edge in an 
  // undirected graph. 
  void addEdgeVV(int v, int w);
  void addEdgeL(int u, int v);
  void addEdgeM(int start, int e);

  void DFSUtilList(list<int>* adjL, int v, bool visited[]); 
  void DFSList(list<int>* adjL, int v); 
  void DFSUtilVV(vector<vector<int>> adjVV, int v, bool visited[]); 
  void DFSVV(int v, vector<int>& comp, bool* visited); 
  void BFSVV(vector<vector<int>> adjVV, int start);
  void ConnectedComponents();

  // A utility function to print the adjacency list 
  // representation of graph 
  void printGraphVV() 
  {
    int index = 1;
    for (auto it = m_adjVV.begin(); it != m_adjVV.end(); ++it) 
     { 
         cout << "\n Adjacency list of vertex " << index << "\n head "; 
         for (auto it1 = it->begin(); it1 != it->end(); ++it1)
	   {
	     cout << "-> " << *it1;
	   }
	 index++;
         printf("\n"); 
     } 
  }
  
  void printGraphL(list<int>* adjL, int V) 
  { 
     for (int v = 0; v < numVertex ; ++v) 
     {
       cout << "\n Adjacency list of vertex " << v+1 << "\n head "; 
       for(auto it =  adjL->begin(); it != adjL->end(); it++)
	 {
           cout << "-> " << *it; 
	 }
         printf("\n");
     } 
  }

  void printGraphM(int** adjM, int V, int E) 
  { 
     for (int v = 0; v < numVertex; ++v) 
     {
       cout << "\n Adjacency list of vertex " << v << "\n head "; 
       for(int e = 0; e < numEdge; ++e)
	 {
           cout << "-> " << adjM[v][e]; 
	 }
         printf("\n");
     } 
  }
 
};

// Function to fill the list
Graph::Graph(int v )
{
  this->numVertex = v;
  m_adjL = new list<int>[numVertex];
}

// Function to fill the empty adjacency matrix 
Graph::Graph(int v, int e) 
{ 
    this->numVertex = v; 
    this->numEdge = e;
    // for vector<vector<int>>
    for(int row = 0; row < numVertex; row++)
      {
	m_adjVV.push_back(vector<int>());
      }
    
    // for matrix solution
    m_adjM = new int*[numVertex]; 
    for (int row = 0; row < numVertex; row++) { 
        m_adjM[row] = new int[numEdge]; 
        for (int column = 0; column < numVertex; column++) { 
            m_adjM[row][column] = 0; 
        } 
    } 
}

Graph::~Graph(){}

void Graph::addEdgeVV(int u, int v) 
{
  m_adjVV[u].push_back(v); 
  m_adjVV[v].push_back(u); 
}

void Graph::addEdgeL(int u, int v)
{
  m_adjL[u].push_back(v);
}

//Function to add an edge to the graph
void Graph::addEdgeM(int start, int e)
{
  // Considering a biDirection edge
  m_adjM[start][e] = 1;
  m_adjM[e][start] = 1;  
}

//DFSUtilList function
void Graph::DFSUtilList(list<int>* adjL, int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adjL[v].begin(); i != adjL[v].end(); ++i) 
        if (!visited[*i]) 
	  DFSUtilList(adjL, *i, visited); 
} 
  
// DFSList traversal of the vertices reachable from v. 
// It uses recursive DFSUtilList() 
void Graph::DFSList(list<int>* adjL, int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[numVertex]; 
    for (int v = 0; v < numVertex; v++) 
        visited[v] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtilList(adjL, v, visited); 
}

//DFSUtilVV function
void Graph::DFSUtilVV(vector<vector<int>> adjVV, int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    for (auto it = adjVV.begin(); it != adjVV.end(); ++it)
      {
	for(auto it1 = it->begin(); it1 != it->end(); ++it1)
	  {
	    if (!visited[*it1]) 
	      DFSUtilVV(adjVV, *it1, visited);
	  }
      }
} 
  
// DFSVV traversal of the vertices reachable from v. 
// It uses recursive DFSUtilVV() 
void Graph::DFSVV(int v, vector<int>& comp, bool* visited) 
{
    visited[v] = true;
    comp.push_back(v);
    // Call the recursive helper function 
    // to print DFS traversal
    for(int i = 0; i < m_adjVV[v].size(); i++)
      {
	int to = m_adjVV[v][i];
	if(!visited[to])
	  {
	    DFSVV(to, comp, visited);
	  }
      }
}

// Function to perform BFS on the graph 
void Graph::BFSVV(vector<vector<int>> adjVV, int start) 
{ 
    // Visited vector to so that 
    // a vertex is not visited more than once 
    // Initializing the vector to false as no 
    // vertex is visited at the beginning 
    vector<bool> visited(numVertex, false); 
    vector<int> q; 
    q.push_back(start); 
  
    // Set source as visited 
    visited[start] = true; 
  
    int vis; 
    while (!q.empty()) { 
        vis = q[0]; 
  
        // Print the current node 
        cout << vis << " "; 
        q.erase(q.begin()); 
  
        // For every adjacent vertex to the current vertex 
        for (int v = 0; v < numVertex; v++)
	  { 
            if (adjVV[vis][v] == 1 && (!visited[v])) { 
  
                // Push the adjacent node to the queue 
                q.push_back(v); 
  
                // Set 
                visited[v] = true; 
            } 
        } 
    } 
} 

//Function to compute the ConnectedComponents
void Graph::ConnectedComponents()
{
  bool visited[numVertex];
  vector<int> components;
  
  for(int v = 0; v < numVertex; v++)
    {
      visited[v] = false;
    }

  for(int v = 0; v < numVertex; v++)
    {
      if(!visited[v])
	{
	  components.clear();
	  DFSVV(v, components, visited);
	  cout << "Components:";

	  for( int c = 0; c < components.size(); c++)
	    {
	      cout << " " << components[c];		
	    }
	  cout << endl;	  
	}
    }
}


int main(int argc, char* argv[] )
{
  // test cases
  int numNodes = 5;
  int numEdges = 2;
  Graph G(numNodes, numEdges);
  G.addEdgeVV(0,1);
  G.addEdgeVV(2,3);
  //G.printGraphVV();
  vector<int> comp;
  G.ConnectedComponents();
  

  return 0;
}
