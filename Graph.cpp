/*
Assignment 3: - There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities.
                The cost of the edge can be the time that flight takes to reach city B from A or the amount of fuel used for the journey.
                The node can be represented by airport name or name of the city. Use adjacency list representation of the graph and adjacency
                matrix representation of the graph. Justify the storage representation used


                create a city name array
*/

#include <iostream>
// #include <string>

using namespace std;

class Graph
{
    string city[50], source, dest;
    int fuel, v, i, j, edges;
    int AdjMatrix[50][50];
    Graph *temp, *next, *newNode;

public:
    void acceptByAdjMatrix();
    void acceptByAdjList();
    void display();
    // void adjacencyList();
    // void adjacencyMatrix();
} *head[50];

// void Graph::acceptByAdjMatrix()
// {
//     cout << "Enter the number of cities: ";
//     cin >> v;

//     cout << "Enter the city names: " << endl;
//     for (int i = 0; i < v; i++)
//     {
//         cout << "City " << i + 1 << " : ";
//         cin >> city[i];
//     }
//     cout << "Enter the fuel for the cities : ";
//     for (int i = 0; i < v; i++)
//     {
//         for (int j = 0; j < v; j++)
//         {
//             if (i == j)
//             {
//                 AdjMatrix[i][j] = 0;
//             }
//             else
//             {
//                 cout << "\nEnter the fuel for " << city[i] << " to " << city[j] << " : ";
//                 cin >> AdjMatrix[i][j];
//             }
//         }
//     }
// }

void Graph::acceptByAdjList()
{
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "Enter the city names: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "City " << i + 1 << " : ";
        cin >> city[i];
    }
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source and destination cities : ";
        cin >> source >> dest;
        for (int j = 0; j < v; j++)
        {
            if (source == city[j])
            {
                break;
            }
        }
    }

    newNode = new Graph();
    newNode->city = dest;
    cout << "Enter the fuel required : ";
    cin >> newNode->fuel;
    newNode->next = NULL;

    temp = head[j];
    if (temp == NULL)
    {
        head[j] = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Graph::display()
{
    cout << "\nCities with fuel required : " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    Graph g;
    int choice;
    do
    {
        cout << "1. Accept by adjacency matrix\n";
        cout << "2. Accept by adjacency list\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.acceptByAdjMatrix();
            break;
        case 2:
            g.acceptByAdjList();
            break;
        case 3:
            g.display();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Try again.";
            break;
        }
    } while (choice != 4);
    return 0;
}