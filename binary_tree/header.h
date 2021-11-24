#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>
#include <fstream>
#include <filesystem>

using namespace std;
using filesystem::directory_iterator;

constexpr string_view PARTICIPANTS_PATH = "../data/participants.txt";
constexpr string_view STANDINGS_PATH = "../data/standings/";

enum UserInput
{
    removeDiscipline = 1,
    printSportDisciplinesInfo,
    printStandings,
    printCountryPlaces,
    printCountryDisciplinePlace,
    writeChanges,
    closeApp
};

#include "SportDisciplinesInfo.h"
#include "DisciplinesPlace.h"
#include "Standings.h"

SportDisciplinesInfo *readParticipants(const string_view);

Country *readStandings(const string_view);

Country *readCountryStandings(const string, Country*);

void writeStandings(const string_view standingsPath, SportDisciplinesInfo *disciplines, Country *standings);

#include "readFunctions.h"
#include "writeFunctions.h"