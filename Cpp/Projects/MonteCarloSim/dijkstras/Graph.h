#pragma once
#include <vector>

class Graph
{
public:
	Graph(unsigned int size, float density, int type);
	/* Methods */
	void print();
	std::vector<unsigned int> shortestPath();
	std::vector<unsigned int> shortestPath(unsigned int from, unsigned int to);
	bool isEdge(unsigned int from, unsigned int to);
	void printSet(std::vector<unsigned int> set);
private:
	/* Methods */
	void addEdge(unsigned int from, unsigned int to, unsigned int weight);
	void removeEdge(unsigned int from, unsigned int to);
	void buildUndirected();
	void buildDirected();

	/* Variables */
	std::vector<std::vector<unsigned int>> m_matrix;
	unsigned int m_size;
	unsigned int m_maxNumEdges;
	unsigned int m_totalEdges;
	unsigned int m_maxWeight;
	float m_density;
};
