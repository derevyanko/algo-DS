int custom_rand(const int left, const int right) {
    return left + rand() % (right - left);
}

vector<int> createRandomVector(int size, int minValue, int maxValue) {
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = custom_rand(minValue, maxValue);
    }

    return array;
}

vector<int> createReversedSortedVector(int size) {
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = size - i;
    }

    return array;
}

template<typename T>
void printVector(vector<T> array) {
    for (auto a : array) cout << a << ' ';
    cout << "\n";
}