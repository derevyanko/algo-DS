#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

constexpr int TESTS_COUNT = 5;

struct TestAnswer {
    int64_t comparison;
    int64_t moving;

    TestAnswer() {
        comparison = 0;
        moving = 0;
    }

    TestAnswer(int64_t comparison, int64_t moving) {
        this->comparison = comparison;
        this->moving = moving;
    }

    TestAnswer& operator+= (const TestAnswer& another) {
        comparison += another.comparison;
        moving += another.moving;
        return *this;
    }

    TestAnswer operator/(const int number) {
        return TestAnswer(comparison / number, moving / number);
    }
};

// sorting
template <typename T>
TestAnswer qsort(vector<int>& array, int left, int right);

template <typename T>
TestAnswer bubbleSort(vector<T>& array);

template <typename T>
TestAnswer shakerSort(vector<T>& array);

template <typename T>
TestAnswer combSort(vector<T>& array);

template <typename T>
TestAnswer insertionSort(vector<T>& array);

template <typename T>
TestAnswer selectionSort(vector<T>& array);

template<typename T>
TestAnswer mergeSort(vector<T>& array, int left, int right);

template<typename T>
TestAnswer heapSort(vector<T>& array);

template <typename T>
TestAnswer shellSort(vector<T>& array);

#include "sorting.cpp"

// functions
int custom_rand(const int left, const int right);

vector<int> createRandomVector(int size, int minValue, int maxValue);

vector<int> createReversedSortedVector(int size);

template<typename T>
void printVector(vector<T> array);

#include "functions.cpp"