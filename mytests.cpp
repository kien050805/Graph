// //========================================================
// // mytests.cpp 
// // James Bui & Kien Le & Trinity Meckel 
// // December 9, 2024
// //
// // Description:
// // This file contains the tests cases for the Graph class
// //========================================================
#include "Graph.hpp"
#include <iostream>
#include <cassert>

using namespace std;

// Function prototypes for tests
void test_addVertex(int &testPassed, int &testFailed);
void test_addEdge(int &testPassed, int &testFailed);
void test_removeEdge(int &testPassed, int &testFailed);
void test_deleteVertex(int &testPassed, int &testFailed);
void test_edgeIn(int &testPassed, int &testFailed);
void test_breadthFirstSearch(int &testPassed, int &testFailed, Graph& g);
void test_depthFirstSearch(int &testPassed, int &testFailed, Graph& g);
void test_getOrdering(int &testPassed, int &testFailed, Graph& g);
void test_readFromSTDIN(int &testPassed, int &testFailed, Graph& g);

int main() {
    int testPassed = 0;
    int testFailed = 0;

    // Initialize the graph from standard input
    Graph g;
    g.readFromSTDIN();

    // Run the tests
    test_addVertex(testPassed, testFailed);
    test_addEdge(testPassed, testFailed);
    test_removeEdge(testPassed, testFailed);
    test_deleteVertex(testPassed, testFailed);
    test_edgeIn(testPassed, testFailed);
    test_breadthFirstSearch(testPassed, testFailed, g);
    test_depthFirstSearch(testPassed, testFailed, g);
    test_getOrdering(testPassed, testFailed, g);
    test_readFromSTDIN(testPassed, testFailed, g);

    cout << "Total Tests: " << testPassed + testFailed << endl;
    cout << "Tests Passed: " << testPassed << endl;
    cout << "Tests Failed: " << testFailed << endl;

    return 0;
}

//=========================================================
// Test addVertex
// Purpose:
//  - Ensure vertices are added correctly to the graph.
//=========================================================
void test_addVertex(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(9);
        assert(!g.edgeIn(9, 1)); // Ensure no edges exist
        testPassed++;
        cout << "Passed test_addVertex" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_addVertex: Exception caught" << endl;
    }
}

//=========================================================
// Test addEdge
// Purpose:
//  - Ensure edges are added correctly between existing vertices.
//=========================================================
void test_addEdge(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addEdge(1, 2);
        assert(g.edgeIn(1, 2));
        testPassed++;
        cout << "Passed test_addEdge" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_addEdge: Exception caught" << endl;
    }
}

//=========================================================
// Test removeEdge
// Purpose:
//  - Ensure edges are removed correctly, and exceptions are handled.
//=========================================================
void test_removeEdge(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addEdge(1, 2);
        g.removeEdge(1, 2);
        assert(!g.edgeIn(1, 2));
        testPassed++;
        cout << "Passed test_removeEdge" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_removeEdge: Exception caught" << endl;
    }
}

//=========================================================
// Test deleteVertex
// Purpose:
//  - Ensure vertices and associated edges are removed correctly.
//=========================================================
void test_deleteVertex(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addEdge(1, 2);
        g.deleteVertex(1);
        assert(!g.edgeIn(1, 2));
        testPassed++;
        cout << "Passed test_deleteVertex" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_deleteVertex: Exception caught" << endl;
    }
}

//=========================================================
// Test edgeIn
// Purpose:
//  - Verify edge existence checking.
//=========================================================
void test_edgeIn(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addEdge(1, 2);
        assert(g.edgeIn(1, 2));
        assert(!g.edgeIn(2, 1));
        testPassed++;
        cout << "Passed test_edgeIn" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_edgeIn: Exception caught" << endl;
    }
}

//=========================================================
// Test breadthFirstSearch
// Purpose:
//  - Verify BFS traversal and distance computation.
//=========================================================
void test_breadthFirstSearch(int &testPassed, int &testFailed, Graph& g) {
    try {
        auto bfs = g.breadthFirstSearch(1);
        assert(bfs[1].first == 0);  // Distance to itself
        assert(bfs[2].first == 1);  // Distance to 2
        assert(bfs[3].first == 1);  // Distance to 3
        testPassed++;
        cout << "Passed test_breadthFirstSearch" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_breadthFirstSearch: Exception caught" << endl;
    }
}

//=========================================================
// Test depthFirstSearch
// Purpose:
//  - Verify DFS traversal and parent computation.
//=========================================================
void test_depthFirstSearch(int &testPassed, int &testFailed, Graph& g) {
    try {

        auto dfs = g.depthFirstSearch();
        assert(get<0>(dfs[1]) != 0);  // Discovery time for vertex 1
        testPassed++;
        cout << "Passed test_depthFirstSearch" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_depthFirstSearch: Exception caught" << endl;
    }
}

//=========================================================
// Test getOrdering
// Purpose:
//  - Verify topological ordering computation.
//=========================================================
void test_getOrdering(int &testPassed, int &testFailed, Graph& g) {
    try {
        auto order = g.getOrdering();
        assert(!order.empty());
        testPassed++;
        cout << "Passed test_getOrdering" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_getOrdering: Exception caught" << endl;
    }
}

//=========================================================
// Test readFromSTDIN
// Purpose:
//  - Verify graph initialization from input.
//=========================================================
void test_readFromSTDIN(int &testPassed, int &testFailed, Graph& g) {
    try {
        assert(g.edgeIn(1, 2));
        assert(g.edgeIn(4, 6));
        assert(!g.edgeIn(7, 8)); // Edge that shouldn't exist
        testPassed++;
        cout << "Passed test_readFromSTDIN" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_readFromSTDIN: Exception caught" << endl;
    }
}