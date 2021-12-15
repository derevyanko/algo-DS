#include <iostream>

using namespace std;

#include "hashTable.cpp"

int main(){

    HashMapTable ht;

    // Declare the data to be stored in the hash table:
    int arr[] = {2, 4, 6, 8, 10};

    // Insert the whole data into the hash table:
    for (int i = 0; i < 5; i++)
        ht.insert(arr[i], i);

    cout << "..:: Hash Table ::.." << "\n";
    ht.print();

    ht.remove(4);
    cout << "\n"
         << "..:: After deleting 4 ::.." << "\n";
    ht.print();

    return 0;
}