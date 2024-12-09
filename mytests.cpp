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
void test_breadthFirstSearch(int &testPassed, int &testFailed);
void test_depthFirstSearch(int &testPassed, int &testFailed);
void test_getOrdering(int &testPassed, int &testFailed);
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
    test_breadthFirstSearch(testPassed, testFailed);
    test_depthFirstSearch(testPassed, testFailed);
    test_getOrdering(testPassed, testFailed);
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
//  - Verify BFS traversal and distance computation with a specific graph input.
//=========================================================
void test_breadthFirstSearch(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);
        g.addVertex(5);
        g.addVertex(6);

        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(3, 5);
        g.addEdge(3, 6);
        g.addEdge(4, 5);
        g.addEdge(5, 5); // Self-loop on vertex 5
        g.addEdge(6, 6); // Self-loop on vertex 6

        // Perform BFS starting from vertex 1
        auto bfs = g.breadthFirstSearch(1);

        // Verify distances
        assert(bfs[1].first == 0); // Distance to itself
        assert(bfs[2].first == 1); // Distance to vertex 2
        assert(bfs[4].first == 1); // Distance to vertex 4
        assert(bfs[5].first == 2); // Distance to vertex 5
        assert(bfs[3].first == -1); // Vertex 3 is not reachable
        assert(bfs[6].first == -1); // Vertex 6 is not reachable

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
void test_depthFirstSearch(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);
        g.addVertex(5);
        g.addVertex(6);

        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(3, 5);
        g.addEdge(3, 6);
        g.addEdge(4, 5);
        g.addEdge(5, 5); // Self-loop on vertex 5
        g.addEdge(6, 6); // Self-loop on vertex 6

        auto dfs = g.depthFirstSearch();
        // Verify discovery and finish times for key vertices
        assert(get<0>(dfs[1]) < get<1>(dfs[1])); // Vertex 1: Discovery < Finish
        assert(get<0>(dfs[2]) < get<1>(dfs[2])); // Vertex 2: Discovery < Finish
        assert(get<0>(dfs[4]) < get<1>(dfs[4])); // Vertex 4: Discovery < Finish
        assert(get<0>(dfs[5]) < get<1>(dfs[5])); // Vertex 5: Discovery < Finish
        assert(get<0>(dfs[3]) < get<1>(dfs[3])); // Vertex 3: Discovery < Finish
        assert(get<0>(dfs[6]) < get<1>(dfs[6])); // Vertex 6: Discovery < Finish

        // Verify relative discovery order
        assert(get<0>(dfs[1]) < get<0>(dfs[2])); // Vertex 1 discovers Vertex 2
        assert(get<0>(dfs[1]) < get<0>(dfs[4])); // Vertex 1 discovers Vertex 4
        assert(get<0>(dfs[2]) < get<0>(dfs[5])); // Vertex 2 discovers Vertex 5
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
void test_getOrdering(int &testPassed, int &testFailed) {
    try {
        Graph g;
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);
        g.addVertex(5);
        g.addVertex(6);

        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(3, 5);
        g.addEdge(3, 6);
        g.addEdge(4, 5);
        g.addEdge(5, 5); // Self-loop on vertex 5
        g.addEdge(6, 6); // Self-loop on vertex 6

        auto order = g.getOrdering();
        assert(order.empty());
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
        assert(g.edgeIn(1, 2)); // Edge exists
        assert(g.edgeIn(1, 4)); // Edge exists
        assert(g.edgeIn(2, 5)); // Edge exists
        assert(g.edgeIn(3, 5)); // Edge exists
        assert(g.edgeIn(3, 6)); // Edge exists
        assert(g.edgeIn(4, 5)); // Edge exists
        assert(g.edgeIn(5, 5)); // Self-loop exists
        assert(g.edgeIn(6, 6)); // Self-loop exists
        assert(!g.edgeIn(1, 3)); // Edge that shouldn't exist
        assert(!g.edgeIn(2, 6)); // Edge that shouldn't exist
        testPassed++;
        cout << "Passed test_readFromSTDIN" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_readFromSTDIN: Exception caught" << endl;
    }
}