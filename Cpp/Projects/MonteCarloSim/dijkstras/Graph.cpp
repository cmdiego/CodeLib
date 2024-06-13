#include "Graph.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

inline unsigned int randomGenerator(unsigned int min, unsigned int max)
{
	return min + rand() % (max - min + 1);
};

Graph::Graph(unsigned int size, float density)
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
	std::cout << "Building graph..." << std::endl;

	m_size = size;
	std::cout << "Number of nodes = " << m_size << std::endl;
	m_density = std::ceil((m_size - 1) * density);
	std::cout << "min number of edges per node (density) = " << m_density << std::endl;
	m_totalEdges = 0;
	m_maxWeight = 10; // Default: max weight of an edge
	// m_size * m_size = total num of edges in a complete graph
	m_matrix = std::vector<std::vector<unsigned int>>(m_size, std::vector<unsigned int>(m_size));
	build();
}

void Graph::addEdge(unsigned int from, unsigned int to, unsigned int weight)
{
	m_matrix[from][to] = weight;
	if (weight > 0)
	{
		++m_totalEdges;
	}
}

void Graph::removeEdge(unsigned int from, unsigned int to)
{
	m_matrix[from][to] = 0;
}

bool Graph::isEdge(unsigned int from, unsigned int to)
{
	return m_matrix[from][to] != 0 ? true : false;
}

std::vector<unsigned int> Graph::getNeighbours(unsigned int node)
{
	std::vector<unsigned int> neighbors;
	for (int i = 0; i < m_matrix[node].size(); i++)
	{
		if (i == node)
		{
			continue;
		}
		else if (m_matrix[node][i] != 0)
		{
			neighbors.push_back(i);
		}
	}
	return neighbors;
}

void Graph::build()
{
	std::cout << "Building graph..." << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		unsigned int neighborDensity = randomGenerator(m_density, m_size);
		for (int j = 0; j < neighborDensity; j++)
		{
			int weight = randomGenerator(0, m_maxWeight); // 0 means no edge
			int to = randomGenerator(0, m_size - 1);
			std::cout << "Adding [" << weight << "] from [" << i << "] to [" << to << "]\n" << std::flush;
			addEdge(i, j, weight);
		}
	}
}

std::vector<unsigned int> Graph::shortestPath()
{
	std::vector<unsigned int> shortestPathSet;
	unsigned int from	= 0;
	unsigned int to		= randomGenerator(1, (m_size - 1));
	std::cout << "Calculating shortest path from " << from << " to " << to << std::endl;
	// Dijkstra's algorithm
	for (int i = 0; i < m_size; i++)
	{
		std::vector<unsigned int> neighbors = getNeighbours(i);
		unsigned int minNeighbor = neighbors[0];
		for (int j = 0; j < neighbors.size() - 1; j++)
		{
			std::cout << "Node [" << i << "] has neighbor [" << neighbors[j] << "]" << std::endl;
			if (neighbors[j] < neighbors[j + 1])
			{
				minNeighbor = j;
			}
		}
		shortestPathSet.push_back(minNeighbor);
		i = minNeighbor;
	}
	return shortestPathSet;
}

std::vector<unsigned int> Graph::shortestPath(unsigned int from, unsigned int to)
{
	std::vector<unsigned int> retPath;
	std::cout << "Calculating shortest path..." << std::endl;

	// Dijkstra's algorithm



	return retPath;
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
			std::cout	<< std::setw(2) << "[" \
						<< std::setw(2) << m_matrix[i][j] \
						<< std::setw(2) << "] ";
		}
		std::cout << std::endl;
	}
}