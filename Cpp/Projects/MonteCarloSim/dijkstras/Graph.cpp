#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>
#include <string>

inline unsigned int randomGenerator(unsigned int min, unsigned int max)
{
	return min + rand() % (max - min + 1);
};

Graph::Graph(const unsigned int size, float density, bool type, bool verbose)
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
	m_maxWeight = 100; // Default: max weight of an edge
	m_verbose = verbose;
	// m_size * m_size = total num of edges in a complete graph
	m_matrix = std::vector<std::vector<unsigned int>>(m_size, std::vector<unsigned int>(m_size, INF));
	this->buildGraph(type);
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
	if (type)
		std::cout << "Building a directed graph..." << std::endl;
	else
		std::cout << "Building a undirected graph..." << std::endl;

	for (unsigned int i = 0; i < m_size; i++)
	{
		for (unsigned int j = 0; j < m_size; j++)
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
				if (type)
					addEdge(j, i, 0); // 0 means no edge
				else
					addEdge(j, i, weight);
			}
		}
	}
}

std::vector<unsigned int> Graph::shortestPath(unsigned int source)
{
	std::vector<bool> visited = std::vector<bool>(m_size);
	std::vector<unsigned int> dist = std::vector<unsigned int>(m_size);

	for (unsigned int i = 0; i < m_size; i++)
	{
		visited[i] = false;
		dist[i] = INF;
	}
	dist[source] = 0;
	for (unsigned int i = 0; i < m_size - 1; i++)
	{
		unsigned int minIndex = minDistance(dist, visited);
		visited[minIndex] = true;
		for (unsigned int j = 0; j < m_size; j++)
		{
			if (!visited[j] && m_matrix[minIndex][j] &&
				dist[minIndex] != INF && (dist[minIndex] + m_matrix[minIndex][j]) < dist[j])
			{
				dist[j] = dist[minIndex] + m_matrix[minIndex][j];
			}
		}
	}
	if (m_verbose)
	{
		// print shortest distance from src to every node
		printVector(dist);
	}
	return dist;
}

std::queue<unsigned int> Graph::shortestPathTo(unsigned int source, unsigned int destination)
{
	std::vector<bool> visited = std::vector<bool>(m_size);
	std::vector<unsigned int> dist = std::vector<unsigned int>(m_size);
	std::queue<unsigned int> spt;

	for (int i = 0; i < m_size; i++)
	{
		visited[i] = false;
		dist[i] = INF;
	}
	dist[source] = 0;
	spt.push(source);
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
					spt.push(minIndex); // previous node
			}
		}
		if (m_verbose)
		{
			std::cout << "iteration: " << i << std::endl;
			printVector(dist);
			std::cout << "\n";
		}
	}
	if (m_verbose)
	{
		// print path to destination node
		printQueue(spt);
	}
	return spt;
}

unsigned int Graph::minDistance(std::vector<unsigned int> distArr, std::vector<bool> spt)
{
	unsigned int min_index = INF;
	unsigned int min_val = INF;
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

void Graph::printQueue(std::queue<unsigned int> q)
{
	std::cout << "nodes:";
	for (; !q.empty(); q.pop())
	{
		if (q.size() - 1 && q.front() == INF)
		{
			std::cout << std::setw(3) << "-" << std::endl;
		}
		else if (q.size() - 1 == 0)
		{
			std::cout << std::setw(3) << q.front() << std::endl;
		}
		else if (q.front() == INF)
		{
			std::cout << std::setw(3) << "-";
		}
		else
		{
			std::cout << std::setw(3) << q.front() << "->";
		}
	}
}

void Graph::printVector(std::vector<unsigned int> set)
{
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
		if (i == set.size() - 1 && set[i] == INF)
		{
			std::cout << std::setw(3) << "-" << std::endl;
		}
		else if (i == set.size() - 1)
		{
			std::cout << std::setw(3) << set[i] << std::endl;
		}
		else if (set[i] == INF)
		{
			std::cout << std::setw(3) << "-";
		}
		else
		{
			std::cout << std::setw(3) << set[i];
		}
	}
}

void Graph::printGraph()
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