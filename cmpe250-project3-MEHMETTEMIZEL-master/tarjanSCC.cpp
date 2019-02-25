//
// Created by student on 23.11.2018.
//

#include "tarjanSCC.h"
#include <stack>
#include <fstream>

tarjanSCC::tarjanSCC(int _numOfNodes, string _output) {
    unvisited = -1;
    numOfNodes = _numOfNodes;

    graph = new int *[numOfNodes + 1];       // Holds keys inside a bank


    numOfKeys = new int[numOfNodes + 1];    //Holds key number inside a bank

    ids = new int[numOfNodes + 1];
    low = new int[numOfNodes + 1];
    onStack = new bool[numOfNodes + 1];


    sccCount = 0;
    id = 1;

    idsInverse = new int[numOfNodes + 1];

    output = _output;
}

void tarjanSCC::dfs(int at) {
    myStack.push(at);
    onStack[at] = true;
    ids[at] = id;
    idsInverse[id] = at;
    low[at] = id;
    id++;

    int k = ids[at];
    int l = low[at];
    //cout<< at << " " << onStack[at]<<endl;

    int i;
    //visit all neighbours & min low-link on callback
    for (i = 0; i < numOfKeys[at]; i++) {
        if (ids[(graph[at])[i]] == unvisited) {
            dfs(graph[at][i]);
            low[at] = min(low[at], low[graph[at][i]]);
            k = ids[at];
            l = low[at];
        } else if (onStack[graph[at][i]]) {
            low[at] = min(low[at], ids[graph[at][i]]);
            k = ids[at];
            l = low[at];
        }

    }
    k = ids[at];
    l = low[at];

    if (ids[at] == low[at]) {

        for (int node = myStack.top();; node = myStack.top()) {

            myStack.pop();
            onStack[node] = false;

            low[node] = ids[at];
            if (node == at) break;

        }
        sccRoots.insert(low[at]);

        sccCount++;
    }
    /*rootOfLow[low[at]]=at;
    while(true){
        int node=myStack.top();
        myStack.pop();
        low[node]=ids[at];
        onStack[node]= false;

        if( node== at ) {
            break;
        }
    }
    sccCount++;
}*/
}

void tarjanSCC::travelToKeys(int at) {
    if (onStack[at])
        return;

    for (int i = 0; i < numOfKeys[at]; i++) {
        if (low[graph[at][i]] != low[at]) {
            sccRoots.erase(low[graph[at][i]]);          // erasing non existent element?
            travelToKeys(graph[at][i]);
            onStack[at] = true;
        }
    }

}

void tarjanSCC::funcForFindSccs() {

    for (int i = 1; i < numOfNodes + 1; i++) {
        ids[i] = unvisited;
    }
    for (int i = 1; i < numOfNodes + 1; i++) {
        if (ids[i] == unvisited) {
            dfs(i);
        }
    }
    for (int i = 1; i <= numOfNodes; i++) {
        travelToKeys(i);
    }

    ofstream out(output);
    out << sccRoots.size() << " ";

    unordered_set<int>::iterator it = sccRoots.begin();
    unordered_set<int>::iterator end = sccRoots.end();
    while (it != end) {
        out << idsInverse[*it] << " ";

        it++;
    }

    out.close();

}


tarjanSCC::~tarjanSCC() {

}
