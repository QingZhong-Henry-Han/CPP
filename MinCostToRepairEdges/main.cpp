//
//Min Cost to Repair Edges (Minimum Spanning Tree II)
//There's an undirected connected graph with n nodes labeled 1..n.
//But some of the edges has been broken disconnecting the graph.
//Find the minimum cost to repair the edges so that all the nodes are once again accessible from each other.

//Input:
//n, an int representing the total number of nodes.
//edges, a list of integer pair representing the nodes connected by an edge.
//edgesToRepair, a list where each element is a triplet representing the pair of nodes between
//which an edge is currently broken and the cost of repearing that edge,
// respectively (e.g. [1, 2, 12] means to repear an edge between nodes 1 and 2, the cost would be 12).

//Example 1:
//Input:
//n = 5, edges = [[1, 2], [2, 3], [3, 4], [4, 5], [1, 5]], edgesToRepair = [[1, 2, 12], [3, 4, 30], [1, 5, 8]]
//Output: 20
//Explanation:
//There are 3 connected components due to broken edges: [1], [2, 3] and [4, 5].
//We can connect these components into a single component by repearing the edges between nodes 1 and 2,
//and nodes 1 and 5 at a minimum cost 12 + 8 = 20.

//Example 2:
//Input:
//n = 6, edges = [[1, 2], [2, 3], [4, 5], [3, 5], [1, 6], [2, 4]], edgesToRepair = [[1, 6, 410], [2, 4, 800]]
//Output: 410

//Example 3:
//Input:
//n = 6, edges = [[1, 2], [2, 3], [4, 5], [5, 6], [1, 5], [2, 4], [3, 4]], edgesToRepair = [[1, 5, 110], [2, 4, 84], [3, 4, 79]]
//Output: 79


// this is the routine for graph component
//What is Minimum Spanning Tree?
//Given a connected and undirected graph, a spanning tree of that graph is a subgraph
//that is a tree and connects all the vertices together.
//A single graph can have many different spanning trees.
//A minimum spanning tree (MST) or minimum weight spanning tree for a weighted,
//connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree.
//The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

//How many edges does a minimum spanning tree has?
//A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.    
//
// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
// of a given connected, undirected and weighted graph 
#include <bits/stdc++.h> 
using namespace std; 

// a structure to represent a weighted edge in graph 
class Edge 
{ 
	public: 
	int src, dest, weight; 
}; 

// a structure to represent a connected, undirected 
// and weighted graph 
class Graph 
{ 
	public: 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	// Since the graph is undirected, the edge 
	// from src to dest is also edge from dest 
	// to src. Both are counted as 1 edge here. 
	Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
Graph* createGraph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

// A structure to represent a subset for union-find 
class subset 
{ 
	public: 
	int parent; 
	int rank; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	// (path compression) 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
int myComp(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 

// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(Graph* graph) 
{ 
	int V = graph->V; 
	Edge result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	// Step 1: Sort all the edges in non-decreasing 
	// order of their weight. If we are not allowed to 
	// change the given graph, we can create a copy of 
	// array of edges 
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	// Allocate memory for creating V ssubsets 
	subset *subsets = new subset[( V * sizeof(subset) )]; 

	// Create V subsets with single elements 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	// Number of edges to be taken is equal to V-1 
	while (e < V - 1 && i < graph->E) 
	{ 
		// Step 2: Pick the smallest edge. And increment 
		// the index for next iteration 
		Edge next_edge = graph->edge[i++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 

		// If including this edge does't cause cycle, 
		// include it in result and increment the index 
		// of result for next edge 
		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		// Else discard the next_edge 
	} 

	// print the contents of result[] to display the 
	// built MST 
	cout<<"Following are the edges in the constructed MST\n";
	int totalWeight = 0;
	for (i = 0; i < e; ++i)
	  {
	    totalWeight += result[i].weight;
	    
		cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
	  }
	printf("\ncost: %d\n", totalWeight);
	return; 
} 

// Driver code 
int main() 
{
 //n = 5, edges = [[1, 2], [2, 3], [3, 4], [4, 5], [1, 5]], edgesToRepair = [[1, 2, 12], [3, 4, 30], [1, 5, 8]]
 //Output: 20
 
	int V = 5; // Number of vertices in graph 
	int E = 5; // Number of edges in graph 
	Graph* graph = createGraph(V, E); 


	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = 12; 

	// add edge 0-4 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 4; 
	graph->edge[1].weight = 0; 

	// add edge 1-2 
	graph->edge[2].src = 1; 
	graph->edge[2].dest = 2; 
	graph->edge[2].weight = 0; 

	// add edge 2-3 
	graph->edge[3].src = 2; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 30; 

	// add edge 3-4 
	graph->edge[4].src = 3; 
	graph->edge[4].dest = 4; 
	graph->edge[4].weight = 8; 

	KruskalMST(graph); 

	return 0; 
} 

