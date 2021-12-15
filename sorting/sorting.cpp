template <typename T>
TestAnswer qsort(vector<T>& array, int left, int right) {
    TestAnswer answer;

    int mid = array[left + (right - left) / 2];
    int i = left, j = right;

    while (i <= j) {
        while(array[i] < mid) {
            i++;
            answer.comparison++;
        }
        while(array[j] > mid){
            j--;
            answer.comparison++;
        }

        if (i <= j) {
            swap(array[i], array[j]);
            answer.moving++;

            i++;
            j--;
        }
    }

    if(j > left) answer += qsort(array, left, j);
    if (i < right) answer += qsort(array, i, right);

    return answer;
}

template <typename T>
TestAnswer bubbleSort(vector<T>& array) {
    TestAnswer answer;

    int size = array.size();
    for (int i = 0; i + 1 < size; i++)
        for (int j = 0; j + 1 < size - i; j++) {
            if (array[j + 1] < array[j]) {
                swap(array[j], array[j + 1]);
                answer.moving++;
            }
            answer.comparison++;
        }

    return answer;
}

template <typename T>
TestAnswer shakerSort(vector<T>& array) {
    TestAnswer answer;

    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        for (int i = right; i > left; i--) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
                answer.moving++;
            }
            answer.comparison++;
        }
        left++;

        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                answer.moving++;
            }
            answer.comparison++;
        }
        right--;
    }

    return answer;
} 

template <typename T>
TestAnswer combSort(vector<T>& array) {
    TestAnswer answer;

    const double factor = 1.247;
    double step = array.size() - 1;

    while (step >= 1) {
        for (int i = 0; i + step < array.size(); ++i) {
            if (array[i] > array[i + step]) {
                swap(array[i], array[i + step]);
                answer.moving++;
            }
            answer.comparison++;
        }

        step /= factor;
    }

    return answer;
}

template <typename T>
TestAnswer insertionSort(vector<T>& array) {
    TestAnswer answer;

    int size = array.size();
    for (int i = 0; i < size; ++i) {
        int j = i - 1;

        while (j >= 0 && array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
            --j;

            answer.comparison++;
            answer.moving++;
        }
        if (j >= 0) answer.comparison++;
    }

    return answer;
}

template <typename T>
TestAnswer selectionSort(vector<T>& array) {
    TestAnswer answer;

    int size = array.size();
    for (int i = 0; i < size; i++) {
        int min = array[i], minInd = i;
        for (int j = i; j < size; j++) {
            if (array[j] < min) {
                minInd = j;
            }
            answer.comparison++;
        }

        swap(array[i], array[minInd]);
        answer.moving++;
    }

    return answer;
}

template <typename T>
TestAnswer merge(vector<T>& array, int left, int mid, int right) {
    TestAnswer answer;

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
            answer.moving++;

            indexOfLeftArray++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfRightArray];
            answer.moving++;

            indexOfRightArray++;
        }

        answer.comparison++;

        indexOfMergedArray++;
    }

    while (indexOfLeftArray < leftArraySize) {
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
        answer.moving++;

        indexOfLeftArray++;
        indexOfMergedArray++;
    }

    while (indexOfRightArray < rightArraySize) {
        array[indexOfMergedArray] = rightArray[indexOfRightArray];
        answer.moving++;

        indexOfRightArray++;
        indexOfMergedArray++;
    }

    return answer;
}

template<typename T>
TestAnswer mergeSort(vector<T>& array, int left, int right) {
    if (left >= right) return {0, 0};

    TestAnswer answer;

    int mid = left + (right - left) / 2;
    answer += mergeSort(array, left, mid);
    answer += mergeSort(array, mid + 1, right);
    answer += merge(array, left, mid, right);

    return answer;
}

template <typename T>
TestAnswer heapify(vector<T>& array, int n, int i) {
    TestAnswer answer;

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        if (array[l] > array[largest])
            largest = l;
        answer.comparison++;
    }
  
    if (r < n) {
        if (array[r] > array[largest])
            largest = r;
        answer.comparison++;
    }

    if (largest != i) {
        swap(array[i], array[largest]);
        answer.moving++;
  
        answer += heapify(array, n, largest);
    }

    return answer;
}

template <typename T>
TestAnswer heapSort(vector<T>& array) {
    TestAnswer answer;
    int size = array.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        answer += heapify(array, size, i);
  
    for (int i = size - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        answer.moving++;
  
        answer += heapify(array, i, 0);
    }

    return answer;
}

template <typename T>
TestAnswer shellSort(vector<T>& array) {
    TestAnswer answer;

    int size = array.size();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
 
            int j;
            answer.comparison++;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
                answer.comparison++;
                answer.moving++;
            }

            array[j] = temp;
            answer.moving++;
        }
    }

    return answer;
}