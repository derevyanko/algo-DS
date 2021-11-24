#include "header.h"

int main() {
    SportDisciplinesInfo *sportDisciplinesInfo = readParticipants(PARTICIPANTS_PATH);
    inOrder(sportDisciplinesInfo);
    cout << "\n";
    
    Country *country = readStandings(STANDINGS_PATH);
    inOrder(country);

    writeStandings(STANDINGS_PATH, sportDisciplinesInfo, country);

    // bool isOpened = true;
    // while (isOpened)
    // {
    //     UserInput userInput = menuCommand();

    //     switch (userInput)
    //     {
    //     case removeDiscipline:
    //     {
    //         string disciplineName;
    //         cin >> disciplineName;
    //         sportDisciplinesInfoList.deleteDiscipline(disciplineName, standingsList);

    //         break;
    //     }
    //     case printSportDisciplinesInfo:
    //         sportDisciplinesInfoList.print();

    //         break;
    //     case printStandings:
    //         standingsList.print();

    //         break;
    //     case printCountryPlaces:
    //     {
    //         string countryName;
    //         cin >> countryName;
    //         Country* country = standingsList.find(countryName);
    //         if (country) {
    //             country->print();
    //         } else {
    //             cout << "Не найдено страны!\n";
    //         }

    //         break;
    //     }
    //     case printCountryDisciplinePlace:
    //     {
    //         string countryName, disciplineName;
    //         cin >> countryName >> disciplineName;
    //         Country* country = standingsList.find(countryName);
    //         if (country) {
    //             country->print();
    //         } else {
    //             cout << "Не найдено страны!\n";

    //             break;
    //         }
    //         DisciplinePlace* discipline = country->disciplinesPlace.find(disciplineName);
    //         if (discipline) {
    //             discipline->print();
    //         } else {
    //             cout << "Не найдено дисцплины!\n";
    //         }

    //         break;
    //     }
    //     case writeChanges:
    //         writeParticipants(PARTICIPANTS_PATH, sportDisciplinesInfoList);
    //         writeStandings(STANDINGS_PATH, sportDisciplinesInfoList, standingsList);
    //     break;
    //     case closeApp:
    //         isOpened = false;

    //         break;
    //     default:
    //         cout << "Input correct value!\n";

    //         break;
    //     }
    // }

    return 0;
}