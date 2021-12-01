#include "header.h"

int main() {
    SportDisciplinesInfo *sportDisciplinesInfo = readParticipants(PARTICIPANTS_PATH);
    inOrder(sportDisciplinesInfo);
    cout << "\n";
    
    Country *country = readStandings(STANDINGS_PATH, sportDisciplinesInfo);
    inOrder(country);
    cout << "\n";

    bool isOpened = true;
    while (isOpened)
    {
        UserInput userInput = menuCommand();

        switch (userInput)
        {
        case insertDiscipline:
        {
            string disciplineName;
            int countOfParticipant;
            cin >> disciplineName >> countOfParticipant;
            sportDisciplinesInfo = insert(sportDisciplinesInfo, disciplineName, countOfParticipant);

            for (int i = 0; i < countOfParticipant; ++i) {
                string countryName;
                int place;
                cin >> countryName >> place;
                country = insert(country, countryName, disciplineName, place);
            }

            break;
        }
        case removeDisciplineInfo:
        {
            string disciplineName;
            cin >> disciplineName;
            sportDisciplinesInfo = remove(sportDisciplinesInfo, disciplineName, country);

            break;
        }
        case printSportDisciplinesInfo:
            inOrder(sportDisciplinesInfo);

            break;
        case printStandings:
            inOrder(country);

            break;
        case printCountryPlaces:
        {
            string countryName;
            cin >> countryName;
            Country* foundedCountry = find(country, countryName);
            if (foundedCountry) {
                print(foundedCountry);
            } else {
                cout << "Не найдено страны!\n";
            }

            break;
        }
        case printCountryDisciplinePlace:
        {
            string countryName, disciplineName;
            cin >> countryName >> disciplineName;
            Country* foundedCountry = find(country, countryName);
            if (foundedCountry) {
                print(foundedCountry);
            } else {
                cout << "Не найдено страны!\n";

                break;
            }
            DisciplinesPlace* discipline = find(foundedCountry->getDisciplinesPlace(), disciplineName);
            if (discipline) {
                print(discipline);
                cout << "\n";
            } else {
                cout << "Не найдено дисциплины!\n";
            }

            break;
        }
        case writeChanges:
            writeParticipants(PARTICIPANTS_PATH, sportDisciplinesInfo);
            writeStandings(STANDINGS_PATH, sportDisciplinesInfo, country);
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