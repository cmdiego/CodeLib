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

Graph::Graph(const unsigned int size, float density, int type)
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

void Graph::shortestPath(unsigned int source)
{
	std::vector<bool> shortestPathSet = std::vector<bool>(m_size);
	std::vector<unsigned int> dist = std::vector<unsigned int>(m_size);
	std::vector<unsigned int> pred = std::vector<unsigned int>(m_size);

	for (int i = 0; i < m_size; i++)
	{
		shortestPathSet[i] = false;
		dist[i] = INF;
		pred[i] = -1;
	}
	dist[source] = 0;
	for (int i = 0; i < m_size - 1; i++)
	{
		unsigned int minIndex = minDistance(dist, shortestPathSet);
		shortestPathSet[minIndex] = true;
		for (int j = 0; j < m_size; j++)
		{
			if (!shortestPathSet[j] && m_matrix[minIndex][j] &&
				dist[minIndex] != INF && dist[minIndex] + m_matrix[minIndex][j] < dist[j])
			{
				dist[j] = dist[minIndex] + m_matrix[minIndex][j];
				pred[j] = minIndex;
			}
		}
	}
	printSet(dist);
}

unsigned int Graph::minDistance(std::vector<unsigned int> distArr, std::vector<bool> spt)
{
	unsigned int min_val = INF, min_index;
	for (int i = 0; i < m_size; i++)
	{
		if (spt[i] == false && distArr[i] <= min_val)
		{
			min_val = distArr[i];
			min_index = i;
		}
	}
	return min_index;
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
		std::cout << i << std::endl;
		for (int j = 0; j < m_size; j++)
		{
			
			std::cout	<< std::setw(3) << "[" \
						<< std::setw(3) << (m_matrix[i][j] == INF ? "INF" : std::to_string(m_matrix[i][j])) \
						<< std::setw(3) << "] ";
		}
		std::cout << std::endl;
	}
}