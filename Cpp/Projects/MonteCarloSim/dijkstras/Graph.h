#pragma once
#include <vector>

class Graph
{
public:
	Graph(unsigned int size, float density, int type);
	void shortestPath(unsigned int source);
	bool isEdge(unsigned int from, unsigned int to);
	void print();
	void printSet(std::vector<unsigned int> set);
private:
	unsigned int minDistance(std::vector<unsigned int> distArr, 
		std::vector<bool> spt);
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
	int INF = INT_MAX;
};
