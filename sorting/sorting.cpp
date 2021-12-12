template <typename T>
void qsort(vector<T>& array, int left, int right) {
    int mid = array[left + (right - left) / 2];
    int i = left, j = right;

    for (auto a : array) cout << a << ' ';]

    while (i <= j) {
        while(array[i] < mid) i++;
        while(array[j] > mid) j--;

        if (i <= j) {
            swap(array[i], array[j]);

            i++;
            j--;
        }
    }

    if(j > left) qsort(array, left, j);
    if (i < right) qsort(array, i, right);
}

template <typename T>
void bubbleSort(vector<T>& array) {
    int size = array.size();
    for (int i = 0; i + 1 < size; i++)
        for (int j = 0; j + 1 < size - i; j++)
            if (array[j + 1] < array[j])
                swap(array[j], array[j + 1]);
}

template <typename T>
void shakerSort(vector<T>& array) {
    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        for (int i = right; i > left; i--)
            if (array[i - 1] > array[i])
                swap(array[i - 1], array[i]);
        left++;

        for (int i = left; i < right; i++)
            if (array[i] > array[i + 1])
                swap(array[i], array[i + 1]);
        right--;
    }
} 

template <typename T>
void combSort(vector<T>& array) {
    const double factor = 1.247;
    double step = array.size() - 1;

    while (step >= 1) {
        for (int i = 0; i + step < array.size(); ++i)
            if (array[i] > array[i + step])
                swap(array[i], array[i + step]);

        step /= factor;
    }
}

template <typename T>
void insertionSort(vector<T>& array) {
    int size = array.size();
    for (int i = 1; i < size; ++i) {
        T item = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > item) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = item;
    }
}

template <typename T>
void selectionSort(vector<T>& array) {
    for (auto i = array.begin(); i != array.end(); ++i) {
        auto j = min_element(i, array.end());
        swap(*i, *j);
    }
}