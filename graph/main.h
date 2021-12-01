#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

constexpr string_view INPUT_FILE_NAME = "input.txt";
constexpr string_view OUTPUT_FILE_NAME = "output.txt";

constexpr int64_t INF = INT64_MAX - 1;

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;
};

struct InputData {
    int verticesNumber;
    int roadsNumber;

    vector<Edge> edges;
};

struct AnswerType {
    int vertexNumber;
    int64_t waysSum;
};

InputData readInputData(istream&);

int64_t FordBelmanAlgorithm(InputData const&, const int);

AnswerType calculateMinimumWaysSum(InputData const&);

void printMinimumSumAnswer(ostream&, const AnswerType);

#include "functions.cpp"