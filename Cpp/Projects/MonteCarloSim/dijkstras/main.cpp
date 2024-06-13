/*
	Description:	Edge List (Better for sparse graphs) vs. Adjacency Matrix (better for dense graphs)

					A representation of a directed graph with n vertices using an array of n lists of vertices.
					List 'i' contains vertex 'j' if there is an edge from 'i' to 'j'.
					A weighted graph may be represented with a list of vertex/weight pairs.
					An undirected graph may be represented by having vertex 'j' in the list for vertex 'i' and vice versa.
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
					also for smal graphs a low density leads to graph being disconnected.
*/
#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	float density = 0.70;
	int size = 10;
	Graph* p_graph = new Graph(size, density);
	p_graph->print();
}