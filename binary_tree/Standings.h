class Country {
private:
    string name;
	DisciplinesPlace *disciplinesPlace;

    Country *left;
    Country *right;

    Country(string name) {
        this->name = name;
        this->disciplinesPlace = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

public:
    friend bool isLeaf(Country *node);
    friend Country *insert(Country *node, string name, string disciplineName, int place);
    friend Country *remove(Country *node, string name);
    friend Country *find(Country *node, string name);
    friend Country *minValue(Country *node);
    friend void inOrder(Country *node);
    friend void print(Country *node);
};

bool isLeaf(Country *node) {
    return node->left == nullptr && node->right == nullptr;
}

Country *insert(
    Country *node,
    string name,
    string disciplineName,
    int place
) {
    if (node == nullptr) {
        node = new Country(name);
        node->disciplinesPlace = insert(
            node->disciplinesPlace,
            disciplineName,
            place
        );
        return node;
    }

    if (node->name == name) {
        node->disciplinesPlace = insert(
            node->disciplinesPlace,
            disciplineName,
            place
        );
        return node;
    }
    if (node->name > name) {
        node->left = insert(node->left, name, disciplineName, place);
    } else {
        node->right = insert(node->right, name, disciplineName, place);
    }

    return node;
}

Country* remove(
    Country *node,
    string name
) {
    if (node == nullptr) return node;

    if (node->name > name) {
        node->left = remove(node->left, name);
    } else if (node->name < name) {
        node->right = remove(node->right, name);
    } else {
        if (isLeaf(node)) {
            return nullptr;
        } else if (node->left == nullptr) {
            Country *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == nullptr) {
            Country *temp = node->left;
            free(node);
            return temp;
        }

        Country *temp = minValue(node->right);

        node->name = temp->name;
        node->disciplinesPlace = temp->disciplinesPlace;

        node->right = remove(node->right, name);
    }

    return node;
}

Country* find(
    Country *node,
    string name
) {
    if (node == nullptr) return nullptr;

    if (node->name > name) {
        return find(node->left, name);
    }
    if (node->name < name) {
        return find(node->right, name);
    }
    return node;
}

Country* minValue(Country *node) {
    Country *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

void inOrder(Country *node) {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << "• ";
    print(node);
    inOrder(node->right);
}

void print(Country *node) {
    if (node) {
        cout << node->name << ": ";
        inOrder(node->disciplinesPlace);
        cout << "\n";
    }
}