void writeParticipants(const string_view participantFileName, SportDisciplinesInfoList list)
{
    fstream output(participantFileName);

    SportDisciplineInfo *node = list.first;
    while (node)
    {
        output << node->disciplineName << node->countOfParticipant;
        node = node->next;
    }
}

void writeStandings(const string_view standingsPath, StandingsList list)
{
    // нужно идти по спику дисциплин
    // потом идти по странам, если есть эта дисциплина, то пихаем в векторе на определённое место
    // потом это всё записываем
    for (const auto &file : directory_iterator(standingsPath))
    {
        // writeCountryStandings(file.path(), standinsList);
    }
}