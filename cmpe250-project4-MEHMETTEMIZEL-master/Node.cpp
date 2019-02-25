#include "Node.h"

Node::Node(int _xCoor, int _yCoor, int _height, int _shortestPath) {
    this->xCoor = _xCoor;
    this->yCoor = _yCoor;
    this->height = _height;
    this->shortestPath = _shortestPath;
}

Node::Node() {}


Node::Node(const Node &node) {
    this->xCoor = node.xCoor;
    this->yCoor = node.yCoor;
    this->height = node.height;
    this->shortestPath = node.shortestPath;

}

Node &Node::operator=(const Node &node) {
    this->xCoor = node.xCoor;
    this->yCoor = node.yCoor;
    this->height = node.height;
    this->shortestPath = node.shortestPath;

    return *this;
}


bool Node::operator<(const Node &node)const {
    return this->shortestPath > node.shortestPath;
}

// buyuktur
bool Node::operator>(const Node &node) const {
    return this->shortestPath > node.shortestPath;
}


