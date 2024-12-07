#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <vector>

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "customexceptions.hpp"

using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int> > Adj;
    vector<int> sorted;
    vector<int> order;

    bool check_vertex(int u) const;
    bool check_edge(int u, int v) const;

    void DFS_visit(int u, unordered_map<int, tuple<int, int, int>> &DFS, int &time, bool sort);

public:
    Graph();
    Graph(const Graph &G);
    ~Graph();
    Graph &operator=(const Graph &G);

    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool edgeIn(int u, int v);
    void deleteVertex(int u);
    void addVertex(int u);

    unordered_map<int, pair<int, int> > breadthFirstSearch(int s);
    unordered_map<int, tuple<int, int, int> > depthFirstSearch(bool sort = false);
    vector<int> getOrdering();

    static Graph readFromSTDIN();
};

#endif