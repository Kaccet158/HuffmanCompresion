#include "node.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// Funkcja rekurencyjna do czytania drzewa i nadawania 0 i 1
void generateCodes(std::shared_ptr<Node> node, const std::string& path, std::map<char, std::string>& codes) {
    if (!node) return;

    if (node->isLeaf()) {
        auto leaf = std::dynamic_pointer_cast<LeafNode>(node);
        codes[leaf->getCharacter()] = path;

        // Prezentacja przeciarzonego operatora
        std::cout << "Kod dla: " << *leaf << " -> " << path << "\n";
        return;
    }

    auto internal = std::dynamic_pointer_cast<InternalNode>(node);
    generateCodes(internal->getLeft(), path + "0", codes);
    generateCodes(internal->getRight(), path + "1", codes);
}

int main() {

    std::string text = "KAJAK";
    std::cout << "Tekst: " << text << "\n\n";

    // Wpisanie wszystkich znakow z pliku
    std::array<int,256> frequency{}; // Tablica wystapien dla wszystkich znakow
    for(char ch : text) {
        // Zliczanie wysatpien kazdego znaku, nawet jak jest to 0
        frequency[static_cast<unsigned char>(ch)]++; // Zamieniamy na bezpieczny typ dodatni
    }

    // Odflirtowanie tych liter, ktore w ogole nie wystepuja w tekscie
    std::vector<std::shared_ptr<Node>> nodes;
    for(int i = 0; i < 256; i++) {
        if(frequency[i] > 0) {
            nodes.push_back(std::make_shared<LeafNode>(static_cast<char>(i), frequency[i]));
        }
    }

    // W przypadku pustego wektora - rzuc blad
    if(nodes.empty()) {
        std::cerr << "Blad: Brak znakow do skompresowania\n";
        return 1;
    }

    // Budowanie drzewa Huffmana laczenie wezlow
    while(nodes.size() > 1) {
        std::sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b) {
            return a->getFrequency() > b->getFrequency();
        });

        auto right = nodes.back(); nodes.pop_back();
        auto left  = nodes.back(); nodes.pop_back();

        auto parent = std::make_shared<InternalNode>(left, right);
        nodes.push_back(parent);
    }

    std::shared_ptr<Node> root = nodes[0];

    // Tworzenie mapy kodow
    std::map<char, std::string> huffmanCodes;
    std::cout << "Kody Huffmana dla poszczegolnych liter: \n";
    generateCodes(root, "", huffmanCodes);

    // Kompresowanie tekstu - efekt koncowy
    std::string compressed = "";
    for(char c : text) {
        compressed += huffmanCodes[c];
    }

    std::cout << "\nWyniki kompresji: \n";
    std::cout << "Skompresowany tekst bitowy: " << compressed << "\n";
    std::cout << "Rozmiar przed: " << text.length() * 8 << " bitow\n";
    std::cout << "Rozmiar po: " << compressed.length() << " bitow\n";

    return 0;
}
