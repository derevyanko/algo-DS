template <typename T>
void qsort(vector<T>& array, int left, int right) {
    int mid = array[left + (right - left) / 2];
    int i = left, j = right;

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

template <typename T>
void merge(vector<T>& array, int left, int mid, int right) {
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;

    vector<T> leftArray(leftArraySize);
    vector<T> rightArray(rightArraySize);

    for (auto i = 0; i < leftArraySize; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < rightArraySize; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfLeftArray = 0, indexOfRightArray = 0;
    int indexOfMergedArray = left;

    while (indexOfLeftArray < leftArraySize && indexOfRightArray < rightArraySize) {
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            array[indexOfMergedArray] = leftArray[indexOfLeftArray];
            indexOfLeftArray++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfRightArray];
            indexOfRightArray++;
        }
        indexOfMergedArray++;
    }

    while (indexOfLeftArray < leftArraySize) {
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
        indexOfLeftArray++;
        indexOfMergedArray++;
    }

    while (indexOfRightArray < rightArraySize) {
        array[indexOfMergedArray] = rightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }
}

template<typename T>
void mergeSort(vector<T>& array, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}