#include "HashTable.h"

int main() {

    cout <<"-------------------------------------------------------------------------------------"<<endl;
    cout << "Linear Probing"<<endl;

    cout << "Size of the Hash table: ";
    int sizeHash;
    cin >> sizeHash;
    HashTable hashTableLinear(sizeHash, LINEAR_PROBING);

    int keyHash;
    int numItems;
    int busqueda;
    int check;

    cout << "How many elements you want to insert?: ";
    cin >> numItems;

    for(int i = 0; i < numItems; i++) {
        hashTableLinear.insert(keyHash);
    }

    hashTableLinear.display();
    cout << "What element are you looking for?: ";
    cin >> busqueda;

    if (busqueda==hashTableLinear.search(keyHash)) {
        cout << "Looking for element: " << (hashTableLinear.search(keyHash) ? "Found it!" : "Not found :(") << endl;
        cout << "Type 1 to remove an element or type 2 to leave" << endl;
        if(check==1) {
            hashTableLinear.remove(keyHash);
            cout << "New hash table";
            hashTableLinear.display();
        }else{
            return 0;
        }
    }

    cout <<"-------------------------------------------------------------------------------------"<<endl;

    cout << "Quadratic Probing";
    HashTable hashTableQuadratic(sizeHash, QUADRATIC_PROBING);

    cout << "How many elements you want to insert?: ";
    cin >> numItems;

    for(int i = 0; i < numItems; i++) {
        hashTableQuadratic.insert(keyHash);
    }

    hashTableQuadratic.display();
    cout << "What element are you looking for?: ";
    cin >> busqueda;

    if (busqueda==hashTableQuadratic.search(keyHash)) {
        cout << "Looking for element: " << (hashTableQuadratic.search(keyHash) ? "Found it!" : "Not found :(") << endl;
        cout << "Type 1 to remove an element or type 2 to leave" << endl;
        if(check==1) {
            hashTableQuadratic.remove(keyHash);
            cout << "New hash table";
            hashTableQuadratic.display();
        }else{
            return 0;
        }
    }

}
