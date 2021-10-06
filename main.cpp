#include "header.h"

using namespace std;

int main() {
    SportDisciplinesInfoList sportDisciplinesInfoList = readParticipants(PARTICIPANTS_PATH);
    sportDisciplinesInfoList.print();

    StandingsList standingsList = readStandings(STANDINGS_PATH);
    standingsList.print();

    sportDisciplinesInfoList.deleteDiscipline("Volleyball", standingsList);
    sportDisciplinesInfoList.print();
    standingsList.print();

    // writeParticipants(PARTICIPANTS_PATH, sportDisciplinesInfoList);
    // writeStandings(STANDINGS_PATH, sportDisciplinesInfoList, standingsList);
    return 0;
    bool isOpened = true;
    // while (isOPened)
    // {
    //     printMenu();
    //     enum UserInput userInput;
    //     cin >> userInput;



        // УДАЛЕНИЕ ДАННЫХ
        // если удалять что-то в одном из списков, должно цепочно удаляться и в других списках, где есть эти данные
        // дисциплину вроде можно норм удалить, удалив её из других списков также
        // у всех стран просто пропадут места

        // удаление страны из списка результатов под сомнением
        // тогда нужно смещать страны в плане результатов в дисциплинах, где у неё призовые места

        // ИЗМЕНЕНИЕ ДАННЫХ
        // но тогда нужно хранить всё же просто что считали с каждого файла по местам в словаре векторов
        // чтобы сразу смотреть в какие страны лесть в списке результатов
        // из адекватного можно только изменить место у страны
        // поставить/изменить место ->
        // просто втупую пихнуть первым, вторым или третьим
        // но может быть слишком много говнокода, может рекурсией будет всё же лучше
        // удалить из призовых ->
        // тут только рекурсивно, передавая индекс текущего места
        
        // ПЕРЕЧИТАТЬ ВСË ЭТО!!!
    // }
 
    return 0;
}