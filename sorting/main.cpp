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
        vector<int> vec;
        
        vec = createRandomVector(size, -size, +size);
        start = chrono::system_clock::now();
        qsort(vec, 0, vec.size() - 1);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["qsort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        qsort(vec, 0, vec.size() - 1);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["qsort"]["reversed"][size] = duration.count();
    }

    cout << "BubbleSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        bubbleSort(vec);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["bubbleSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        bubbleSort(vec);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["bubbleSort"]["reversed"][size] = duration.count();
    }

    cout << "ShakerSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        shakerSort(vec);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["shakerSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        shakerSort(vec);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["shakerSort"]["reversed"][size] = duration.count();
    }

    cout << "CombSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        combSort(vec);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["combSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        combSort(vec);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["combSort"]["reversed"][size] = duration.count();
    }

    cout << "InsertionSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        insertionSort(vec);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["insertionSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        insertionSort(vec);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["insertionSort"]["reversed"][size] = duration.count();
    }

    cout << "SelectionSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        selectionSort(vec);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["selectionSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        selectionSort(vec);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["selectionSort"]["reversed"][size] = duration.count();
    }

    cout << "MergeSort start...\n";
    for (auto size : initialVectorSizes) {
        vector<int> vec = createRandomVector(size, -size, +size);

        start = chrono::system_clock::now();
        mergeSort(vec, 0, vec.size() - 1);
        end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        time_table["mergeSort"]["random"][size] = duration.count();

        vec = createReversedSortedVector(size);
        start = chrono::system_clock::now();
        mergeSort(vec, 0, vec.size() - 1);
        end = chrono::system_clock::now();
        duration = end - start;
        time_table["mergeSort"]["reversed"][size] = duration.count();
    }

    cout << "Printing start...\n";
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