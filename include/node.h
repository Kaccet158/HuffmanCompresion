#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>
#include <memory>

class Node {
    protected:
        int frequency;
    public:
        Wezel(int fr); // Konstruktor
        virtual ~Wezel() = default; // Destruktor
        int getFrequency() const; // Metoda ile wystapien
        virtual bool isLeaf() const = 0; // Metoda na razie wirtualna
};

class LeafNode : public Node {
    private:
        char character;
    public;
        LeafNode(int ch, int fr); // Konstruktor ile wystapien dla danego znaku
        bool isLeaf() const override; // Musimy nadpisac, bo juz nasz rodzic ma klase abrkacyjne
        char getChar() const; // Metoda dostania znaku
        friend std::ostream& operator<<(std::ostream& os, const LeafNode& leaf); // Przyjaciel i nadanie std::cout skrotu os

};

#endif
