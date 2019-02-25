#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    int xCoor;
    int yCoor;
    int height;
    int shortestPath;

    Node();

    Node(int _xCoor, int _yCoor, int _height, int _shortestPath);

    Node(const Node &node);

    Node &operator=(const Node &node);

    bool operator<(const Node &node)const;

    bool operator>(const Node &node) const;

};

#endif
