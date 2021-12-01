InputData readInputData(istream &in) {
    InputData inputData;
    in >> inputData.verticesNumber;
    in >> inputData.roadsNumber;

    inputData.edges.resize(inputData.verticesNumber, vector<Edge>(inputData.verticesNumber));
    for (int i = 0; i < inputData.roadsNumber; i++) {
        int fromVertex, toVertex, weight;
        cin >> fromVertex >> toVertex >> weight;
        inputData.edges[fromVertex].push_back({toVertex, weight});
    }

    return inputData;
}