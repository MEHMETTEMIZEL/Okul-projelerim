//
// Created by student on 23.11.2018.
//

#ifndef PROJECT3_TARJANSCC_H
#define PROJECT3_TARJANSCC_H

#include <iostream>
#include <list>
#include <stack>
#include <unordered_set>
using namespace std;
class tarjanSCC {
public:
    unordered_set<int> sccRoots;

    string output;
    int unvisited;

    int numOfNodes;


    int** graph;
    int* numOfKeys;

    int id;
    int sccCount;

    int* idsInverse;
    int* ids;
    int* low;


    bool* onStack;
    stack<int> myStack;

    void travelToKeys(int at);
    void dfs(int at);
    void funcForFindSccs();
    tarjanSCC(int numOfNodes,string output);
    ~tarjanSCC();

};

#endif //PROJECT3_TARJANSCC_H
