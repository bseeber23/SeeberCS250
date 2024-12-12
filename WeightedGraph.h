/*
    Braden Seeber
    12/12/24
    Header file for updated WeigthedGraphClass
*/
#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include <string>
#include "Vertex.h"
using namespace std;

class WeightedGraph
{
public:
    WeightedGraph(int size);
    bool isEmpty();
    void addVertex(Vertex* aVertex);
    void addEdge(int fromVertex, int toVertex, int weight);
    bool isFull();
    void DFS(Vertex* aVertex);
    void BFS(Vertex* aVertex);
    bool isPath(Vertex* src, Vertex* dest);
    void printPath(const vector<string>& path, int cost);

protected:
    int indexIs(Vertex* aVertex);
    void clearMarks();
    void doDFS(Vertex* aVertex, vector<string>& path, int& cost);
    void doBFS(Vertex* aVertex, vector<string>& path, int& cost);

private:
    static const int NULL_EDGE;
    int m_numVertices;
    int m_maxVertices;
    vector<Vertex*> m_vertices;
    vector<vector<int>> m_edges;
    vector<bool> m_marks;
};

#endif // WEIGHTEDGRAPH_H
