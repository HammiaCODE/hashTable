#include "HashTable.h"

// Constructor
HashTable::HashTable(int size, CollisionResolution method)
    : tableSize(size), numElements(0), collisionResolutionMethod(method) {
    table.resize(tableSize, -1); // Inicializa la tabla con -1 (vacío)
}

// Hash function
int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

// Linear Probing: (hash + i) % size
int HashTable::linearProbing(int key, int attempt) const {
    return (hashFunction(key) + attempt) % tableSize;
}

// Quadratic Probing: (hash + i^2) % size
int HashTable::quadraticProbing(int key, int attempt) const {
    return (hashFunction(key) + attempt * attempt) % tableSize;
}

// Rehash
void HashTable::rehash() {
    vector<int> oldTable = table; // Copia de la tabla actual
    tableSize *= 2;              // Duplicar el tamaño de la tabla
    table.resize(tableSize, -1); // Nueva tabla vacía
    numElements = 0;

    // Reinsertar elementos
    for (int key : oldTable) {
        if (key != -1 && key != -2) { // Ignorar posiciones vacías y eliminadas
            insert(key);
        }
    }
}

// Insert
void HashTable::insert(int key) {
    if ((double)numElements / tableSize >= 0.7) {
        rehash(); // Realizar rehash si el factor de carga supera el 70%
    }

    int attempt = 0;
    int index;
    do {
        index = (collisionResolutionMethod == LINEAR_PROBING)
                    ? linearProbing(key, attempt)
                    : quadraticProbing(key, attempt);
        attempt++;
    } while (table[index] != -1 && table[index] != -2); // Repite si ocupado o borrado

    table[index] = key;
    numElements++;
}

// Busqueda
bool HashTable::search(int key) const {
    int attempt = 0;
    int index;
    do {
        index = (collisionResolutionMethod == LINEAR_PROBING)
                    ? linearProbing(key, attempt)
                    : quadraticProbing(key, attempt);

        if (table[index] == key) {
            return true; // Encontrado
        }
        attempt++;
    } while (table[index] != -1 && attempt < tableSize);

    return false; // No encontrado
}

// Eliminar
void HashTable::remove(int key) {
    int attempt = 0;
    int index;
    do {
        index = (collisionResolutionMethod == LINEAR_PROBING)
                    ? linearProbing(key, attempt)
                    : quadraticProbing(key, attempt);

        if (table[index] == key) {
            table[index] = -2; // Marca como eliminado
            numElements--;
            return;
        }
        attempt++;
    } while (table[index] != -1 && attempt < tableSize);
}

// Mostrar la tabla hash
void HashTable::display() const {
    for (int i = 0; i < tableSize; ++i) {
        cout << "Index " << i << ": ";
        if (table[i] == -1) {
            cout << "Empty!!!";
        } else if (table[i] == -2) {
            cout << "Elimminated";
        } else {
            cout << table[i];
        }
        cout << "\n";
    }
}