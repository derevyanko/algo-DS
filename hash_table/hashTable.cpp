#include "hashTable.h"

const int T_S = 32;

HashTableEntry::HashTableEntry(int k, int v) {
    this->key = k;
    this->value = v;
    this->next = nullptr;
}

HashMapTable::HashMapTable() {
    buffer_size = T_S;
    size = 0;
    table = new HashTableEntry *[buffer_size];
    for (int i = 0; i < buffer_size; i++)
        table[i] = nullptr;
}

int HashMapTable::hashFunc(int key) {
    return key % buffer_size;
}

void HashMapTable::resize() {
    int past_buffer_size = buffer_size;
    buffer_size *= 2;
    HashTableEntry** table2 = new HashTableEntry* [buffer_size];
    size = 0;
    for (int i = 0; i < buffer_size; i++)
        table2[i] = nullptr;

    swap(table, table2);

    for (int i = 0; i < past_buffer_size; i++) {
        if (table2[i])
            insert(table2[i]->key, table2[i]->value);
    }

    for (int i = 0; i < past_buffer_size; i++)
        if (table2[i])
            delete table2[i];

    delete[] table2;
}

void HashMapTable::insert(int key, int value) {
    if (size + 1 >= buffer_size * load_factor) {
        resize();
    }

    int hash_v = hashFunc(key);
    HashTableEntry* prev = nullptr;
    HashTableEntry** entry = &table[hash_v];

    while ((*entry) != nullptr) {
        prev = (*entry);
        (*entry) = (*entry)->next;
    }

    if ((*entry) == nullptr) {
        (*entry) = new HashTableEntry(key, value);
        if (prev == nullptr) {
            table[hash_v] = (*entry);
        } else {
            prev->next = (*entry);
        }
    } else {
        (*entry)->value = value;
    }

    size++;
}

void HashMapTable::remove(int key) {
    int hash_v = hashFunc(key);
    HashTableEntry** entry = &table[hash_v];
    HashTableEntry* prev = nullptr;

    if ((*entry) == nullptr || (*entry)->key != key) {
        cout << "No Element found at key " << key << "\n";
        return;
    }

    while ((*entry)->next != nullptr) {
        prev = (*entry);
        (*entry) = (*entry)->next;
    }
    
    if (prev != nullptr) {
        prev->next = (*entry)->next;
    }

    (*entry) = nullptr;

    cout << "Element Deleted" << "\n";
}

void HashMapTable::find(int key) {
    int hash_v = hashFunc(key);
    bool flag = false;
    HashTableEntry** entry = &table[hash_v];

    if ((*entry) != nullptr) {
        while ((*entry) != nullptr) {
            if ((*entry)->key == key) {
                flag = true;
            }
            if (flag) {
                cout << "Element found at key " << key << ": ";
                cout << (*entry)->value << "\n";
            }
            (*entry) = (*entry)->next;
        }
    }

    if (!flag)
        cout << "No Element found at key " << key << "\n";
}

void HashMapTable::print() {
    HashTableEntry** entry;
    for (int i = 0; i < buffer_size; i++) {
        if (table[i])
            cout << "Key: " << table[i]->key << " Value: " << table[i]->value << "\n";
    }
}

HashMapTable::~HashMapTable() {
    delete[] table;
}