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