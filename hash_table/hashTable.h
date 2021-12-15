const int T_S = 20;

struct HashTableEntry {
    int key, value;
    HashTableEntry *next;

    HashTableEntry(int key, int value);
};

class HashMapTable {
private:
    int table_size;

    // hash function
    int hashFunc(int key);
public:
    HashTableEntry** table;

    // constructor
    HashMapTable();

    void insert(int key, int value);

    void remove(int key);

    void find(int key);

    void print();

    ~HashMapTable();
};