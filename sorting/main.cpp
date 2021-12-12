#include "main.h"

int main() {

    srand(0);

    // vector<int> initialVectorSizes{10, 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000}; for release
    vector<int> initialVectorSizes{10}; // for tests
    map<string, map<string, map<size_t, double> > > time_table;
    chrono::system_clock::time_point start, end;
    chrono::duration<double> duration;

    cout << "QSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            qsort(vec, 0, vec.size() - 1);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["qsort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            qsort(vec, 0, vec.size() - 1);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["qsort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "BubbleSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            bubbleSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["bubbleSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            bubbleSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["bubbleSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "ShakerSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            shakerSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["shakerSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            shakerSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["shakerSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "CombSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            combSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["combSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            combSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["combSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "InsertionSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            insertionSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["insertionSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            insertionSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["insertionSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "SelectionSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            selectionSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["selectionSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            selectionSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["selectionSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "MergeSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            mergeSort(vec, 0, vec.size() - 1);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["mergeSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            mergeSort(vec, 0, vec.size() - 1);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["mergeSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "HeapSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            heapSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["heapSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            heapSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["heapSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "ShellSort start...\n";
    for (auto size : initialVectorSizes) {
        double average = 0;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            start = chrono::system_clock::now();
            shellSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["shellSort"]["random"][size] = average / TESTS_COUNT;

        average = 0;
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            start = chrono::system_clock::now();
            shellSort(vec);
            end = chrono::system_clock::now();
            duration = end - start;
            average += duration.count();
        }
        time_table["shellSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "Saving start...\n";
    for (auto sort : time_table) {
        cout << "Name: " << sort.first << "\n";
        ofstream out("tests/" + sort.first + ".txt");
        for (auto typeArray : sort.second) {
            for (auto test : typeArray.second) {
                cout << "Type array: " << typeArray.first << "\t" << fixed << setprecision(10) << "Size: " << test.first << "\t Time: " << test.second << "\n";
                out << typeArray.first << ' ' << test.first << ' ' << test.second << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}