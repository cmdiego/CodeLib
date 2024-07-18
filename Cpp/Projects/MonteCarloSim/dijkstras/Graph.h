#pragma once
#include <vector>
#include <queue>

class Graph
{
public:
	Graph(unsigned int size, float density, bool type, bool verbose);
	std::vector<unsigned int> shortestPath(unsigned int source);
	std::queue<unsigned int> shortestPathTo(unsigned int source, unsigned int dest);
	bool isEdge(unsigned int from, unsigned int to);
	void printGraph();
	void printQueue(std::queue<unsigned int> q);
	void printVector(std::vector<unsigned int> set);
private:
	unsigned int minDistance(std::vector<unsigned int> distArr, 
		std::vector<bool> spt);
	void addEdge(unsigned int from, unsigned int to, unsigned int weight);
	void removeEdge(unsigned int from, unsigned int to);
	void buildGraph(int type);

	/* Variables */
	std::vector<std::vector<unsigned int>> m_matrix;
	unsigned int m_size;
	unsigned int m_maxNumEdges;
	unsigned int m_totalEdges;
	unsigned int m_maxWeight;
	bool m_verbose;
	float m_density;
	int INF = INT_MAX;
};
