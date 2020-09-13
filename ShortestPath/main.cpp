// this is the routine for graph component
// directed weighted graph 
// 2) shortest path
//     A Dijkstra's is gready algorithms
//     
// 3) program to find Dijkstra's shortest path using STL set
//
//  for V E

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

// program to find Dijkstra's shortest path using STL set
class GraphD
{
  int numVertex;

  list<pair<int, int>> *adj;

public:
  GraphD(int numVertex);

  void addEdge(int u, int v, int w);

  void shortestPath(int s);
  void BellmanFord(int s);
  
};

GraphD::GraphD(int numVertex)
{
  this->numVertex = numVertex;
  adj = new list<pair<int, int>>[numVertex];
}

void GraphD::addEdge(int u, int v, int w)
{
  adj[u].push_back(make_pair(v,w));
  adj[v].push_back(make_pair(u,w));
}

// prints shortest paths from src to all other vertices
void GraphD::shortestPath(int src)
{
  // Create a set to store vertices that are being
  // preprocessed
  set<pair<int,int>> setds;

  // Create a vector for distances and initialize all distances as infinite (INF)
  vector<int> dist(numVertex, INF);

  //Insert source itself in set and initialize its distance as 0
  setds.insert({0,src});
  dist[src] = 0;

   /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty()) 
    { 
        // The first vertex in Set is the minimum distance 
        // vertex, extract it from set. 
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < numVertex; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);   

}

// prints shortest paths from src to all other vertices
void GraphD::BellmanFord(int src)
{
  // Create a set to store vertices that are being
  // preprocessed
  set<pair<int,int>> setds;

  // Create a vector for distances and initialize all distances as infinite (INF)
  vector<int> dist(numVertex, INF);

  //Insert source itself in set and initialize its distance as 0
  setds.insert({0,src});
  dist[src] = 0;

   /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty()) 
    { 
        // The first vertex in Set is the minimum distance 
        // vertex, extract it from set. 
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < numVertex; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);   

}
 

class Graph
{
  int numVertex;
  int numEdge;

  vector<vector<pair<int, int>>> m_adj;
  
  
public:
  Graph(int v );  
  // A utility function to add an edge in an 
  // directed acyclic graph(DAG). 
  void addEdge(int v, int u, int weight);

  void SPUtil(int s, int v, bool* visited, vector<int>& distance );
  void SP(int start);
  
  void printGraph() 
  {
    for( int v = 1; v < numVertex; v++)
      {
	for(auto it =  m_adj[v].begin(); it != m_adj[v].end(); it++)
	  {
	    cout << "-> " << it->first << " d " << it->second << " ;" ;
	  }
	printf("\n");
      }
  }
};

// Function to fill the list
Graph::Graph(int numV )
{
  this->numVertex = numV;
  m_adj.resize(numV);
}

void Graph::addEdge(int v, int u, int weight) 
{
  m_adj[v].push_back(std::pair<int, int>(u, weight));
}

//SPUtil function
void Graph::SPUtil(int s, int v, bool* visited, vector<int>& distance)
{
  for (auto it = m_adj[s].begin(); it != m_adj[s].end(); ++it)
    {
      int u = it->first;
      cout << " -> " << u << " ";
      if(!visited[u])
	{
	  distance[u] += it->second;
	  visited[u] = true;
	  if(u != v)
	    {
	      SPUtil(u, v, visited, distance);
	    }
	}
      else
	{
	  // we are in circle
	}
    }
} 

//Shortest path 
void Graph::SP(int start) 
{
  vector<int> SPResult(numVertex, 0);
    
  // Mark all the vertices as not visited 
  bool *visited = new bool[numVertex];

  for (int v = 0; v < numVertex; v++)
    {
      visited[v] = false;
    }

  int v = 1;
  //for( int v = 1; v < numVertex; v++)
    {
      SPUtil(start, v, visited, SPResult);
    }

  for(int i = 1; i < numVertex; i++)
    {
      cout << SPResult[i]  << "  ";
    }
  cout << "\n";
}

#define V_N  9

// A utility function to find the veretex with minimum distance value,
// from the set of vertices not yet included in shortese path tree

// dist[] --
// sptSet -- shortest path tree set.
// Algorithm for this time complexcity is O(V^2).
//
int minDistance( int dist[], bool sptSet[])
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

// A utility function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V_N; i++) 
        printf("%d \t\t %d\n", i, dist[i]);
    
}

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V_N][V_N], int src) 
{ 
    int dist[V_N]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V_N]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V_N; i++)
      {
        dist[i] = INT_MAX;
	sptSet[i] = false;
      }
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V_N - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V_N; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printSolution(dist); 
} 

int main(int argc, char* argv[] )
{
  //Input V = 5, S = 1
  // arr{{1,2,1},{2,3,7},{2,4,-2},{1,3,8},{1,4,9},{3,4,3},{2,5,3},{4,5,-3}}
  //  int numNodes = 5;
  //  int numEdges = 7;

  //  Graph G(numNodes + 1);
  //  G.addEdge(1,2,1);
  //  G.addEdge(2,3,7);
  //  G.addEdge(2,4,-2);
  //  G.addEdge(1,3,8);
  //  G.addEdge(1,4,9);
  //  G.addEdge(3,4,3);
  //  G.addEdge(2,5,3);
  //  G.addEdge(4,5,-3);

  //G.printGraph();
  //  int start = 1;
  //  G.SP(start);



   // Let us create the example */
  
    int graph[V_N][V_N] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                            { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                            { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                            { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                            { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                            { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                            { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  

			dijkstra(graph, 1);



    // create the graph given in above fugure 
    /*  int V = 9; 
    GraphD gd(V); 
  
    //  making above shown graph 
    gd.addEdge(0, 1, 4); 
    gd.addEdge(0, 7, 8); 
    gd.addEdge(1, 2, 8); 
    gd.addEdge(1, 7, 11); 
    gd.addEdge(2, 3, 7); 
    gd.addEdge(2, 8, 2); 
    gd.addEdge(2, 5, 4); 
    gd.addEdge(3, 4, 9); 
    gd.addEdge(3, 5, 14); 
    gd.addEdge(4, 5, 10); 
    gd.addEdge(5, 6, 2); 
    gd.addEdge(6, 7, 1); 
    gd.addEdge(6, 8, 6); 
    gd.addEdge(7, 8, 7); 
  
    gd.shortestPath(0); 
    */
  return 0;
}
