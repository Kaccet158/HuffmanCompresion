# Projekt Kompresji Huffmana
Program pozwala skompresować binarnie plik za pomocą algorytmu Huffmana. 

Aby skompilować i uruchomić: 

```
g++ -std=c++17 src/main.cpp src/node.cpp -I include -o huffman && ./huffman
```

Lub przez CMake: 
Kompilacja:
```
cd /Users/kacpe/HuffmanCompresion
mkdir -p build
cd build
cmake ..
make
```
Uruchomienie:
```
./huffman
```
