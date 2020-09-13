
//
//K NEAREST POST OFFICES
//Find the k post offices located closest to you, given your location and a list of locations of all post offices available.
//Locations are given in 2D coordinates in [X, Y], where X and Y are integers.
//Euclidean distance is applied to find the distance between you and a post office.
//Assume your location is [m, n] and the location of a post office is [p, q],
//the Euclidean distance between the office and you is SquareRoot((m - p) * (m - p) + (n - q) * (n - q)).
//K is a positive integer much smaller than the given number of post offices. from aonecode.com

//e.g.
//Input
//you: [0, 0]
//post_offices: [[-16, 5], [-1, 2], [4, 3], [10, -2], [0, 3], [-5, -9]]
//k = 3

//Output from aonecode.com
//[[-1, 2], [0, 3], [4, 3]]


// cpp program to demonstrate distance to 
// nearest source problem using BFS 
// from each vertex 
#include <bits/stdc++.h> 
using namespace std; 
#define N 100000 + 1 
#define inf 1000000 

// This array stores the distances of the 
// vertices from the nearest source 
int dist[N]; 

// a hash array where source[i] = 1 
// means vertex i is a source 
int source[N]; 

// The BFS Queue 
// The pairs are of the form (vertex, distance 
// from current source) 
deque<pair<int, int> > BFSQueue; 

// visited array for remembering visited vertices 
int visited[N]; 

// The BFS function 
void BFS(vector<int> graph[], int start) 
{ 
	// clearing the queue 
	while (!BFSQueue.empty()) 
		BFSQueue.pop_back(); 

	// push_back starting vertices 
	BFSQueue.push_back({ start, 0 }); 

	while (!BFSQueue.empty()) { 

		int s = BFSQueue.front().first; 
		int d = BFSQueue.front().second; 
		visited[s] = 1; 
		BFSQueue.pop_front(); 

		// stop at the first source we reach during BFS 
		if (source[s] == 1) { 
			dist[start] = d; 
			return; 
		} 

		// Pushing the adjacent unvisited vertices 
		// with distance from current source = this 
		// vertex's distance + 1 
		for (int i = 0; i < graph[s].size(); i++) 
			if (visited[graph[s][i]] == 0) 
				BFSQueue.push_back({ graph[s][i], d + 1 }); 
	} 
} 

// This function calculates the distance of each 
// vertex from nearest source 
void nearestTown(vector<int> graph[], int n, 
					int sources[], int S) 
{ 

	// reseting the source hash array 
	for (int i = 1; i <= n; i++) 
		source[i] = 0; 
	for (int i = 0; i <= S - 1; i++) 
		source[sources[i]] = 1; 

	// loop through all the vertices and run 
	// a BFS from each vertex to find the distance 
	// to nearest town from it 
	for (int i = 1; i <= n; i++) { 
		for (int i = 1; i <= n; i++) 
			visited[i] = 0; 
		BFS(graph, i); 
	} 

	// Printing the distances 
	for (int i = 1; i <= n; i++) 
		cout << i << " " << dist[i] << endl; 
} 

void addEdge(vector<int> graph[], int u, int v) 
{ 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
} 

// Driver Code 
int main() 
{

//you: [0, 0]
//post_offices: [[-16, 5], [-1, 2], [4, 3], [10, -2], [0, 3], [-5, -9]]
//k = 3


  // Number of vertices 
	int n = 6; 

	vector<int> graph[n + 1]; 

	// Edges 
	addEdge(graph, 1, 2); 
	addEdge(graph, 1, 6); 
	addEdge(graph, 2, 6); 
	addEdge(graph, 2, 3); 
	addEdge(graph, 3, 6); 
	addEdge(graph, 5, 4); 
	addEdge(graph, 6, 5); 
	addEdge(graph, 3, 4); 
	addEdge(graph, 5, 3); 

	// Sources 
	int sources[] = { 1, 5 }; 

	int S = sizeof(sources) / sizeof(sources[0]); 

	nearestTown(graph, n, sources, S); 

	return 0; 
} 
