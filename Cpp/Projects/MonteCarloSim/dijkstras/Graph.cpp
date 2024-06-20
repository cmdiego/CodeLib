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
	m_density = density;
	m_size = size;
	m_totalEdges = 0;
	m_maxWeight = 10; // Default: max weight of an edge
	// m_size * m_size = total num of edges in a complete graph
	m_matrix = std::vector<std::vector<unsigned int>>(m_size, std::vector<unsigned int>(m_size, INF));
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
	m_matrix[from][to] = INF;
}

bool Graph::isEdge(unsigned int from, unsigned int to)
{
	return m_matrix[from][to] == 0 ? false : true;
}

void Graph::buildDirected()
{
	std::cout << "Building a directed graph..." << std::endl;
	for (unsigned i = 0; i < m_size; i++)
	{
		for (unsigned j = 0; j < m_size; j++)
		{
			if (i == j)
			{
				addEdge(i, j, 0);
				continue;
			}
			float prob = float(randomGenerator(0, 100) / 100.00);
			if (prob >= m_density && isEdge(i, j))
			{
				int weight = randomGenerator(1, m_maxWeight); // Greater than 0
				addEdge(i, j, weight);
				addEdge(j, i, 0); // 0 means no edge
			}
		}
	}
}

void Graph::buildUndirected()
{
	std::cout << "Building a directed graph..." << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (i == j)
			{
				addEdge(i, j, 0);
				continue;
			}
			float prob = float(randomGenerator(0, 100) / 100.00);
			if (prob >= m_density)
			{
				int weight = randomGenerator(1, m_maxWeight); // Greater than 0
				addEdge(i, j, weight);
				addEdge(j, i, weight);
			}
		}
	}
}

std::vector<unsigned int> Graph::shortestPath()
{
	// TODO: IMPLEMENT OPEN/CLOSE SET ALGO. TO OVERCOME DISCONNECTED GRAPHS

	std::vector<unsigned int> shortestPathSet;
	std::vector<std::vector<unsigned int>> visitedNodes(m_size, std::vector<unsigned int>(m_size, 0));
	unsigned int to		= randomGenerator(1, (m_size - 1));
	unsigned int from = 0;
	// Dijkstra's algorithm
	unsigned int lastNodeWeight = INF;
	visitedNodes[0][0] = 1;
	shortestPathSet.push_back(0);
	std::cout << "Calculating shortest path from " << from << " to " << to << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			// Skip if the node is itself, already visited, or is not an edge
			if (i == j || visitedNodes[i][j] == 1 || !isEdge(i, j))
			{
				continue;
			}
			if (lastNodeWeight > m_matrix[i][j])
			{
				lastNodeWeight = m_matrix[i][j];
				from = j;
				visitedNodes[i][j] = 1;
			}
		}
		shortestPathSet.push_back(from);
		if (from == to)
		{
			return shortestPathSet;
		}
		else
		{
			i = from;
		}
	}
	printf("Graph is disconnected, could not reach destination...\n");
	return shortestPathSet;
}

//std::vector<unsigned int> Graph::shortestPath(unsigned int from, unsigned int to)
//{
//	
//}

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
						<< std::setw(3) << (m_matrix[i][j] == INF ? "INF" : std::to_string(m_matrix[i][j])) \
						<< std::setw(3) << "] ";
		}
		std::cout << std::endl;
	}
}