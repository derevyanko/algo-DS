#include "hashTable.h"

HashTableEntry::HashTableEntry(int k, int v) {
    this->key = k;
    this->value = v;
    this->next = nullptr;
}

HashMapTable::HashMapTable() {
    table_size = T_S;
    table = new HashTableEntry *[table_size];
    for (int i = 0; i < table_size; i++)
        table[i] = nullptr;
}

int HashMapTable::hashFunc(int key) {
    return key % table_size;
}

void HashMapTable::insert(int key, int value) {
    int hash_v = hashFunc(key);
    HashTableEntry* prev = nullptr;
    HashTableEntry* entry = table[hash_v];

    while (entry != nullptr) {
        prev = entry;
        entry = entry->next;
    }

    if (entry == nullptr) {
        entry = new HashTableEntry(key, value);
        if (prev == nullptr) {
            table[hash_v] = entry;
        } else {
            prev->next = entry;
        }
    } else {
        entry->value = value;
    }
}

void HashMapTable::remove(int key) {
    int hash_v = hashFunc(key);
    HashTableEntry** entry = &table[hash_v];
    HashTableEntry* prev = nullptr;
    cout << entry << " " << (*entry)->key << "\n";

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

    this->print();

    cout << "Element Deleted" << "\n";
}

void HashMapTable::find(int key) {
    int hash_v = hashFunc(key);
    bool flag = false;
    HashTableEntry *entry = table[hash_v];

    if (entry != nullptr) {
        while (entry != nullptr) {
            if (entry->key == key) {
                flag = true;
            }
            if (flag) {
                cout << "Element found at key " << key << ": ";
                cout << entry->value << "\n";
            }
            entry = entry->next;
        }
    }

    if (!flag)
        cout << "No Element found at key " << key << "\n";
}

void HashMapTable::print() {
    for (int i = 0; i < table_size; i++) {
        if (table[i] != nullptr) {
            cout << &table[i] << ' ';
            cout << "Key: " << table[i]->key << " Value: " << table[i]->value << "\n";
        }
    }
}

HashMapTable::~HashMapTable() {
    delete[] table;
}