SportDisciplinesInfo *readParticipants(const string_view participantFileName)
{
    ifstream input(participantFileName);
    SportDisciplinesInfo *node = nullptr;

    while (!input.eof())
    {
        string sportDisciplineName;
        int participantsCount;
        input >> sportDisciplineName >> participantsCount;
        node = insert(
            node,
            sportDisciplineName,
            participantsCount
        );
    }

    return node;
}