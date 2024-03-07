#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int x, y; // Coordinates of the node
    bool visited; // Flag to track visited nodes
    vector<Node*> neighbors; // Neighboring nodes
};

// Function to find a path between two nodes using BFS
bool findPath(Node* start, Node* end) {
    // Create a queue for BFS
    queue<Node*> q;

    // Mark the start node as visited and enqueue it
    start->visited = true;
    q.push(start);

    // BFS
    while (!q.empty()) {
        // Dequeue a node from the queue
        Node* current = q.front();
        q.pop();

        // If the current node is the end node, path found
        if (current == end) {
            return true;
        }

        // Visit all the neighboring nodes
        for (Node* neighbor : current->neighbors) {
            if (!neighbor->visited) {
                neighbor->visited = true;
                q.push(neighbor);
            }
        }
    }

    // Path not found
    return false;
}

int main() {
    // Create nodes
    Node* node1 = new Node{1, 1, false};
    Node* node2 = new Node{2, 2, false};
    Node* node3 = new Node{3, 3, false};
    Node* node4 = new Node{4, 4, false};

    // Connect nodes
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node4);

    // Find path between node1 and node4
    bool pathExists = findPath(node1, node4);

    // Print the result
    if (pathExists) {
        cout << "Path exists between node1 and node4" << endl;
    } else {
        cout << "Path does not exist between node1 and node4" << endl;
    }

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}