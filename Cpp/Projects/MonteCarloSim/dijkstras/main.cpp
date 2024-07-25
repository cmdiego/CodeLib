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

unsigned int monteCarloSim(Graph& g, unsigned int n_sim, unsigned int src);
float vectorAvg(std::vector<unsigned int> v);

int main()
{
	float density = 0.15;
	int size = 100;
	bool directed = true;
	bool verbose = false;
	unsigned int destination = 4;
	unsigned int num_simulations = 1000;
	unsigned int src = 0;
	float result = 0.0;

	Graph* p_graph = new Graph(size, density, directed, verbose);
	result = monteCarloSim(*p_graph, num_simulations, src);
	std::cout << "Average shortest path from " << src << " to all nodes = " << result << std::endl;
	delete(p_graph);
}

/* 
	@brief:		Monte Carlo Simulator 
				The simulator will use the shortestPath() method and get an average
				of all shortest paths from the source node to every node.
	@params:	Graph: Graph object properly initialized,
				n_sim: Number of simulations to run.
	@returns:	The total average weight for the shortest paths 
				from the src to every node, n_sim number of times.
*/
unsigned int monteCarloSim(Graph& graph, unsigned int n_sim, unsigned int src)
{
	float avg = 0.0, total_avg = 0.0;
	std::vector<unsigned int> dist;
	/* Run the simulation */
	for (int i = 0; i < n_sim; ++i)
	{
		dist = graph.shortestPath(src);
		avg += vectorAvg(dist);
	}
	total_avg = avg / n_sim;

	return total_avg;
}

float vectorAvg(std::vector<unsigned int> weights)
{
	int size = weights.size();
	int i = 0, temp = 0;
	float result = 0.0;
	for (; i < size; ++i)
	{
		temp += weights[i];
	}
	result = static_cast<float>(temp)/(size);

	return result;
}