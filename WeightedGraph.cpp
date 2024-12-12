/*
    Braden Seeber
    12/12/24
    Main file for updated WeightedGraph class
*/
#include "WeightedGraph.h"
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

const int WeightedGraph::NULL_EDGE = 0;

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size, nullptr);
    m_marks.resize(size, false);
    m_edges.resize(size, vector<int>(size, NULL_EDGE));
}

void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    int row = indexIs(m_vertices[fromVertex]);
    int column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::clearMarks()
{
    fill(m_marks.begin(), m_marks.end(), false);
}

void WeightedGraph::doDFS(Vertex* aVertex, vector<string>& path, int& cost)
{
    if (aVertex == nullptr) return;
    path.push_back(aVertex->getTitle());
    int ix = indexIs(aVertex);
    m_marks[ix] = true;
    for (int i = 0; i < m_numVertices; i++) {
        if (m_edges[ix][i] != NULL_EDGE && !m_marks[i]) {
            cost += m_edges[ix][i];
            doDFS(m_vertices[i], path, cost);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    vector<string> path;
    int cost = 0;
    doDFS(aVertex, path, cost);
    printPath(path, cost);
}

void WeightedGraph::doBFS(Vertex* aVertex, vector<string>& path, int& cost)
{
    queue<Vertex*> que;
    int ix = indexIs(aVertex);
    que.push(aVertex);
    m_marks[ix] = true;
    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        path.push_back(node->getTitle());
        ix = indexIs(node);
        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[ix][i] != NULL_EDGE && !m_marks[i]) {
                m_marks[i] = true;
                que.push(m_vertices[i]);
                cost += m_edges[ix][i];
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    vector<string> path;
    int cost = 0;
    doBFS(aVertex, path, cost);
    printPath(path, cost);
}

bool WeightedGraph::isPath(Vertex* src, Vertex* dest)
{
    int start = indexIs(src);
    int end = indexIs(dest);

    vector<int> dist(m_numVertices, INT_MAX);
    vector<int> prev(m_numVertices, -1);
    dist[start] = 0;

    auto compare = [&](int lhs, int rhs) { return dist[lhs] > dist[rhs]; };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
    pq.push(start);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        if (u == end) break;

        for (int v = 0; v < m_numVertices; v++) {
            if (m_edges[u][v] != NULL_EDGE) {
                int alt = dist[u] + m_edges[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.push(v);
                }
            }
        }
    }

    vector<string> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.insert(path.begin(), m_vertices[at]->getTitle());
    }

    if (path.size() > 1 && path.front() == src->getTitle() && path.back() == dest->getTitle()) {
        int cost = dist[end];
        printPath(path, cost);
        return true;
    } else {
        cout << "No path from " << src->getTitle() << " to " << dest->getTitle() << endl;
        return false;
    }
}

void WeightedGraph::printPath(const vector<string>& path, int cost)
{
    for (const auto& node : path) {
        cout << node << " ";
    }
    cout << "\nCost: " << cost << endl;
}
