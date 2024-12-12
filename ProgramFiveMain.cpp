/*
    Braden Seeber
    12/12/2024
    Program Five: Perform DFS and BFS on 5 noded graph, then test paths between nodes
*/
#include <iostream>
#include "WeightedGraph.h"
#include "Vertex.h"
#include <iostream>

using namespace std;

int main() {
    // Create a weighted graph with 5 vertices
    WeightedGraph graph(5);

    // Create vertices
    Vertex* A = new Vertex("A");
    Vertex* B = new Vertex("B");
    Vertex* C = new Vertex("C");
    Vertex* D = new Vertex("D");
    Vertex* E = new Vertex("E");

    // Add vertices to the graph
    graph.addVertex(A);
    graph.addVertex(B);
    graph.addVertex(C);
    graph.addVertex(D);
    graph.addVertex(E);

    // Add edges with weights according to the directed graph
    graph.addEdge(4, 0, 7);  // E -> A (7)
    graph.addEdge(0, 2, 12); // A -> C (12)
    graph.addEdge(0, 3, 60); // A -> D (60)
    graph.addEdge(2, 1, 20); // C -> B (20)
    graph.addEdge(2, 3, 32); // C -> D (32)
    graph.addEdge(1, 0, 10); // B -> A (10)

    Vertex* start_vertex = E; // Start from vertex E

    // Perform DFS from vertex E
    cout << "DFS from E:" << endl;
    graph.DFS(start_vertex);

    // Perform BFS from vertex E
    cout << "\nBFS from E:" << endl;
    graph.BFS(start_vertex);

    // Test the path-checking function
    cout << "\nPath from A to E:" << endl;
    graph.isPath(A, E);

    cout << "\nPath from A to D:" << endl;
    graph.isPath(A, D);

    cout << "\nPath from B to D:" << endl;
    graph.isPath(B, D);

    return 0;
}
