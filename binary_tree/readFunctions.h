SportDisciplinesInfo *readParticipants(const string_view participantFileName)
{
    ifstream input(participantFileName);
    SportDisciplinesInfo *node = nullptr;

    while (!input.eof())
    {
        string sportDisciplineName;
        int participantsCount;
        input >> sportDisciplineName >> participantsCount;
        cout << sportDisciplineName << " " << participantsCount << "\n";
        node = insert(
            node,
            sportDisciplineName,
            participantsCount
        );
    }

    input.close();

    return node;
}

Country *readStandings(const string_view standingsPath)
{
    Country *standings = nullptr;

    for (const auto &file : directory_iterator(standingsPath))
    {
        standings = readCountryStandings(file.path().string(), standings);
    }

    return standings;
}

Country *readCountryStandings(const string standingsPath, Country *standings)
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
        standings = insert(
            standings,
            countryName,
            disciplineName,
            place
        );
    }

    input.close();

    return standings;
}