class SportDisciplinesInfo {
private:
    string disciplineName;
    int countOfParticipant;

    SportDisciplinesInfo *left;
    SportDisciplinesInfo *right;

    SportDisciplinesInfo() {
        this->disciplineName = "";
        this->countOfParticipant = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    SportDisciplinesInfo(string disciplineName, int countOfParticipant) {
        this->disciplineName = disciplineName;
        this->countOfParticipant = countOfParticipant;
        this->left = nullptr;
        this->right = nullptr;
    }

public:
    friend bool isLeaf(SportDisciplinesInfo *node);
    friend SportDisciplinesInfo *insert(SportDisciplinesInfo *node, string disciplineName, int countOfParticipant);
    friend SportDisciplinesInfo *remove(SportDisciplinesInfo *node, string disciplineName);
    friend SportDisciplinesInfo *find(SportDisciplinesInfo *node, string disciplineName);
    friend SportDisciplinesInfo *minValue(SportDisciplinesInfo *node);
    friend void inOrder(SportDisciplinesInfo *node);
    friend void print(SportDisciplinesInfo *node);
};

bool isLeaf(SportDisciplinesInfo *node) {
    return node->left == nullptr && node->right == nullptr;
}

SportDisciplinesInfo *insert(
    SportDisciplinesInfo *node,
    string disciplineName,
    int countOfParticipant
) {
    if (node == nullptr) {
        node = new SportDisciplinesInfo(disciplineName, countOfParticipant);
        return node;
    }

    if (node->disciplineName >= disciplineName) {
        node->left = insert(node->left, disciplineName, countOfParticipant);
    } else {
        node->right = insert(node->right, disciplineName, countOfParticipant);
    }

    return node;
}

SportDisciplinesInfo* remove(
    SportDisciplinesInfo *node,
    string disciplineName
) {
    if (node == nullptr) return node;

    print(node);

    if (node->disciplineName > disciplineName) {
        node->left = remove(node->left, disciplineName);
    } else if (node->disciplineName < disciplineName) {
        node->right = remove(node->right, disciplineName);
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

        node->disciplineName = temp->disciplineName;
        node->countOfParticipant = temp->countOfParticipant;

        node->right = remove(node->right, disciplineName);
    }

    return node;
}

SportDisciplinesInfo* find(
    SportDisciplinesInfo *node,
    string disciplineName
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
    cout << "• " << node->disciplineName << ' ' << node->countOfParticipant << "\n";
    inOrder(node->right);
}

void print(SportDisciplinesInfo *node) {
    if (node)
        cout << node->disciplineName << ' ' << node->countOfParticipant << "\n";
}