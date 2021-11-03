class DisciplinesPlace {
private:
    string name;
	int place;

    DisciplinesPlace *left;
    DisciplinesPlace *right;

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
    friend bool DisciplinesPlace(DisciplinesPlace *node);
    friend DisciplinesPlace *insert(DisciplinesPlace *node, string name, int place);
    friend DisciplinesPlace *remove(DisciplinesPlace *node, string name);
    friend DisciplinesPlace *find(DisciplinesPlace *node, string name);
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

    if (node->place >= place) {
        node->left = insert(node->left, name, place);
    } else {
        node->right = insert(node->right, name, place);
    }

    return node;
}

SportDisciplinesInfo* remove(
    SportDisciplinesInfo *node,
    string name
) {
    if (node == nullptr) return node;

    if (node->place > place) {
        node->left = remove(node->left, name);
    } else if (node->place < place) {
        node->right = remove(node->right, name);
    } else {
        if (isLeaf(node)) {
            return nullptr;
        } else if (node->left == nullptr) {
            SportDisciplinesInfo *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == nullptr) {
            SportDisciplinesInfo *temp = node->left;
            free(node);
            return temp;
        }

        SportDisciplinesInfo *temp = minValue(node->right);

        node->name = temp->name;
        node->place = temp->place;

        node->right = remove(node->right, name);
    }

    return node;
}

SportDisciplinesInfo* find(
    SportDisciplinesInfo *node,
    string name
) {
    if (node == nullptr) return nullptr;

    if (node->disciplineName > disciplineName) {
        return find(node->left, disciplineName);
    }
    if (node->disciplineName < disciplineName) {
        return find(node->right, disciplineName);
    }
    return node;
}

SportDisciplinesInfo* minValue(SportDisciplinesInfo *node) {
    SportDisciplinesInfo *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

void inOrder(SportDisciplinesInfo *node) {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << "• " << node->name << ' ' << node->place << "\n";
    inOrder(node->right);
}

void print(SportDisciplinesInfo *node) {
    if (node)
        cout << node->name << ' ' << node->place << "\n";
}