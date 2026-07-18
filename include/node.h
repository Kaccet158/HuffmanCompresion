#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>

class Node {
    protected:
        int frequency;
    public:
        Wezel(int fr); // Konstruktor
        virtual ~Wezel() = default // Destruktor
        int getFrequency() const; // Metoda ile wystapien
        virtual bool isLeaf() const = 0; // Metoda na razie wirtualna
};

class

#endif
