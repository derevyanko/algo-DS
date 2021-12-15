struct HashTableEntry {
    int key, value;
    HashTableEntry *next;

    HashTableEntry(int key, int value);
};

class HashMapTable {
private:
    HashTableEntry** table;
    int buffer_size;
    int size;

    double load_factor = 0.75;

    // hash function
    int hashFunc(int key);

    // resize hashMapTable
    void resize();
public:
    // constructor
    HashMapTable();

    // add element
    void insert(int key, int value);

    // remove element
    void remove(int key);

    // find element
    void find(int key);

    // print hashMapTable
    void print();

    // destructor
    ~HashMapTable();
};