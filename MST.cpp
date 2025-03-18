/*
you are a job seeker prepparing fo rinterviw you have list of cities where interviews are schedules you have to find shortest path to reach all
cities starting form you current location the objective is to minikize the total travel distance and time while ensuring you reach each location on
time use appropriate and algortihm and data structure to solve the problem and implement it
*/

#include <iostream>

using namespace std;

class MST // Minimum Spanning Tree
{
    string city[10];
    int min, v, e, u;
    int adjMatrix[10][10];
    bool visited[10];
    int key[10], parent[10];

public:
    void create();
    void edges();
    void displayByPrimsAlgorithm();
};

void MST::create()
{
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "Enter the city names: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "City " << i + 1 << " : ";
        cin >> city[i];
    }
}

void MST::edges(){
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (i == j){
                adjMatrix[i][j] = 0;
            }
            else{
                cout << "\nEnter the fuel for " << city[i] << " to " << city[j] << " : ";
                cin >> adjMatrix[i][j];
                // adjMatrix[j][i] = adjMatrix[i][j];
            }
        }
    }
}

void MST::displayByPrimsAlgorithm(){
    for (int i = 0; i < v; i++){
        visited[i] = false;
        min = 999;
        key[0] = 0;
        parent[0] = -1;
    }
    for (int edge = 0; edge < v - 1; edge++){
        min = 999;
        for (int i = 0; i < v; i++){
            if (!visited[i] && key[i] < min){
                min = key[i];
                u = i;
            }

            visited[u] = true;

            for (int j = 0; j < v; j++){
                if (adjMatrix[u][j] && !visited[j] && adjMatrix[u][j] < key[j]){
                    parent[j] = u;
                    key[j] = adjMatrix[u][j];
                }
            }
        }
    }
}

int main()
{
    int choice;
    MST m;
    do
    {
        cout << "\n1. Accept\n2. Add Edges\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.create();
            break;
        case 2:
            m.edges();
            break;
        case 3:
            m.displayByPrimsAlgorithm();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}