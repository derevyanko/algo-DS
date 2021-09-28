#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::directory_iterator;

constexpr string_view PARTICIPANTS_PATH = "data/participants.txt";
constexpr string_view STANDINGS_PATH = "data/standings/";

// enum UserInput
// {

// };

#include "SportDisciplineInfoList.h"
#include "DisciplinesPlaceList.h"
#include "StandingsList.h"

/*
    input: path to read participants file
*/
SportDisciplinesInfoList readParticipants(const string_view);

/*
    input: path to read standings files
*/
StandingsList readStandings(const string_view);

/*
    input: path to read country standings
*/
void readCountryStandings(const string, StandingsList*);

/*
    input: path to write participants changes
*/
void writeParticipants(const string_view, SportDisciplinesInfoList);

/*
    input: path to write standings files changes
*/
void writeStandings(const string_view);

/*
    input: path to write country standings files changes
*/
void writeCountryStandings(const string_view);

#include "readFunctions.cpp"
#include "writeFunctions.cpp"