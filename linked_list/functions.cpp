UserInput menuCommand() {
    cout << "1. Удалить дисциплину\n";
    cout << "2. Вывести количество участников в каждой дисциплине\n";
    cout << "3. Вывести результаты каждой страны в каждой дисциплине\n";
    cout << "4. Вывести результаты страны в каждой дисциплине\n";
    cout << "5. Вывести результаты страны в дисциплине\n";
    cout << "6. Записать все изменения\n";
    cout << "7. Закрыть приложение\n";
    cout << "Команда: ";
    int userInputInt;
    cin >> userInputInt;

    return UserInput(userInputInt);
}