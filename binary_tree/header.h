#include <iostream>
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

#include "readFunctions.h"