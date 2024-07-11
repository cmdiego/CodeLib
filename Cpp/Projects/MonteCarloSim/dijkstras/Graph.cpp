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
	if (type < 0 || type > 1)
	{
		std::cout << "invalid type passed to constructor" << std::endl;
		exit(1);
	}
	else
	{
		this->buildGraph(type);
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

void Graph::buildGraph(int type)
{
	if (type == 0)
		std::cout << "Building a directed graph..." << std::endl;
	else
		std::cout << "Building a undirected graph..." << std::endl;

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
				if (type == 0)
					addEdge(j, i, 0); // 0 means no edge
				else
					addEdge(j, i, weight);
			}
		}
	}
}

void Graph::shortestPath(unsigned int source)
{
	std::vector<bool> visited = std::vector<bool>(m_size);
	std::vector<unsigned int> dist = std::vector<unsigned int>(m_size);
	std::vector<unsigned int> spt = std::vector<unsigned int>(m_size);

	for (int i = 0; i < m_size; i++)
	{
		visited[i] = false;
		dist[i] = INF;
		spt[i] = -1;
	}
	dist[source] = 0;
	for (int i = 0; i < m_size - 1; i++)
	{
		unsigned int minIndex = minDistance(dist, visited);
		visited[minIndex] = true;
		for (int j = 0; j < m_size; j++)
		{
			if (!visited[j] && m_matrix[minIndex][j] &&
				dist[minIndex] != INF && (dist[minIndex] + m_matrix[minIndex][j]) < dist[j])
			{
				dist[j] = dist[minIndex] + m_matrix[minIndex][j];
			}
		}
	}
	// print shortest distance from src to every node
	printSet(dist);
}

void Graph::shortestPath(unsigned int source, unsigned int destination)
{
	std::vector<bool> visited = std::vector<bool>(m_size);
	std::vector<unsigned int> dist = std::vector<unsigned int>(m_size);
	std::vector<unsigned int> spt = std::vector<unsigned int>(m_size);

	for (int i = 0; i < m_size; i++)
	{
		visited[i] = false;
		dist[i] = INF;
		spt[i] = 11;
	}
	dist[source] = 0;
	for (int i = 0; i < m_size; i++)
	{
		unsigned int minIndex = minDistance(dist, visited);
		visited[minIndex] = true;
		for (int j = 0; j < m_size; j++)
		{
			if (!visited[j] && m_matrix[minIndex][j] &&
				dist[minIndex] != INF && (dist[minIndex] + m_matrix[minIndex][j]) < dist[j])
			{
				dist[j] = dist[minIndex] + m_matrix[minIndex][j];
				if (j == destination)
					spt[i] = minIndex; // previous node
			}
		}
		printIter(dist, i);
	}
	// print path to destination node
	printSet(spt);
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
	std::cout << "count:";
	for (int i = 0; i < set.size(); i++)
	{
		if (i == set.size() - 1)
		{
			std::cout << std::setw(3) << i << std::endl;
		}
		else
		{
			std::cout << std::setw(3) << i;
		}
	}
	std::cout << "value:";
	for (int i = 0; i < set.size(); i++)
	{
		if (i == set.size() - 1)
		{
			std::cout << std::setw(3) << set[i] << std::endl;
		}
		else
		{
			std::cout << std::setw(3) << set[i];
		}
	}
}

void Graph::printIter(std::vector<unsigned int> set, int iteration)
{
	std::cout << "iteration: " << iteration << std::endl;
	std::cout << "index:";
	for (int i = 0; i < set.size(); i++)
	{
		if (i == set.size() - 1)
		{
			std::cout << std::setw(3) << i << std::endl;
		}
		else
		{
			std::cout << std::setw(3) << i;
		}
	}
	std::cout << "value:";
	for (int i = 0; i < set.size(); i++)
	{
		if (i == set.size() - 1)
		{
			std::cout << std::setw(3) << set[i] << std::endl;
		}
		else
		{
			std::cout << std::setw(3) << set[i];
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