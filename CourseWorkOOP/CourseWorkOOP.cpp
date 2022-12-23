#include <string>
#include <iostream>
#include <fstream>
#include <locale>
#include <Windows.h>

using namespace std;

class CPassGen
{
private:
    string pass;
public:
    CPassGen();
    string getPassword(int length);
    void   getPassword();
};

CPassGen::CPassGen()
{
    srand(time(0));
}

string CPassGen::getPassword(int length)
{
    string password = "";
    for (int i = 0; i < length; i++)
        password += char('0' + rand() % ('z' - '0'));
    return password;
}
bool FileIsExist(string filePath)
{
    bool isExist = true;
    ifstream fout(filePath.c_str());
    ifstream file(filePath.c_str());
    if (fout.is_open())
        isExist = false;
    if (file.is_open())
        isExist = false;
    return isExist;
}

void CPassGen::getPassword()
{
    int k;
    int length = 0;
    int count = 0;
    string password;
    while (true) {
        while (true) {
            cout << "\x1b[32mВведите длину пароля : \x1b[0m";
            cin >> length;
            while (!(cin) >> length)
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "\x1b[31m\nОшибка ввода\n\x1b[0m" << endl;
            }
            break;
        }
        if (length) {
            while (true) {
                cout << "\x1b[32mВведите количество паролей: \x1b[0m";
                cin >> count;
                while (!(cin) >> count)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m\nОшибка ввода\n\x1b[0m" << endl;

                }
                if (count) {
                    cout << "Сгенерированные пароли : \n";

                    for (k = 0; k < count; k++)
                    {
                        password = getPassword(length);
                        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                        cout << "Пароль #" << k + 1 << " : " << password << endl;

                    }
                    break;
                }
            }

        }
        if (count) {
            break;
        }
    }
}


class CPassGen1
{
private:
    string pass1;
public:
    CPassGen1();
    string getPassword1(int length);
    void   getPassword1();
};

CPassGen1::CPassGen1()
{
    srand(time(0));
}

string CPassGen1::getPassword1(int length)
{
    string password = "";
    for (int i = 0; i < length; i++)
        password += char('0' + rand() % ('z' - '0'));
    return password;
}

void CPassGen1::getPassword1()
{
    int k;
    int length = 0;
    int count = 0;
    string password;

    string gde;
    string l = "input.txt";
    cout << "\x1b[32mУкажите расположение файла input.txt (Пример: G:\\)\n \x1b[0m";
    cin >> gde;

    ifstream fout(gde.c_str() + l);

    while (true) {
        if (fout.is_open()) {
            while (true) {
                fout >> length;
                while (!(fout) >> length)
                {
                    fout.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m\nОшибка чтения файла: строка #1\x1b[0m" << endl;
                    fout.close();
                }
                break;
            }
            if (length) {
                fout >> count;
                while (!(fout) >> count)
                {
                    fout.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m\nОшибка чтения файла: строка #2\x1b[0m" << endl;
                    fout.close();
                }
                if (count & length) {

                    cout << "\x1b[32mС файла input.txt были считаны исходные данный\x1b[0m\nРезультат: \n";
                    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                    for (k = 0; k < count; k++)
                    {
                        password = getPassword1(length);
                        SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                        cout << "Пароль #" << k + 1 << " : " << password << endl;


                    }
                    fout.clear();
                    fout.close();
                }
            }

        }
        else
            cout << "\x1b[31mОшибка: файл input.txt не найден\n\x1b[0m";
        fout.clear();
        fout.close();
        break;
    }
}


class CPassGen2
{
private:
    string pass2;
public:
    CPassGen2();
    string getPassword2(int length);
    void   getPassword2();
};

CPassGen2::CPassGen2()
{
    srand(time(0));
}

string CPassGen2::getPassword2(int length)
{
    string password = "";
    for (int i = 0; i < length; i++)
        password += char('0' + rand() % ('z' - '0'));
    return password;
}

void CPassGen2::getPassword2()
{
    int k;
    int length = 0;
    int count = 0;

    string gde1;
    string v = "data.txt";
    cout << "\x1b[32mУкажите расположение файла data.txt (Пример: G:\\)\n \x1b[0m";
    cin >> gde1;

    ifstream file(gde1.c_str() + v);
    while (true) {
        if (file.is_open()) {
            while (true) {
                file >> length;
                while (!(file) >> length)
                {
                    file.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m\nОшибка чтения файла: строка #1\x1b[0m" << endl;
                    file.close();
                }
                break;
            }
            if (length) {
                file >> count;
                while (!(file) >> count)
                {
                    file.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m\nОшибка чтения файла: строка #2\x1b[0m" << endl;
                    file.close();
                }
                if (count & length) {
                    cout << "С файла data.txt были считаны исходные данный\n";
                    string gde2;
                    string f = "output.txt";
                    cout << "\x1b[32mУкажите расположение, в которое требуется сохранить файл output.txt (Пример: G:\\)\n \x1b[0m ";
                    cin >> gde2;

                    string password;
                    ofstream output(gde2.c_str() + f);
                    cout << "\x1b[32mРезультат записан по пути: \n\x1b[0m" << gde2.c_str() + f << "\n";
                    for (k = 0; k < count; k++)
                    {
                        password = getPassword2(length);
                        output << "Пароль #" << k + 1 << " : " << password << endl;

                    }
                    output.clear();
                    output.close();
                }
            }
            file.clear();
            file.close();

        }
        else
            cout << "\x1b[31mОшибка: файл data.txt не найден\n\x1b[0m";
        file.clear();
        file.close();
        break;
    }

}


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitleA("Генератор уникальных паролей");
    int num = 1;
    bool exit = false;
    string ss = "\x1b[33m\n                                             Генератор уникальных паролей\n\x1b[0m";
    string s = "\x1b[33m\nРежимы работы программы: \x1b[0m\x1b[37m\n1. Интерактивный \x1b[36m(ввод и вывод в консоли)\x1b[0m\n2. Полуинтерактивный \x1b[36m(данные из файла input.txt, вывод в консоли)\x1b[0m\n3. Неинтерактивный \x1b[36m(данные из файла data.txt, запись в файл output.txt)\x1b[0m\n4. Очистка консоли\n5. Выход из программы\n\x1b[0m";
    cout << ss;
    cout << s;
    while (!exit) {
        cout << "\x1b[33m\nНомер операции > \x1b[0m";
        cin >> num;
        while (!(cin) >> num)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31m\nОшибка ввода\n\x1b[0m" << endl;
        }

        switch (num) {
        case 1:
        {
            CPassGen pPass;
            pPass.getPassword();
            break;

        }
        case 2:
        {
            CPassGen1 pPass;
            pPass.getPassword1();
            break;
        }
        case 3:
        {
            CPassGen2 pPass;
            pPass.getPassword2();
            break;
        }
        case 4:
        {

            system("cls");
            cout << ss;
            cout << s;
            break;
        }
        case 5:
        {
            exit = true;
            break;
        }
        }
    }
    system("pause");
    return 0;
}