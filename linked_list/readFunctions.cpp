SportDisciplinesInfoList readParticipants(const string_view participantFileName)
{
    ifstream input(participantFileName);
    SportDisciplinesInfoList sportDisciplinesInfoList;

    while (!input.eof())
    {
        string sportDisciplineName;
        int participantsCount;
        input >> sportDisciplineName >> participantsCount;

        sportDisciplinesInfoList.pushBack(sportDisciplineName, participantsCount);
    }

    return sportDisciplinesInfoList;
}

StandingsList readStandings(const string_view standingsPath)
{
    StandingsList standinsList;

    for (const auto &file : directory_iterator(standingsPath))
    {
        readCountryStandings(file.path().string(), &standinsList);
    }

    return standinsList;
}

void readCountryStandings(const string standingsPath, StandingsList *standingsList)
{
    ifstream input(standingsPath);

    string disciplineName = "";
    int index = standingsPath.size() - 4;
    while (standingsPath[--index] != '/') {
        disciplineName += standingsPath[index];
    }
    reverse(disciplineName.begin(), disciplineName.end());

    string countryName;
    for (int place = 1; input >> countryName; place++)
    {
        standingsList->push(countryName, disciplineName, place);
    }
}