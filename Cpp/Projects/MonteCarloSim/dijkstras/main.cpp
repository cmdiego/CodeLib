/*
	Description:	Edge List (Better for sparse graphs) vs. Adjacency Matrix (better for dense graphs)
					
					A representation of a directed graph maybe represented by having node 'j' in the set for
					node 'i', though not vice versa.

					An undirected graph may be represented by having node 'j' in the set for node 'i' and vice versa.
					The total weight of a path is the sum of the weights of the edges in the path.

					(n): is the number of nodes, (m): is the number of edges

					Edges: (Total number of edges in the graph)	= n * (n-1) / 2
					Degree: (Total number of edges of a node)	= n - 1
					Size: (total number of nodes in the graph)	= n
					Density:
						Undirected graphs:	( d = 2m / (n(n-1)) )
						Directed graphs:	( d = m / (n(n-1)) )

	Task:			Implement a Monte Carlo simulation that calculates the average shortest path in a graph.
					The graph can be generated using a pseudo-random number generator to produce edges and their costs.
					The shortest path algorithm will be Dijkstra’s.

	Questions:		How to average in disconnected graphs - ignore them for averaging
					Density is for entire set of edges - does not mean node degree is uniform;
					
	Note:			Small graphs with low density leads to the graph being disconnected.
*/
#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	float density = 0.15;
	int size = 100;
	bool directed = false;
	bool verbose = true;
	unsigned int destination = 4;

	Graph* p_graph = new Graph(size, density, directed, verbose);
	std::cout << "Shortest distance traversal from: " << 0 << " to: " << destination << std::endl;
	std::queue<unsigned int> retVal = p_graph->shortestPathTo(0, destination);
	delete(p_graph);
}