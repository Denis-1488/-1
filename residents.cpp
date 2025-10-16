#include "Header.h"

void addApartment(Apartment apartments[], int& count) {
    cout << "Введите номер квартиры: ";
    cin >> apartments[count].number;
    cout << "Введите этаж: ";
    cin >> apartments[count].floor;
    cout << "Введите количество комнат: ";
    cin >> apartments[count].rooms;
    apartments[count].residentCount = 0;
    count++;
}

// Удаляет квартиру по номеру
void deleteApartment(Apartment apartments[], int& count, int number) {
    for (int i = 0; i < count; i++) {
        if (apartments[i].number == number) {
            for (int j = i; j < count - 1; j++)
                apartments[j] = apartments[j + 1];
            count--;
            cout << "Квартира удалена.\n";
            return;
        }
    }
    cout << "Квартира не найдена.\n";
}

//Добавляет жильца в выбранную квартиру.
void addResident(Apartment& apartment) {
    if (apartment.residentCount >= 20) {
        cout << "Квартира переполнена.\n";
        return;
    }

    Resident r;
    cout << "Введите ПIБ жильца: ";
    cin.ignore();
    cin.getline(r.name, 50);
    cout << "Введите возраст: ";
    cin >> r.age;
    r.assigned = true;

    apartment.residents[apartment.residentCount++] = r;
}

//Выводит все квартиры и всех жильцов на экран.
void showAll(const Apartment apartments[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nКвартира " << apartments[i].number
            << ", этаж: " << apartments[i].floor
            << ", комнат: " << apartments[i].rooms << endl;

        for (int j = 0; j < apartments[i].residentCount; j++) {
            cout << "  - " << apartments[i].residents[j].name
                << ", возраст: " << apartments[i].residents[j].age << endl;
        }
    }
}

//Сохраняет все данные
void saveToFile(const Apartment apartments[], int count) {
    ofstream file("apartments.txt");
    if (!file) {
        cout << "Ошибка при открытии файла для записи!\n";
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        const Apartment& a = apartments[i];
        file << a.number << " " << a.floor << " " << a.rooms << " " << a.residentCount << endl;
        for (int j = 0; j < a.residentCount; j++) {
            file << a.residents[j].name << endl;
            file << a.residents[j].age << endl;
        }
    }

    file.close();
    cout << "Данные сохранены в файл apartments.txt\n";
}

//Загружает данные из файла
void loadFromFile(Apartment apartments[], int& count) {
    ifstream file("apartments.txt");
    if (!file) {
        cout << "Файл не найден!\n";
        return;
    }

    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++) {
        Apartment& a = apartments[i];
        file >> a.number >> a.floor >> a.rooms >> a.residentCount;
        file.ignore();

        for (int j = 0; j < a.residentCount; j++) {
            file.getline(a.residents[j].name, 50);
            file >> a.residents[j].age;
            file.ignore();
            a.residents[j].assigned = true;
        }
    }

    file.close();
    
}
