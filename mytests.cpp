#include <iostream>
#include <tuple>
#include "Graph.hpp"

using namespace std;

int main()
{
    // Graph g = Graph::readFromSTDIN();
    Graph g;
    for (int i = 1; i <= 6; i++)
    {
        g.addVertex(i);
    }
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 5);
    g.addEdge(6, 6);

    unordered_map<int, tuple<int, int, int>> DFS = g.depthFirstSearch(true);
    for (int i = 1; i <= 6; i++)
    {
        cout << get<0>(DFS[i]) << " " << get<1>(DFS[i]) << " " << get<2>(DFS[i]) << endl;
    };
    vector<int> order = g.getOrdering();

for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i < order.size() - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
};