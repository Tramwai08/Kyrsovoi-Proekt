#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#pragma region Директивы define
#define E << endl;
#define O cout <<
#define A cin >>
#define B break;
#pragma endregion

using namespace std;

#pragma region Структура
struct Dela {
    string name;
    string prioritet;
    int data;
    int data2;
    string time;
    string txt;
};
#pragma endregion

string* mas_file = new string[99];
int kol_file = 0;
int* mas_data1 = new int[99];
int* mas_data2 = new int[99];
int kol_data2 = 0;
int kol_data1 = 0;

#pragma region Функции
void add(Dela dels) {
    O "\nВведите название дела: ";
    cin.ignore();
    getline(cin, dels.name);
    mas_file[kol_file] = dels.name;
    kol_file++;
    O "\nВведите приоритет дела: ";
    getline(cin, dels.prioritet);
    O "\nВведите дату\nЧисло: ";
    A dels.data;
    mas_data1[kol_data1] = dels.data;
    kol_data1++;
    O "\nМесяц: ";
    A dels.data2;
    mas_data2[kol_data2] = dels.data2;
    kol_data2++;
    O "\nВведите время: ";
    cin.ignore();
    getline(cin, dels.time);
    O "\nВведите описание к делу: ";
    getline(cin, dels.txt);
    ofstream file("./spisok/" + dels.name + ".txt");
    if (file) {
        file << "Название: " << dels.name E;
        file << "Приоритет: " << dels.prioritet E;
        file << "Дата: " << dels.data << "." << dels.data2 E;
        file << "Время: " << dels.time E;
        file << "Описание: \n" << dels.txt E;
        file << "*********************************************************" << endl;
        file.close();
        O endl;
        cout << "\x1b[32mДело было успешно добавлено и сохранено в список\x1b[0m";
    }
    else  O "Ошибка файла ";
}

void del(Dela dels) {
    string name2;
    O endl;
    O "Введите название дела, которое нужно удалить: ";
    cin.ignore();
    getline(cin, name2);
    if (remove(("./spisok/" + name2 + ".txt").c_str()) != 0) {
        O "\x1b[31mОшибка при удалении дела\x1b[0m" E;
    }
    else  O endl << "\x1b[32mДело успешно удалено\x1b[0m" E;
}

void red(Dela dels) {
    string name3;
    O endl;
    O "Введите название дела для редактирования: ";
    A name3;
    ifstream file1("./spisok/" + name3 + ".txt");
    if (!file1) {
        O "\x1b[31mФайл не найден \x1b[0m";
        exit(0);
    }
    O "\nВведите название дела: ";
    cin.ignore();
    getline(cin, dels.name);
    O "\nВведите приоритет дела: ";
    getline(cin, dels.prioritet);
    O "\nВведите дату\nЧисло: ";
    A dels.data;
    mas_data1[kol_data1] = dels.data;
    O "\nМесяц: ";
    A dels.data2;
    mas_data2[kol_data2] = dels.data2;
    O "\nВведите время: ";
    cin.ignore();
    getline(cin, dels.time);
    O "\nВведите описание к делу: ";
    getline(cin, dels.txt);
    ofstream file("./spisok/" + name3 + ".txt");
    if (file) {
        file << "Название: " << dels.name E;
        file << "Приоритет: " << dels.prioritet E;
        file << "Дата: " << dels.data << "." << dels.data2 E;
        file << "Время: " << dels.time  E;
        file << "Описание: \n" << dels.txt E;
        file << "*******************************************************" << endl;
        file.close();
        O endl;
        O "\x1b[32mДело было успешно отредактировано и сохранено в список \x1b[0m";
    }
    else  O "\x1b[31mОшибка файла \x1b[0m";
}

void poisk(Dela dels) {
    int vib;
    O "\nВыберите по чему будет производиться поиск:\n";
    O "[1]-По названию\n";
    O "[2]-По приоритету\n";
    O "[3]-По дате\n";
    O "[4]-По времени\n";
    O "[5]-По описанию\n";
    O "Ваш выбор: ";
    A vib;
    switch (vib) {
    case 1: {
        string name2;
        O "\nВведите название дела: ";
        A name2;
        ifstream file1("./spisok/" + name2 + ".txt", ios::in);
        if (!file1) {
            O "\x1b[31mФайл не найден  \x1b[0m";
            exit(0);
        }
        O endl;
        O "\x1b[32mВаше дело: \x1b[0m" E;
        O endl;
        char txt[256];
        while (!file1.eof()) {
            file1.getline(txt, 256);
            if (file1) {
                O txt E;
            }
        }
        B;
    }
    case 2: {
        string name2, line;
        O "\nВведите приоритет: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32mПриоритет был найден в файле \x1b[0m" << mas_file[i];
                    O endl;
                    file2.close();
                    file2.open("./spisok/" + mas_file[i] + ".txt", ios::in);
                    while (!file2.eof()) {
                        file2.getline(txt, 256);
                        if (file2) {
                            O endl;
                            O txt E;
                        }
                    }
                }
            }
        }
        B;
    }
    case 3: {
        string name2, line;
        O "\nВведите дату: ";
        cin.ignore();
        A name2;
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32mДата была найдена в файле \x1b[0m" << mas_file[i];
                    O endl;
                    file2.close();
                    file2.open("./spisok/" + mas_file[i] + ".txt", ios::in);
                    while (!file2.eof()) {
                        file2.getline(txt, 256);
                        if (file2) {
                            O endl;
                            O txt E;
                        }
                    }
                }
            }
        }
        break;
    }
    case 4: {
        string name2, line;
        O "\nВведите время: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32mВремя совпало в файле \x1b[0m" << mas_file[i];
                    O endl;
                    file2.close();
                    file2.open("./spisok/" + mas_file[i] + ".txt", ios::in);
                    while (!file2.eof()) {
                        file2.getline(txt, 256);
                        if (file2) {
                            O endl;
                            O txt E;
                        }
                    }
                }
            }
        }
        break;
    }
    case 5: {
        string name2, line;
        O "\nВведите описание: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32mДанное описание найдено в файле \x1b[0m" << mas_file[i];
                    O endl;
                    file2.close();
                    file2.open("./spisok/" + mas_file[i] + ".txt", ios::in);
                    while (!file2.eof()) {
                        file2.getline(txt, 256);
                        if (file2) {
                            O endl;
                            O txt E;
                        }
                    }
                }
            }
        }
        break;
    }
    default:  O "Неверный ввод!";
    }
}

void vivod(Dela dels) {
    int vib;
    int data2, data1;
    O "Выберите способ вывода дел:\n[1]-На день\n[2]-На неделю\n[3]-На месяц\nВаш выбор: ";
    A vib;

    switch (vib) {
    case 1: {
        O "\nВведите сегодняшнюю дату\nДата: ";
        A data1;
        O "\nМесяц: ";
        A data2;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data1[i] == data1 && mas_data2[i] == data2) {
                O endl;
                O "\x1b[32mВаши дела на день:\x1b[0m";
                char txt[256];
                while (!file2.eof()) {
                    file2.getline(txt, 256);
                    if (file2) {
                        O endl;
                        O txt E;
                    }
                }
            }
        }
        break;
    }
    case 2: {
        O "\nВведите сегодняшнюю дату: ";
        A data1;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data1[i] == data1 || mas_data1[i] <= data1 + 7) {
                O endl;
                O "\x1b[32mВаши дела на неделю:\x1b[0m";
                char txt[256];
                while (!file2.eof()) {
                    file2.getline(txt, 256);
                    if (file2) {
                        O endl;
                        O txt E;
                    }
                }
            }
        }
        break;
    }
    case 3: {
        O "\nВведите сегодняшнюю дату\nДата: ";
        A data1;
        O "\nМесяц: ";
        A data2;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data2[i] == data2) {
                O endl;
                O "\x1b[32mВаши дела на месяц:\x1b[0m";
                char txt[256];
                while (!file2.eof()) {
                    file2.getline(txt, 256);
                    if (file2) {
                        O endl;
                        O txt E;
                    }
                }
            }
        }
        break;
    }
    default:  O "\x1b[31mНеверный ввод!\x1b[0m";
    }
}
#pragma endregion 

int main() {

    setlocale(LC_ALL, "RUS");

    Dela dels;
    int vib;

    do {
        string mas[99];
        O "\n\n\t\t\t\t\t\tСписок ваших дел\n\n";
        O "Выберите действие:\n[1]Добавить дело\n[2]Удалить\n[3]Редактировать\n[4]Поиск\n[5]Вывод дела на экран\n[6]-Выход\nВаш выбор: ";
        cin >> vib;
        switch (vib) {
#pragma region Меню
        case 1:
            add(dels);
            B;

        case 2:
            del(dels);
            B;

        case 3:
            red(dels);
            B;

        case 4:
            poisk(dels);
            B;
        case 5:
            vivod(dels);
            B;
        }
#pragma endregion

    } while (vib != 6);
}