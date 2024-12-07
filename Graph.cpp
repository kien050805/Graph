#include "Graph.hpp"

using namespace std;

Graph::Graph() {};

Graph::Graph(const Graph &G)
{
    Adj = G.Adj;
    sorted = G.sorted;
};

Graph::~Graph() {};

Graph &Graph::operator=(const Graph &G)
{
    Adj = G.Adj;
    sorted = G.sorted;
    return *this;
};

bool Graph::check_vertex(int u) const
{
    return Adj.find(u) != Adj.end();
}

bool Graph::check_edge(int u, int v) const
{
    if (!check_vertex(u))
    {
        return false;
    }
    for (int i = 0; i < Adj.at(u).size(); i++)
    {
        if (Adj.at(u)[i] == v)
        {
            return true;
        }
    }
    return false;
}

void Graph::addEdge(int u, int v)
{
    if (!check_vertex(u))
    {
        return;
    }
    if (!check_vertex(v))
    {
        return;
    }
    if (!check_edge(u, v))
    {
        Adj[u].push_back(v);
    }
    return;
};

void Graph::removeEdge(int u, int v)
{
    for (int i = 0; i < Adj[u].size(); i++)
    {
        if (Adj[u][i] == v)
        {
            Adj[u].erase(Adj[u].begin() + i);
            return;
        };
    };
    throw edge_exception();
};

bool Graph::edgeIn(int u, int v)
{
    for (int i = 0; i < Adj[u].size(); i++)
    {
        if (Adj[u][i] == v)
        {
            return true;
        };
    };
    return false;
};

void Graph::deleteVertex(int u)
{
    Adj.erase(u);
    for (int i = 0; i < sorted.size(); i++)
    {
        if (edgeIn(sorted[i], u))
        {
            removeEdge(sorted[i], u);
        };
    };
};

void Graph::addVertex(int u)
{
    if (check_vertex(u))
    {
        throw vertex_exception();
    };
    sorted.push_back(u);
    Adj.insert({u, vector<int>()});
};

unordered_map<int, pair<int, int>> Graph::breadthFirstSearch(int s)
{
    unordered_map<int, pair<int, int>> BFS;
    for (int i = 0; i < sorted.size(); i++)
    {
        BFS.insert({sorted[i], pair<int, int>(-1, 0)}); // -1 as unreachable, 0 as NIL
    }
    BFS[s].first = 0;
    BFS[s].second = -1;
    queue<int> to_visit;
    to_visit.push(s);
    while (!to_visit.empty())
    {
        int u = to_visit.front();
        to_visit.pop();
        for (int i = 0; i < Adj[u].size(); i++)
        {
            if (BFS[Adj[u][i]].first == -1)
            {
                BFS[Adj[u][i]].first = BFS[u].first + 1;
                BFS[Adj[u][i]].second = u;
                to_visit.push(Adj[u][i]);
            };
        }
    };
    return BFS;
};

void Graph::DFS_visit(int u, unordered_map<int, tuple<int, int, int>> &DFS, int &time, bool sort)
{
    time++;
    get<0>(DFS[u]) = time;

    for (int i = 0; i < Adj.at(u).size(); i++)
    {
        int v = Adj.at(u)[i];
        if (get<0>(DFS[v]) == -1)
        {
            get<2>(DFS[v]) = u;
            DFS_visit(v, DFS, time, sort);
        }
    }
    time++;
    get<1>(DFS[u]) = time;
    if (sort)
    {
        order.insert(order.begin(), u);
    }
}

unordered_map<int, tuple<int, int, int>> Graph::depthFirstSearch(bool sort)
{
    unordered_map<int, tuple<int, int, int>> DFS;

    for (int i = 0; i < sorted.size(); i++)
    {
        DFS[sorted[i]] = make_tuple(-1, -1, 0); // -1, -1 as time sentinel, 0 as NIL
    };

    int time = 0;
    for (int i = 0; i < sorted.size(); i++)
    {
        if (get<0>(DFS[sorted[i]]) == -1)
        {
            DFS_visit(sorted[i], DFS, time, sort);
        };
    };
    return DFS;
};

vector<int> Graph::getOrdering()
{
    return order;
};

Graph Graph::readFromSTDIN()
{
    Graph G;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        G.addVertex(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    return G;
};
