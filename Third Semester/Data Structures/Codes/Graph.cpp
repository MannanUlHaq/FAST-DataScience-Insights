#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int NumberofVertices; // Number of vertices in the graph
    vector<list<int>> AdjanceyList; // Adjacency list representation of the graph
public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->NumberofVertices = V; // Set the number of vertices
        this->AdjanceyList.resize(NumberofVertices); // Resize the adjacency list
    }

    // Function to add an edge from vertex V to vertex W
    void addEdge(int V, int W) {
        AdjanceyList[V].push_back(W); // Add W to V's list
    }

    // BFS traversal from a given starting point
    void BFS(int StartingPoint) {
        vector<bool> visited; // Vector to keep track of visited vertices
        visited.resize(NumberofVertices); // Resize the visited vector to the number of vertices
        for (int i = 0; i < NumberofVertices; i++)
            visited[i] = false; // Initialize all vertices as not visited

        queue<int> q; // Queue for BFS

        visited[StartingPoint] = true; // Mark the starting point as visited
        q.push(StartingPoint); // Enqueue the starting point

        while (!q.empty()) {
            int s = q.front(); // Get the front element from the queue
            cout << s << " "; // Print the current node
            q.pop(); // Remove the front element

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (auto adjVertex : AdjanceyList[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true; // Mark the adjacent vertex as visited
                    q.push(adjVertex); // Enqueue the adjacent vertex
                }
            }
        }
    }

    // DFS traversal from a given starting point
    void DFS(int StartingPoint) {
        vector<bool> visited; // Vector to keep track of visited vertices
        visited.resize(NumberofVertices); // Resize the visited vector to the number of vertices
        for (int i = 0; i < NumberofVertices; i++)
            visited[i] = false; // Initialize all vertices as not visited

        stack<int> s; // Stack for DFS

        s.push(StartingPoint); // Push the starting point onto the stack

        while (!s.empty()) {
            int x = s.top(); // Get the top element from the stack
            s.pop(); // Remove the top element

            // If the vertex has not been visited, process it
            if (!visited[x]) {
                cout << x << " "; // Print the current node
                visited[x] = true; // Mark the current node as visited
            }

            // Get all adjacent vertices of the popped vertex x
            // If an adjacent vertex has not been visited, then push it to the stack
            for (auto adjVertex : AdjanceyList[x]) {
                if (!visited[adjVertex]) {
                    s.push(adjVertex); // Push the adjacent vertex onto the stack
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 1);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal (starting from vertex 0): ";
    g.BFS(0);

    // Perform DFS traversal starting from vertex 0
    cout << "\nDepth First Traversal (starting from vertex 0): ";
    g.DFS(0);

    // Breadth First Traversal(starting from vertex 0) : 0 1 2 3 4
    // Depth First Traversal(starting from vertex 0) : 0 2 3 4 1

    return 0;
}