#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

// sorting
template <typename T>
void qsort(vector<int>& array, int left, int right);

template <typename T>
void bubbleSort(vector<T>& array);

template <typename T>
void shakerSort(vector<T>& array);

template <typename T>
void combSort(vector<T>& array);

template <typename T>
void insertionSort(vector<T>& array);

template <typename T>
void selectionSort(vector<T>& array);

template<typename T>
void mergeSort(vector<T>& array, int left, int right);

template <typename T>
void shellSort(vector<T>& array);

#include "sorting.cpp"

// functions
int custom_rand(const int left, const int right);

vector<int> createRandomVector(int size, int minValue, int maxValue);

vector<int> createReversedSortedVector(int size);

template<typename T>
void printVector(vector<T> array);

#include "functions.cpp"