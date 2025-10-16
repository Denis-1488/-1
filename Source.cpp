#include "Header.h"

int main() {
    setlocale(0, "");
    Apartment apartments[10];
    int count = 0;
    int choice;

    
    loadFromFile(apartments, count);

    do {
        cout << "\t====МЕНЮ====\n";
        cout << "\n1. Добавить квартиру\n";
        cout << "2. Удалить квартиру\n";
        cout << "3. Добавить жильца\n";
        cout << "4. Показать все квартиры\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addApartment(apartments, count);
            break;
        case 2: {
            int num;
            cout << "Введите номер квартиры: ";
            cin >> num;
            deleteApartment(apartments, count, num);
            break;
        }
        case 3: {
            int num;
            cout << "Введите номер квартиры: ";
            cin >> num;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (apartments[i].number == num) {
                    addResident(apartments[i]);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Квартира не найдена.\n";
            break;
        }
        case 4:
            showAll(apartments, count);
            break;
        case 5:
            saveToFile(apartments, count);
            break;
        case 6:
            loadFromFile(apartments, count);
            showAll(apartments, count);
            break;
        }
    } while (choice != 0);

    cout << "Выход из программы...\n";
    return 0;
}
