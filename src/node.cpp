#include "node.h"

// Wezel
Node::Node(int fr) : frequency(fr) {}

int Node::getFrequency() const {
    return frequency; // Zwraca czestotliwosc
}

// Lisc
LeafNode::LeafNode(int ch, int fr) : Node(fr), character(ch) {}

// Sprawdza czy jest lisciem
bool LeafNode::isLeaf() const {
    return true;
}
// Jesli tak to zwraca znak
char LeafNode::getCharacter() const {
    return character; // Zwraca znak
}

std:;ostream& operator<<(std::ostream& os, LeafNode& leaf) {
    os << "'" << leaf.character << "'(" << leaf.frequency << ")";
}

// Wewnetrzne wezly
InternalNode::InternalNode(std::shared_ptr<Node> l, std::shared_ptr<Node> r) : Node(l->getFrequency() + p -> getFrequency()), left(l), right(p) {}

bool LeafNode::isLeaf() const {
    return false;
}

std::shared_ptr<Wezel> InternalNode::getLeft() const { return left; }
std::shared_ptr<Wezel> InternalNode::getRight() const { return right; }
