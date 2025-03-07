/*
you are a job seeker prepparing fo rinterviw you have list of cities where interviews are schedules you have to find shortest path to reach all
cities starting form you current location the objective is to minikize the total travel distance and time while ensuring you reach each location on
time use appropriate and algortihm and data structure to solve the problem and implement it
*/

#include <iostream>
#include <vector>

using namespace std;

class MST
{
    string city[50], source, dest;
    int fuel, v, i, j, edges;
    int AdjMatrix[50][50];
    MST *temp, *next, *newNode;

public:
    void accept();
    // void acceptByAdjList();
    void display();
};