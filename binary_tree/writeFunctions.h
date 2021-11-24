void writeParticipants(const string_view participantFileName, const SportDisciplinesInfo *node)
{
    ofstream output(participantFileName, ofstream::out | ofstream::trunc);

    inOrderFile(output, node);

    output.close();
}

void writeStandings(
    const string_view standingsPath, 
    SportDisciplinesInfo *disciplines, 
    Country *standings
)
{
    SportDisciplinesInfo *nodeDisciplineInfo = disciplines;
    stack<SportDisciplinesInfo*> disciplineStack;
    while (nodeDisciplineInfo || !disciplineStack.empty())
    {
        while(nodeDisciplineInfo) {
            disciplineStack.push(nodeDisciplineInfo);
            nodeDisciplineInfo = nodeDisciplineInfo->getLeft();
        }

        nodeDisciplineInfo = disciplineStack.top();
        disciplineStack.pop();

        int countOfParticipant = nodeDisciplineInfo->getCountOfParticipant();
        string disciplineName = nodeDisciplineInfo->getDisciplineName();
        string filePath = STANDINGS_PATH.data() + disciplineName + ".txt";
        fstream output(filePath, std::ofstream::out | ofstream::trunc);

        string standingsRes[countOfParticipant];
        Country *nodeCountry = standings;
        stack<Country*> countries;
        while (nodeCountry || !countries.empty())
        {
            while(nodeCountry)
            {
                countries.push(nodeCountry);
                nodeCountry = nodeCountry->getLeft();
            }

            nodeCountry = countries.top();
            countries.pop();

            DisciplinesPlace *nodeDisciplinePlace = nodeCountry->getDisciplinesPlace();
            stack<DisciplinesPlace*> disciplinePlaces;
            while(nodeDisciplinePlace || !disciplinePlaces.empty())
            {
                while (nodeDisciplinePlace)
                {
                    disciplinePlaces.push(nodeDisciplinePlace);
                    nodeDisciplinePlace = nodeDisciplinePlace->left;
                }
                
                nodeDisciplinePlace = disciplinePlaces.top();
                disciplinePlaces.pop();

                if (nodeDisciplinePlace->name == nodeDisciplineInfo->getDisciplineName())
                {
                    standingsRes[nodeDisciplinePlace->place - 1] = nodeCountry->getName();
                }

                nodeDisciplinePlace = nodeDisciplinePlace->right;
            }

            nodeCountry = nodeCountry->getRight();
        }

        for (const auto countryName: standingsRes) 
        {
            output << countryName << " ";
        }

        nodeDisciplineInfo = nodeDisciplineInfo->getRight();
    }
}