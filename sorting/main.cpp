#include "main.h"

int main() {

    srand(0);

    // vector<int> initialVectorSizes{10, 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000}; for release
    vector<int> initialVectorSizes{10}; // for tests
    TestAnswer testResult;
    map<string, map<string, map<size_t, TestAnswer> > > time_table;
    chrono::system_clock::time_point start, end;
    chrono::duration<double> duration;

    cout << "QSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = qsort(vec, 0, vec.size() - 1);
            average += testResult;
        }
        time_table["qsort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = qsort(vec, 0, vec.size() - 1);
            average += testResult;
        }
        time_table["qsort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "BubbleSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = bubbleSort(vec);
            average += testResult;
        }
        time_table["bubbleSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = bubbleSort(vec);
            average += testResult;
        }
        time_table["bubbleSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "ShakerSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = shakerSort(vec);
            average += testResult;
        }
        time_table["shakerSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = shakerSort(vec);
            average += testResult;
        }
        time_table["shakerSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "CombSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = combSort(vec);
            average += testResult;
        }
        time_table["combSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = combSort(vec);
            average += testResult;
        }
        time_table["combSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "InsertionSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = insertionSort(vec);
            average += testResult;

            for (auto a : vec) cout << a << ' ';
            cout << "\n";
        }
        time_table["insertionSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = insertionSort(vec);
            average += testResult;
        }
        time_table["insertionSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "SelectionSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = selectionSort(vec);
            average += testResult;
        }
        time_table["selectionSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = selectionSort(vec);
            average += testResult;
        }
        time_table["selectionSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "MergeSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = mergeSort(vec, 0, vec.size() - 1);
            average += testResult;
        }
        time_table["mergeSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = mergeSort(vec, 0, vec.size() - 1);
            average += testResult;
        }
        time_table["mergeSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "HeapSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = heapSort(vec);
            average += testResult;
        }
        time_table["heapSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = heapSort(vec);
            average += testResult;
        }
        time_table["heapSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "ShellSort start...\n";
    for (auto size : initialVectorSizes) {
        TestAnswer average;

        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createRandomVector(size, -size, +size);
            testResult = shellSort(vec);
            average += testResult;
        }
        time_table["shellSort"]["random"][size] = average / TESTS_COUNT;

        average = TestAnswer(0, 0);
        for (int i = 0; i < TESTS_COUNT; i++) {
            vector<int> vec = createReversedSortedVector(size);
            testResult = shellSort(vec);
            average += testResult;
        }
        time_table["shellSort"]["reversed"][size] = average / TESTS_COUNT;
    }

    cout << "Saving start...\n";
    for (auto sort : time_table) {
        cout << "Name: " << sort.first << "\n";
        ofstream out("tests/" + sort.first + ".txt");
        for (auto typeArray : sort.second) {
            for (auto test : typeArray.second) {
                cout << "Type array: " << typeArray.first << "\t" << "Size: " << test.first;
                cout << "\t Comparisons: " << test.second.comparison << "\tMovings: " << test.second.moving << "\n";
                out << typeArray.first << ' ' << test.first << ' ' << test.second.comparison << ' ' << test.second.moving << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}