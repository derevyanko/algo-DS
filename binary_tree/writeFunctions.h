void writeParticipants(const string_view participantFileName, const SportDisciplinesInfo *node)
{
    ofstream output(participantFileName, ofstream::out | ofstream::trunc);

    inOrderFile(output, node);

    output.close();
}

void writeStandings(
    const string_view standingsPath, 
    const SportDisciplinesInfo disciplines, 
    const Country standings
)
{
    SportDisciplinesInfo *nodeDisciplineInfo = disciplines;
    while (nodeDisciplineInfo)
    {
        int countOfParticipant = nodeDisciplineInfo->countOfParticipant;
        string disciplineName = nodeDisciplineInfo->disciplineName;
        string filePath = STANDINGS_PATH.data() + disciplineName + ".txt";
        fstream output(filePath, std::ofstream::out | ofstream::trunc);

        string standingsRes[countOfParticipant];
        Country *nodeCountry = standings;
        while (nodeCountry)
        {
            DisciplinesPlace *nodeDisciplinePlace = nodeCountry->disciplinesPlace;

            while (nodeDisciplinePlace)
            {
                if (nodeDisciplinePlace->name == nodeDisciplineInfo->disciplineName) {
                    standingsRes[nodeDisciplinePlace->place - 1] = nodeCountry->name;
                }

                nodeDisciplinePlace = nodeDisciplinePlace->next;
            }

            nodeCountry = nodeCountry->next;
        }
        for (auto const countryName : standingsRes) {
            output << countryName << " ";
        }

        nodeDisciplineInfo = nodeDisciplineInfo->next;
    }
}