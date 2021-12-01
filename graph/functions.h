InputData readInputData(istream&);

int64_t FordBelmanAlgorithm(InputData const&, const int);

AnswerType calculateMinimumWaysSum(InputData const&);

void printMinimumSumAnswer(ostream&, const AnswerType);

#include "functions.cpp"