//========================================================
// mytests.cpp 
// James Bui & Kien Le & Trinity Meckel 
// December 9, 2024
//
// Description:
// This file contains the tests cases for the Graph class
//========================================================
#include <iostream>
#include <tuple>
#include "Graph.hpp"
using namespace std;

Graph createSampleGraph();

// Pass or fail testing
void testGraph();

// Testing Functions for Graph
bool testcheck_vertex();
bool testcheck_edge();
bool testis_empty();
bool testaddEdge();
bool testremoveEdge();
bool testedgeIn();
bool testdeleteVertex();
bool testaddVertex();
bool testBFS();
bool testDFS_VISIT();
bool testDFS();
bool testgetOrdering();

int main()
{
    cout << "Testing Graph: " << endl;
    testGraph();
    return 0;

}
//==============================================================
// createSampleGraph
// Creates and returns a sample graph for testing purposes.
// The graph contains 6 vertices (1 to 6) and the following edges:
// 1 -> 2, 1 -> 4, 2 -> 5, 3 -> 5, 3 -> 6, 4 -> 5, 5 -> 5, 6 -> 6
// PARAMETERS:
// - none
// RETURN VALUE:
// - A Graph object initialized with the sample graph data.
//==============================================================
Graph createSampleGraph() {
    Graph g;
    for (int i = 1; i <= 6; i++) {
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
    return g;
}

//==============================================================
//======================Testing Functions=======================
//==============================================================

//==============================================================
// testcheck_vertex
// Tests the functionality of the check_vertex method in the Graph class.
// Verifies if the method correctly checks for the presence of a vertex in the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testcheck_vertex() {
    Graph g = createSampleGraph();

    // Test if existing vertex is detected
    if (!g.check_vertex(1)) {
        cout << "Error: check_vertex failed to find existing vertex 1" << endl;
        return false;
    }

    // Test if non-existing vertex is correctly reported
    if (g.check_vertex(7)) {
        cout << "Error: check_vertex incorrectly found non-existing vertex 7" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testcheck_edge
// Tests the functionality of the check_edge method in the Graph class.
// Verifies if the method correctly checks for the existence of an edge between two vertices.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testcheck_edge() {
    Graph g = createSampleGraph();

    // Test if existing edge is detected
    if (!g.check_edge(1, 2)) {
        cout << "Error: check_edge failed to find existing edge 1 -> 2" << endl;
        return false;
    }

    // Test if non-existing edge is correctly reported
    if (g.check_edge(2, 4)) {
        cout << "Error: check_edge incorrectly found non-existing edge 2 -> 4" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testis_empty
// Tests the functionality of the is_empty method in the Graph class.
// Verifies if the method correctly identifies whether the graph is empty or not.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testis_empty() {
    Graph g;

    // Test if empty graph is correctly detected
    if (!g.is_empty()) {
        cout << "Error: is_empty failed to detect an empty graph" << endl;
        return false;
    }

    // Test if non-empty graph is correctly reported
    g.addVertex(1);
    if (g.is_empty()) {
        cout << "Error: is_empty incorrectly reported a non-empty graph as empty" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testaddEdge
// Tests the functionality of the addEdge method in the Graph class.
// Verifies if the method correctly adds an edge between two vertices in the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testaddEdge() {
    Graph g = createSampleGraph();

    // Test adding a new edge
    g.addEdge(2, 6);
    if (!g.check_edge(2, 6)) {
        cout << "Error: addEdge failed to add edge 2 -> 6" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testremoveEdge
// Tests the functionality of the removeEdge method in the Graph class.
// Verifies if the method correctly removes an edge between two vertices in the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testremoveEdge() {
    Graph g = createSampleGraph();

    // Test removing an existing edge
    g.removeEdge(1, 2);
    if (g.check_edge(1, 2)) {
        cout << "Error: removeEdge failed to remove edge 1 -> 2" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testedgeIn
// Tests the functionality of the edgeIn method in the Graph class.
// Verifies if the method correctly checks whether a specific edge exists in the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testedgeIn() {
    Graph g = createSampleGraph();

    // Test if a vertex with incoming edges is correctly reported
    if (!g.edgeIn(5)) {
        cout << "Error: edgeIn failed to detect incoming edges for vertex 5" << endl;
        return false;
    }

    // Test if a vertex with no incoming edges is correctly reported
    if (g.edgeIn(1)) {
        cout << "Error: edgeIn incorrectly detected incoming edges for vertex 1" << endl;
        return false;
    }

    return true;
}
//==============================================================
// testdeleteVertex
// Tests the functionality of the deleteVertex method in the Graph class.
// Verifies if the method correctly deletes a vertex and its associated edges from the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testdeleteVertex() {
    Graph g = createSampleGraph();

    // Test deleting an existing vertex
    g.deleteVertex(3);
    if (g.check_vertex(3)) {
        cout << "Error: deleteVertex failed to delete vertex 3" << endl;
        return false;
    }

    // Ensure edges associated with the deleted vertex are also removed
    if (g.check_edge(3, 6)) {
        cout << "Error: deleteVertex failed to remove edge 3 -> 6 associated with deleted vertex" << endl;
        return false;
    }

    return true;
}

//==============================================================
// testaddVertex
// Tests the functionality of the addVertex method in the Graph class.
// Verifies if the method correctly adds a new vertex to the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testaddVertex() {
    Graph g = createSampleGraph();

    // Test adding a new vertex
    g.addVertex(7);
    if (!g.check_vertex(7)) {
        cout << "Error: addVertex failed to add vertex 7" << endl;
        return false;
    }

    return true;
}
//==============================================================
// testBFS
// Tests the functionality of the BFS (Breadth-First Search) method in the Graph class.
// Verifies if the method correctly performs a breadth-first traversal of the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testBFS() {
    Graph g = createSampleGraph();
    vector<int> bfsResult = g.breadthFirstSearch(1);
    vector<int> expected = {1, 2, 4, 5, 3, 6};

    // Compare BFS result to expected
    if (bfsResult != expected) {
        cout << "Error: BFS result does not match expected. Got: ";
        for (int v : bfsResult) cout << v << " ";
        cout << endl;
        return false;
    }

    return true;
}
//==============================================================
// testDFS
// Tests the functionality of the DFS (Depth-First Search) method in the Graph class.
// Verifies if the method correctly performs a depth-first traversal of the graph.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testDFS() {
    Graph g = createSampleGraph();
    vector<int> dfsResult = g.depthFirstSearch(1);
    vector<int> expected = {1, 2, 5, 4, 3, 6};

    // Compare DFS result to expected
    if (dfsResult != expected) {
        cout << "Error: DFS result does not match expected. Got: ";
        for (int v : dfsResult) cout << v << " ";
        cout << endl;
        return false;
    }

    return true;
}

//==============================================================
// testgetOrdering
// Tests the functionality of the getOrdering method in the Graph class.
// Verifies if the method correctly returns the order of vertices after a traversal or search operation.
// PARAMETERS:
// - none
// RETURN VALUE:
// - Returns true if the test passes, false if it fails.
//==============================================================
bool testgetOrdering()
{
    Graph g = createSampleGraph();

    vector<int> ordering = g.getOrdering();

    vector<int> expected_order = {1, 2, 4, 5, 3, 6};

    // Check if the ordering matches the expected result
    if (ordering != expected_order)
    {
        cout << "Error: getOrdering failed. Expected ordering: ";
        for (int vertex : expected_order)
        {
            cout << vertex << " ";
        }
        cout << ", but got: ";
        for (int vertex : ordering)
        {
            cout << vertex << " ";
        }
        cout << endl;
        return false;
    }

    return true;
}

//==============================================================
// testGraph
// Testing functions and respective outputs for Graph class.
// Updates and outputs the tally of passed and failed tests.
// PARAMETERS:
// - none
// RETURN VALUE:
// - none
//==============================================================
void testGraph()
{
    struct TestResult
    {
        int passed;
        int failed;
    };
    TestResult graph_result = {0, 0};

    // Test check_vertex function
    if (testcheck_vertex())
    {
        cout << "testcheck_vertex passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testcheck_vertex failed" << endl;
        graph_result.failed++;
    }

    // Test check_edge function
    if (testcheck_edge())
    {
        cout << "testcheck_edge passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testcheck_edge failed" << endl;
        graph_result.failed++;
    }

    // Test is_empty function
    if (testis_empty())
    {
        cout << "testis_empty passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testis_empty failed" << endl;
        graph_result.failed++;
    }

    // Test addEdge function
    if (testaddEdge())
    {
        cout << "testaddEdge passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testaddEdge failed" << endl;
        graph_result.failed++;
    }

    // Test removeEdge function
    if (testremoveEdge())
    {
        cout << "testremoveEdge passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testremoveEdge failed" << endl;
        graph_result.failed++;
    }

    // Test edgeIn function
    if (testedgeIn())
    {
        cout << "testedgeIn passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testedgeIn failed" << endl;
        graph_result.failed++;
    }

    // Test deleteVertex function
    if (testdeleteVertex())
    {
        cout << "testdeleteVertex passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testdeleteVertex failed" << endl;
        graph_result.failed++;
    }

    // Test addVertex function
    if (testaddVertex())
    {
        cout << "testaddVertex passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testaddVertex failed" << endl;
        graph_result.failed++;
    }

    // Test BFS function
    if (testBFS())
    {
        cout << "testBFS passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testBFS failed" << endl;
        graph_result.failed++;
    }

    // Test DFS function
    if (testDFS())
    {
        cout << "testDFS passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testDFS failed" << endl;
        graph_result.failed++;
    }
    if (testgetOrdering())
    {
        cout << "testgetOrdering passed" << endl;
        graph_result.passed++;
    }
    else
    {
        cout << "testgetOrdering failed" << endl;
        graph_result.failed++;
    }

    // Output the final tally of passed and failed tests
    cout << "Graph Tests Passed: " << graph_result.passed << endl;
    cout << "Graph Tests Failed: " << graph_result.failed << endl;
    cout << endl;
};



