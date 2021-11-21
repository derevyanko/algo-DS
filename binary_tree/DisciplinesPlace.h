class DisciplinesPlace {
private:
    DisciplinesPlace() {
        this->name = "";
        this->place = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    DisciplinesPlace(string name, int place) {
        this->name = name;
        this->place = place;
        this->left = nullptr;
        this->right = nullptr;
    }

public:
    string name;
	int place;

    DisciplinesPlace *left;
    DisciplinesPlace *right;

    friend bool DisciplinesPlace(DisciplinesPlace *node);
    friend DisciplinesPlace *insert(DisciplinesPlace *node, string name, int place);
    friend DisciplinesPlace *remove(DisciplinesPlace *node, string name, int place);
    friend DisciplinesPlace *find(DisciplinesPlace *node, string name, int place);
    friend DisciplinesPlace *minValue(DisciplinesPlace *node);
    friend void inOrder(DisciplinesPlace *node);
    friend void print(DisciplinesPlace *node);
};

bool isLeaf(DisciplinesPlace *node) {
    return node->left == nullptr && node->right == nullptr;
}

DisciplinesPlace *insert(
    DisciplinesPlace *node,
    string name,
    int place
) {
    if (node == nullptr) {
        node = new DisciplinesPlace(name, place);
        return node;
    }

    if (node->place > place) {
        node->left = insert(node->left, name, place);
    } else {
        node->right = insert(node->right, name, place);
    }

    return node;
}

DisciplinesPlace* remove(
    DisciplinesPlace *node,
    string name,
    int place
) {
    if (node == nullptr) return node;

    if (node->place > place) {
        node->left = remove(node->left, name, place);
    } else if (node->place < place) {
        node->right = remove(node->right, name, place);
    } else {
        if (isLeaf(node)) {
            return nullptr;
        } else if (node->left == nullptr) {
            DisciplinesPlace *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == nullptr) {
            DisciplinesPlace *temp = node->left;
            free(node);
            return temp;
        }

        DisciplinesPlace *temp = minValue(node->right);

        node->name = temp->name;
        node->place = temp->place;

        node->right = remove(node->right, name, place);
    }

    return node;
}

DisciplinesPlace* find(
    DisciplinesPlace *node,
    string name,
    int place
) {
    if (node == nullptr) return nullptr;

    if (node->place > place) {
        return find(node->left, name, place);
    }
    if (node->place < place) {
        return find(node->right, name, place);
    }
    return node;
}

DisciplinesPlace* minValue(DisciplinesPlace *node) {
    DisciplinesPlace *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

void inOrder(DisciplinesPlace *node) {
    if (node == nullptr) return;

    inOrder(node->left);
    print(node);
    inOrder(node->right);
}

void print(DisciplinesPlace *node) {
    if (node)
        cout << node->name << ' ' << node->place << " | ";
}