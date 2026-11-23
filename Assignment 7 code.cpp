#include <iostream>
Using namespace std;

Class Graph
{
Private:
Int vertices, adj[20][20];

Public:

// Constructor
Graph()
{
Vertices = 0;

For (int I = 0; I < 20; i++)
{
For (int j = 0; j < 20; j++)
{
Adj[i][j] = 0;
}
}
}

// Create Graph
Void createGraph()
{
Int edges, source, destination;

Cout << “\nEnter number of vertices: “;
Cin >> vertices;

For (int I = 0; I < vertices; i++)
{
For (int j = 0; j < vertices; j++)
{
Adj[i][j] = 0;
}
}

Cout << “Enter number of edges: “;
Cin >> edges;

Cout << “\nEnter edges (source destination):\n”;

For (int I = 0; I < edges; i++)
{
Cout << “Edge “ << I + 1 << “: “;
Cin >> source >> destination;

If (source >= 0 && source < vertices &&
Destination >= 0 && destination < vertices)
{
// Undirected graph
Adj[source][destination] = 1;
Adj[destination][source] = 1;
}
Else
{
Cout << “Invalid vertex number.\n”;
i--;
}
}

Cout << “\nGraph created successfully.\n”;
}

// Display Adjacency Matrix
Void displayMatrix()
{
If (vertices == 0)
{
Cout << “\nGraph is not created.\n”;
Return;
}

Cout << “\nAdjacency Matrix:\n\n”;

Cout << “ “;

For (int I = 0; I < vertices; i++)
{
Cout << I << “ “;
}

Cout << endl;

For (int I = 0; I < vertices; i++)
{
Cout << I << “: “;

For (int j = 0; j < vertices; j++)
{
Cout << adj[i][j] << “ “;
}

Cout << endl;
}
}

// DFS using Adjacency Matrix
Void DFS(int startVertex)

{
If (vertices == 0)
{
Cout << “\nGraph is not created.\n”;
Return;
}

If (startVertex < 0 || startVertex >= vertices)
{
Cout << “\nInvalid starting vertex.\n”;
Return;
}

Int visited[20];
Int stack[20];
Int top = -1;

// Initialize visited array
For (int I = 0; I < vertices; i++)
{
Visited[i] = 0;
}

// Push starting vertex
Top++;
Stack[top] = startVertex;

Cout << “\nDFS Traversal: “;

// Continue until stack becomes empty
While (top != -1)
{
// Pop vertex
Int current = stack[top];
Top--;

// Process only if not visited
If (visited[current] == 0)
{
Cout << current << “ “;

// Mark as visited
Visited[current] = 1;

// Check adjacent vertices from right to left
For (int I = vertices – 1; I >= 0; i--)
{
If (adj[current][i] == 1 && visited[i] == 0)
{
Top++;
Stack[top] = I;
}

}
}
}

Cout << endl;
}
};

// =========================
// Main Function
// =========================

Int main()
{
// Create object
Graph g;

Int choice;
Int startVertex;

Do
{
Cout << “\n============================”;
Cout << “\n GRAPH MENU”;
Cout << “\n============================”;

Cout << “\n1. Create Graph”;
Cout << “\n2. Display Adjacency Matrix”;
Cout << “\n3. DFS Traversal”;
Cout << “\n4. Exit”;
Cout << “\n============================”;

Cout << “\nEnter your choice: “;
Cin >> choice;

Switch (choice)
{
Case 1:
g.createGraph();
break;
case 2:
g.displayMatrix();
break;
case 3:
cout << “\nEnter starting vertex: “;
cin >> startVertex;
g.DFS(startVertex);
break;

case 4:
cout << “\nProgram terminated.\n”;
break;

default:
cout << “\nInvalid choice. Please try again.\n”;
}
} while (choice != 4);
Return 0;
}
