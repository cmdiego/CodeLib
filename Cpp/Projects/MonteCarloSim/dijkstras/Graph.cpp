#include "Graph.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>


inline unsigned int randomGenerator(unsigned int min, unsigned int max)
{
	return min + rand() % (max - min + 1);
};

Graph::Graph(unsigned int size, float density, int type)
{
	// Why does the randomGenerator work if we place the srand func inside Graph??
	srand(time(NULL));

	if (size < 1)
	{
		std::cout << "Error: 'size' cannot be less than 1" << std::endl;
		return;
	}
	if (density > 1)
	{
		std::cout << "Error: 'density' cannot be greater than 1; allowed range: [0.00, 1.00]" << std::endl;
		return;
	}
	m_size = size;
	std::cout << "Number of nodes = " << m_size << std::endl;
	m_density = std::ceil((m_size - 1) * density);
	std::cout << "min number of edges per node (density) = " << m_density << std::endl;
	m_totalEdges = 0;
	m_maxWeight = 10; // Default: max weight of an edge
	// m_size * m_size = total num of edges in a complete graph
	m_matrix = std::vector<std::vector<unsigned int>>(m_size, std::vector<unsigned int>(m_size, INT_MAX));
	switch (type)
	{
	case 0:
		buildDirected();
		break;
	case 1:
		buildUndirected();
		break;
	}
}

void Graph::addEdge(unsigned int from, unsigned int to, unsigned int weight)
{
	m_matrix[from][to] = weight;
	++m_totalEdges;
}

void Graph::removeEdge(unsigned int from, unsigned int to)
{
	m_matrix[from][to] = 0;
}

bool Graph::isEdge(unsigned int from, unsigned int to)
{
	return m_matrix[from][to] != 0 ? true : false;
}

void Graph::buildDirected()
{
	std::cout << "Building a directed graph..." << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		unsigned int neighborDensity = randomGenerator(m_density, m_size);
		for (int j = 0; j < neighborDensity; j++)
		{
			int weight = randomGenerator(1, m_maxWeight); // Greater than 0
			int to = randomGenerator(0, m_size - 1);
			if (i == to)
			{
				continue;
			}
			if (m_matrix[to][i] == 0 or m_matrix[i][to] == 0)
			{
				std::cout << "Edge already exists from [" << i << "] to [" << to << "]\n" << std::flush;
				continue;
			}
			std::cout << "Adding [" << weight << "] from [" << i << "] to [" << to << "]\n" << std::flush;
			addEdge(i, to, weight);
			std::cout << "Adding [" << 0 << "] from [" << to << "] to [" << i << "]\n" << std::flush;
			addEdge(to, i, 0); // 0 means no edge
		}
	}
}

void Graph::buildUndirected()
{
	std::cout << "Building an undirected graph..." << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		unsigned int neighborDensity = randomGenerator(m_density, m_size);
		for (int j = 0; j < neighborDensity; j++)
		{
			int weight = randomGenerator(1, m_maxWeight);
			int to = randomGenerator(0, m_size - 1);
			if (i == to)
			{
				continue;
			}
			std::cout << "Adding [" << weight << "] from [" << i << "] to [" << to << "]\n" << std::flush;
			addEdge(i, to, weight);
			addEdge(to, i, weight);
		}
	}
}

std::vector<unsigned int> Graph::shortestPath()
{
	std::vector<unsigned int> shortestPathSet;
	std::vector<std::vector<unsigned int>> visitedNodes(m_size, std::vector<unsigned int>(m_size, 0));
	unsigned int from	= 0;
	unsigned int to		= randomGenerator(1, (m_size - 1));
	std::cout << "Calculating shortest path from " << from << " to " << to << std::endl;
	// Dijkstra's algorithm
	unsigned int minWeight = INT_MAX;
	unsigned int destNode;
	shortestPathSet.push_back(from);
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size - 1; j++)
		{
			// Skip if the node is itself, already visited
			if (i == j or visitedNodes[i][j] == 1)
			{
				continue;
			}
			if (m_matrix[i][j + 1] != 0 && m_matrix[i][j + 1] != INT_MAX && m_matrix[i][j + 1] < minWeight)
			{
				minWeight = m_matrix[i][j + 1];
				destNode = j + 1;
			}
			// mark node as visited
			visitedNodes[i][j] = 1;
		}
		std::cout << "from [" << i << "] -> [" << destNode << "] = " << minWeight << "\n" << std::flush;
		shortestPathSet.push_back(destNode);
		if (destNode == to)
		{
			break;
		}
		i = destNode;
	}
	return shortestPathSet;
}

std::vector<unsigned int> Graph::shortestPath(unsigned int from, unsigned int to)
{
	std::vector<unsigned int> shortestPathSet;
	std::vector<std::vector<unsigned int>> visitedNodes(m_size, std::vector<unsigned int>(m_size, 0));
	std::cout << "Calculating shortest path from " << from << " to " << to << std::endl;
	// Dijkstra's algorithm
	unsigned int minNeighbor = INT_MAX;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size - 1; j++)
		{
			if (i == j or visitedNodes[i][j] == 1)
			{
				continue;
			}
			else if (m_matrix[i][j] > m_matrix[i][j + 1])
			{
				std::cout << "from [" << minNeighbor << "] -> [" << j + 1 << "] = " << m_matrix[i][j + 1] << "\n" << std::flush;
				minNeighbor = j + 1;
			}
			// mark node as visited
			visitedNodes[i][j] = 1;
		}
		shortestPathSet.push_back(minNeighbor);
		if (minNeighbor == to)
		{
			break;
		}
		i = minNeighbor;
	}
	return shortestPathSet;
}

void Graph::printSet(std::vector<unsigned int> set)
{
	for (int i = 0; i < set.size(); i++)
	{
		if (i == set.size() - 1)
		{
			std::cout << set[i] << std::endl;
		}
		else
		{
			std::cout << set[i] << " -> ";
		}
	}
}

void Graph::print()
{
	if (m_size < 1)
	{
		std::cout << "Error: 'size' cannot be less than 1" << std::endl;
		return;
	}
	else if (m_size > 20)
	{
		std::cout << "Error: cannot print matrix with size greater than 20" << std::endl;
		return;
	}
	
	std::cout << "Printing graph..." << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			
			std::cout	<< std::setw(3) << "[" \
						<< std::setw(3) << (m_matrix[i][j] == INT_MAX ? "INF" : std::to_string(m_matrix[i][j])) \
						<< std::setw(3) << "] ";
		}
		std::cout << std::endl;
	}
}