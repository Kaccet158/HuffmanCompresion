#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>
#include <memory>

// Klasa wezla w drzewie
class Node {
    protected:
        int frequency; // Czestotliwosc
    public:
        Node(int fr); // Konstruktor
        virtual ~Node() = default; // Destruktor
        int getFrequency() const; // Metoda ile wystapien
        virtual bool isLeaf() const = 0; // Metoda abstrakcyjna
};

// Klasa Liscia w Wezle
class LeafNode : public Node {
    private:
        char character; // Znak w drzewie
    public:
        LeafNode(int ch, int fr); // Konstruktor ile wystapien dla danego znaku
        bool isLeaf() const override; // Musimy nadpisac, bo juz nasz rodzic ma klase abstrakcyjne
        char getCharacter() const; // Metoda dostania znaku
        friend std::ostream& operator<<(std::ostream& os, const LeafNode& leaf); // Przyjaciel i nadanie std::cout skrotu os
};

// Klasa poloczenai dwoch wezlow wewnetrznych
class InternalNode : public Node {
    private:
        std::shared_ptr<Node> left; // Pointer na lewe dziecko
        std::shared_ptr<Node> right; // Pointer na prawe
    public:
        InternalNode(std::shared_ptr<Node> l, std::shared_ptr<Node> r); // Konstruktor, ktory bedzie wskazywac nam na te dzieci
        bool isLeaf() const override; // Tez musi sprawdzic czy lisciem
        std::shared_ptr<Node> getLeft() const; // Dostanie lewe dziecko
        std::shared_ptr<Node> getRight() const; // Dostanei prawe dziecko
};

#endif
