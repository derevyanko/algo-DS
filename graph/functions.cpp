InputData readInputData(istream &in) {
    InputData inputData;
    in >> inputData.verticesNumber >> inputData.roadsNumber;
    
    for (int i = 0; i < inputData.roadsNumber; i++) {
        int fromVertex, toVertex, weight;
        in >> fromVertex >> toVertex >> weight;
        fromVertex--;
        toVertex--;
        inputData.edges.push_back({fromVertex, toVertex, weight});
        inputData.edges.push_back({toVertex, fromVertex, weight});
    }

    inputData.roadsNumber *= 2;

    return inputData;
}

int64_t FordBelmanAlgorithm(InputData const &data, const int vertexNumber) {
    vector<int64_t> distance(data.verticesNumber, INF);
	distance[vertexNumber] = 0;

    vector<Edge> edges = data.edges;

	for (;;) {
		bool any = false;
		for (int i = 0; i < data.roadsNumber; ++i) {
			if (distance[edges[i].fromVertex] < INF) {
                int64_t newWeight = distance[edges[i].fromVertex] + edges[i].weight;
				if (distance[edges[i].toVertex] > newWeight) {
					distance[edges[i].toVertex] = newWeight;
					any = true;
				}
            }
        }

		if (!any) break;
	}

    int64_t waysSum = 0;
    for (auto wayCost : distance) {
        waysSum += wayCost;
    }

    return waysSum;
}

AnswerType calculateMinimumWaysSum(InputData const &data) {
    AnswerType answer = {-1, INF};
    for (int vertexNumber = 0; vertexNumber < data.verticesNumber; vertexNumber++) {
        int64_t waysSum = FordBelmanAlgorithm(data, vertexNumber);
        if (waysSum < answer.waysSum) {
            answer = {vertexNumber, waysSum};
        }
    }

    answer.vertexNumber++;

    return answer;
}

void printMinimumSumAnswer(ostream &out, const AnswerType answer) {
    out << "Vertex number: " << answer.vertexNumber << "\n";
    out << "Ways sum = " << answer.waysSum << "\n";
}