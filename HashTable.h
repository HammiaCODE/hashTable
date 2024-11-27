#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

enum CollisionResolution {
    LINEAR_PROBING,
    QUADRATIC_PROBING
};

class HashTable {
private:
    vector<int> table; // Tabla hash
    int tableSize;     // Tamaño de la tabla
    int numElements;   // Número de elementos en la tabla
    CollisionResolution collisionResolutionMethod;

    int hashFunction(int key) const;

    int linearProbing(int key, int attempt) const;
    int quadraticProbing(int key, int attempt) const;

    void rehash();

public:
    // Constructor
    HashTable(int size, CollisionResolution method);

    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif // HASHTABLE_H