#include "main.h"

int main() {
    ifstream inputFile(INPUT_FILE_NAME);
    ofstream outputFile(OUTPUT_FILE_NAME);

    const InputData inputData = readInputData(inputFile);
    const AnswerType minimumWaysSumAnswer = calculateMinimumWaysSum(inputData);
    printMinimumSumAnswer(outputFile, minimumWaysSumAnswer);

    inputFile.close();
    outputFile.close();

    return 0;
}