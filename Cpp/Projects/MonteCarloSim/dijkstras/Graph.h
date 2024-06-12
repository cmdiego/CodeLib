#pragma once
#include <vector>

class Node
{
	// Add vector
	// Add size (weighted nodes)
};

class Graph
{
public:
	Graph(unsigned int size, float density);
	/* Methods */
	unsigned int getSize() const;
	void print();
	std::vector<unsigned int> shortestPath();
	std::vector<unsigned int> shortestPath(unsigned int from, unsigned int to);
	bool isEdge(unsigned int from, unsigned int to);
	std::vector<unsigned int> getNeighbours(unsigned int vertex);
	unsigned int getNumEdges(unsigned int vertex);

private:
	/* Methods */
	unsigned int getMaxNumEdgesAllowed();
	void addEdge(unsigned int from, unsigned int to, unsigned int weight);
	void removeEdge(unsigned int from, unsigned int to);
	void build();

	/* Variables */
	std::vector<std::vector<unsigned int>> m_matrix;
	unsigned int m_size;
	unsigned int m_maxNumEdgesAllowed;
	unsigned int m_totalEdges;
	unsigned int m_maxWeight;
	float m_density;
};
