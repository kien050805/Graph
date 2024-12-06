#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph
{
private:

public:
    Graph();

    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool edgeIn(int u, int v);
};

#include "Graph.cpp"

#endif