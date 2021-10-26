void writeParticipants(const string_view participantFileName, const SportDisciplinesInfoList list)
{
    fstream output(participantFileName, std::ofstream::out | ofstream::trunc);

    SportDisciplineInfo *node = list.first;
    while (node)
    {
        output << node->disciplineName << " " << node->countOfParticipant << "\n";
        node = node->next;
    }
}

void writeStandings(
    const string_view standingsPath, 
    const SportDisciplinesInfoList disciplinesList, 
    const StandingsList standingsList
)
{
    // нужно идти по спику дисциплин
    // потом идти по странам, если есть эта дисциплина, то записываем в массив на определённое место
    // потом это всё записываем

    SportDisciplineInfo *nodeDisciplineInfo = disciplinesList.first;
    while (nodeDisciplineInfo)
    {
        int countOfParticipant = nodeDisciplineInfo->countOfParticipant;
        string disciplineName = nodeDisciplineInfo->disciplineName;
        string filePath = STANDINGS_PATH.data() + disciplineName + ".txt";
        fstream output(filePath, std::ofstream::out | ofstream::trunc);

        string standingsRes[countOfParticipant];
        Country *nodeCountry = standingsList.first;
        while (nodeCountry)
        {
            DisciplinePlace *nodeDisciplinePlace = nodeCountry->disciplinesPlace.first;

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