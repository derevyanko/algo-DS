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
        if (sportDisciplineName != "")
            node = insert(
                node,
                sportDisciplineName,
                participantsCount
            );
    }

    input.close();

    return node;
}

Country *readStandings(const string_view standingsPath, SportDisciplinesInfo *disciplinesInfo)
{
    Country *standings = nullptr;
    stack<SportDisciplinesInfo*> disciplines;
    while(disciplinesInfo || !disciplines.empty())
    {
        while (disciplinesInfo)
        {
            disciplines.push(disciplinesInfo);
            disciplinesInfo = disciplinesInfo->getLeft();
        }
        
        disciplinesInfo = disciplines.top();
        disciplines.pop();

        standings = readCountryStandings(string(standingsPath), disciplinesInfo->disciplineName, standings);

        disciplinesInfo = disciplinesInfo->getRight();
    }

    return standings;
}

Country *readCountryStandings(const string standingsPath, const string disciplineName, Country *standings)
{
    const string inputPath = standingsPath + "/" + disciplineName + ".txt";
    ifstream input(inputPath);

    // string disciplineName = "";
    // int index = standingsPath.size() - 4;
    // while (standingsPath[--index] != '/') {
    //     disciplineName += standingsPath[index];
    // }
    // reverse(disciplineName.begin(), disciplineName.end());

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