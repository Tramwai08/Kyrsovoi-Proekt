#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#pragma region ��������� define
#define E << endl;
#define O cout <<
#define A cin >>
#define B break;
#pragma endregion

using namespace std;

#pragma region ���������
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

#pragma region �������
void add(Dela dels) {
    O "\n������� �������� ����: ";
    cin.ignore();
    getline(cin, dels.name);
    mas_file[kol_file] = dels.name;
    kol_file++;
    O "\n������� ��������� ����: ";
    getline(cin, dels.prioritet);
    O "\n������� ����\n�����: ";
    A dels.data;
    mas_data1[kol_data1] = dels.data;
    kol_data1++;
    O "\n�����: ";
    A dels.data2;
    mas_data2[kol_data2] = dels.data2;
    kol_data2++;
    O "\n������� �����: ";
    cin.ignore();
    getline(cin, dels.time);
    O "\n������� �������� � ����: ";
    getline(cin, dels.txt);
    ofstream file("./spisok/" + dels.name + ".txt");
    if (file) {
        file << "��������: " << dels.name E;
        file << "���������: " << dels.prioritet E;
        file << "����: " << dels.data << "." << dels.data2 E;
        file << "�����: " << dels.time E;
        file << "��������: \n" << dels.txt E;
        file << "*********************************************************" << endl;
        file.close();
        O endl;
        cout << "\x1b[32m���� ���� ������� ��������� � ��������� � ������\x1b[0m";
    }
    else  O "������ ����� ";
}

void del(Dela dels) {
    string name2;
    O endl;
    O "������� �������� ����, ������� ����� �������: ";
    cin.ignore();
    getline(cin, name2);
    if (remove(("./spisok/" + name2 + ".txt").c_str()) != 0) {
        O "\x1b[31m������ ��� �������� ����\x1b[0m" E;
    }
    else  O endl << "\x1b[32m���� ������� �������\x1b[0m" E;
}

void red(Dela dels) {
    string name3;
    O endl;
    O "������� �������� ���� ��� ��������������: ";
    A name3;
    ifstream file1("./spisok/" + name3 + ".txt");
    if (!file1) {
        O "\x1b[31m���� �� ������ \x1b[0m";
        exit(0);
    }
    O "\n������� �������� ����: ";
    cin.ignore();
    getline(cin, dels.name);
    O "\n������� ��������� ����: ";
    getline(cin, dels.prioritet);
    O "\n������� ����\n�����: ";
    A dels.data;
    mas_data1[kol_data1] = dels.data;
    O "\n�����: ";
    A dels.data2;
    mas_data2[kol_data2] = dels.data2;
    O "\n������� �����: ";
    cin.ignore();
    getline(cin, dels.time);
    O "\n������� �������� � ����: ";
    getline(cin, dels.txt);
    ofstream file("./spisok/" + name3 + ".txt");
    if (file) {
        file << "��������: " << dels.name E;
        file << "���������: " << dels.prioritet E;
        file << "����: " << dels.data << "." << dels.data2 E;
        file << "�����: " << dels.time  E;
        file << "��������: \n" << dels.txt E;
        file << "*******************************************************" << endl;
        file.close();
        O endl;
        O "\x1b[32m���� ���� ������� ��������������� � ��������� � ������ \x1b[0m";
    }
    else  O "\x1b[31m������ ����� \x1b[0m";
}

void poisk(Dela dels) {
    int vib;
    O "\n�������� �� ���� ����� ������������� �����:\n";
    O "[1]-�� ��������\n";
    O "[2]-�� ����������\n";
    O "[3]-�� ����\n";
    O "[4]-�� �������\n";
    O "[5]-�� ��������\n";
    O "��� �����: ";
    A vib;
    switch (vib) {
    case 1: {
        string name2;
        O "\n������� �������� ����: ";
        A name2;
        ifstream file1("./spisok/" + name2 + ".txt", ios::in);
        if (!file1) {
            O "\x1b[31m���� �� ������  \x1b[0m";
            exit(0);
        }
        O endl;
        O "\x1b[32m���� ����: \x1b[0m" E;
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
        O "\n������� ���������: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32m��������� ��� ������ � ����� \x1b[0m" << mas_file[i];
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
        O "\n������� ����: ";
        cin.ignore();
        A name2;
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32m���� ���� ������� � ����� \x1b[0m" << mas_file[i];
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
        O "\n������� �����: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32m����� ������� � ����� \x1b[0m" << mas_file[i];
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
        O "\n������� ��������: ";
        cin.ignore();
        getline(cin, name2);
        for (int i = 0; i < kol_file; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            while (file2 >> line) {
                if (line == name2) {
                    char txt[256];
                    O endl;
                    O "\x1b[32m������ �������� ������� � ����� \x1b[0m" << mas_file[i];
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
    default:  O "�������� ����!";
    }
}

void vivod(Dela dels) {
    int vib;
    int data2, data1;
    O "�������� ������ ������ ���:\n[1]-�� ����\n[2]-�� ������\n[3]-�� �����\n��� �����: ";
    A vib;

    switch (vib) {
    case 1: {
        O "\n������� ����������� ����\n����: ";
        A data1;
        O "\n�����: ";
        A data2;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data1[i] == data1 && mas_data2[i] == data2) {
                O endl;
                O "\x1b[32m���� ���� �� ����:\x1b[0m";
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
        O "\n������� ����������� ����: ";
        A data1;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data1[i] == data1 || mas_data1[i] <= data1 + 7) {
                O endl;
                O "\x1b[32m���� ���� �� ������:\x1b[0m";
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
        O "\n������� ����������� ����\n����: ";
        A data1;
        O "\n�����: ";
        A data2;
        for (int i = 0; i < kol_data1; i++) {
            ifstream file2("./spisok/" + mas_file[i] + ".txt", ios::in);
            if (mas_data2[i] == data2) {
                O endl;
                O "\x1b[32m���� ���� �� �����:\x1b[0m";
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
    default:  O "\x1b[31m�������� ����!\x1b[0m";
    }
}
#pragma endregion 

int main() {

    setlocale(LC_ALL, "RUS");

    Dela dels;
    int vib;

    do {
        string mas[99];
        O "\n\n\t\t\t\t\t\t������ ����� ���\n\n";
        O "�������� ��������:\n[1]�������� ����\n[2]�������\n[3]�������������\n[4]�����\n[5]����� ���� �� �����\n[6]-�����\n��� �����: ";
        cin >> vib;
        switch (vib) {
#pragma region ����
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