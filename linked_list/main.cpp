#include "header.h"

using namespace std;

int main() {
    SportDisciplinesInfoList sportDisciplinesInfoList = readParticipants(PARTICIPANTS_PATH);
    // sportDisciplinesInfoList.print();

    StandingsList standingsList = readStandings(STANDINGS_PATH);
    // standingsList.print();

    bool isOpened = true;
    while (isOpened)
    {
        UserInput userInput = menuCommand();

        switch (userInput)
        {
        case removeDiscipline:
        {
            string disciplineName;
            cin >> disciplineName;
            sportDisciplinesInfoList.deleteDiscipline(disciplineName, standingsList);

            break;
        }
        case printSportDisciplinesInfo:
            sportDisciplinesInfoList.print();

            break;
        case printStandings:
            standingsList.print();

            break;
        case printCountryPlaces:
        {
            string countryName;
            cin >> countryName;
            Country* country = standingsList.find(countryName);
            if (country) {
                country->print();
            } else {
                cout << "Не найдено страны!\n";
            }

            break;
        }
        case printCountryDisciplinePlace:
        {
            string countryName, disciplineName;
            cin >> countryName >> disciplineName;
            Country* country = standingsList.find(countryName);
            if (country) {
                country->print();
            } else {
                cout << "Не найдено страны!\n";

                break;
            }
            DisciplinePlace* discipline = country->disciplinesPlace.find(disciplineName);
            if (discipline) {
                discipline->print();
            } else {
                cout << "Не найдено дисцплины!\n";
            }

            break;
        }
        case writeChanges:
            writeParticipants(PARTICIPANTS_PATH, sportDisciplinesInfoList);
            writeStandings(STANDINGS_PATH, sportDisciplinesInfoList, standingsList);
        break;
        case closeApp:
            isOpened = false;

            break;
        default:
            cout << "Input correct value!\n";

            break;
        }
    }
 
    return 0;
}