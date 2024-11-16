#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

class Directory {
private:
    string company_name;
    string owner;
    string phone;
    string address;
    string type_activity;

public:
    Directory() : company_name(""), owner(""), phone(""), address(""), type_activity("") {}

    Directory(string company, string owner, string phone, string address, string activity)
        : company_name(company), owner(owner), phone(phone), address(address), type_activity(activity) {}

    string getCompany_name() const { return company_name; }
    string getOwner() const { return owner; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }
    string getType_activity() const { return type_activity; }

    void add_info(fstream& file) {
        file << company_name << "\n" << owner << "\n" << phone << "\n" << address << "\n" << type_activity << endl;
    }

    static void search_name(const string& searchName, fstream& file) {
        string company_name, owner, phone, address, type_activity;
        bool search = false;
        file.clear();
        file.seekg(0);
        while (getline(file, company_name)) {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, type_activity);

            if (company_name == searchName) {
                search = true;
                cout << "\nФірма знайдена: \n";
                cout << "=============================\n";
                cout << "Назва фірми: " << company_name << endl;
                cout << "Власник: " << owner << endl;
                cout << "Телефон: " << phone << endl;
                cout << "Адреса: " << address << endl;
                cout << "Рід діяльності: " << type_activity << endl;
                cout << "=============================\n";
                break;
            }
        }
        if (!search) {
            cout << "Фірму з таким ім'ям не знайдено\n";
        }
    }

    static void search_owner(const string& searchOwner, fstream& file) {
        string company_name, owner, phone, address, type_activity;
        bool search = false;
        file.clear();
        file.seekg(0);
        while (getline(file, company_name)) {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, type_activity);

            if (owner == searchOwner) {
                search = true;
                cout << "\nВласник знайдений: \n";
                cout << "=============================\n";
                cout << "Назва фірми: " << company_name << endl;
                cout << "Власник: " << owner << endl;
                cout << "Телефон: " << phone << endl;
                cout << "Адреса: " << address << endl;
                cout << "Рід діяльності: " << type_activity << endl;
                cout << "=============================\n";
                break;
            }
        }
        if (!search) {
            cout << "Власника з таким ім'ям не знайдено\n";
        }
    }

    static void search_phone(const string& searchPhone, fstream& file) {
        string company_name, owner, phone, address, type_activity;
        bool search = false;
        file.clear();
        file.seekg(0);
        while (getline(file, company_name)) {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, type_activity);

            if (phone == searchPhone) {
                search = true;
                cout << "\nТелефон знайдений: \n";
                cout << "=============================\n";
                cout << "Назва фірми: " << company_name << endl;
                cout << "Власник: " << owner << endl;
                cout << "Телефон: " << phone << endl;
                cout << "Адреса: " << address << endl;
                cout << "Рід діяльності: " << type_activity << endl;
                cout << "=============================\n";
                break;
            }
        }
        if (!search) {
            cout << "Телефон з таким номером не знайдено\n";
        }
    }

    static void search_activity(const string& searchActivity, fstream& file) {
        string company_name, owner, phone, address, type_activity;
        bool search = false;
        file.clear();
        file.seekg(0);
        while (getline(file, company_name)) {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, type_activity);

            if (type_activity == searchActivity) {
                search = true;
                cout << "\nРід діяльності знайдений: \n";
                cout << "=============================\n";
                cout << "Назва фірми: " << company_name << endl;
                cout << "Власник: " << owner << endl;
                cout << "Телефон: " << phone << endl;
                cout << "Адреса: " << address << endl;
                cout << "Рід діяльності: " << type_activity << endl;
                cout << "=============================\n";
                break;
            }
        }
        if (!search) {
            cout << "Рід діяльності не знайдений\n";
        }
    }

    static void display(fstream& file) {
        string company_name, owner, phone, address, type_activity;
        file.clear();
        file.seekg(0);
        while (getline(file, company_name)) {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, type_activity);
            cout << "\n=============================\n";
            cout << "Назва фірми: " << company_name << endl;
            cout << "Власник: " << owner << endl;
            cout << "Телефон: " << phone << endl;
            cout << "Адреса: " << address << endl;
            cout << "Рід діяльності: " << type_activity << endl;
            cout << "=============================\n";
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string fileName = "directory.txt";
    fstream file(fileName, ios::in | ios::out | ios::app);
    int choice;
    string name, owner, phone, address, activity;
    Directory newRecord(name, owner, phone, address, activity);


    do {
        cout << "\nМеню:\n";
        cout << "=============================\n";
        cout << "1. Додати запис\n";
        cout << "2. Пошук за назвою\n";
        cout << "3. Пошук за власником\n";
        cout << "4. Пошук за номером телефону\n";
        cout << "5. Пошук за родом діяльності\n";
        cout << "6. Вивести всі записи\n";
        cout << "0. Вийти\n";
        cout << "=============================\n";
        cout << "Вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();
            cout << "Введіть назву фірми: ";
            getline(cin, name);
            cout << "Введіть власника: ";
            getline(cin, owner);
            cout << "Введіть телефон: ";
            getline(cin, phone);
            cout << "Введіть адресу: ";
            getline(cin, address);
            cout << "Введіть рід діяльності: ";
            getline(cin, activity);
            newRecord = Directory(name, owner, phone, address, activity);
            newRecord.add_info(file);
            cout << "Запис успішно додано!\n";
            break;
        case 2:
            cin.ignore();
            cout << "Введіть назву фірми для пошуку: ";
            getline(cin, name);
            Directory::search_name(name, file);
            break;
        case 3:
            cin.ignore();
            cout << "Введіть власника для пошуку: ";
            getline(cin, owner);
            Directory::search_owner(owner, file);
            break;
        case 4:
            cin.ignore();
            cout << "Введіть номер телефону для пошуку: ";
            getline(cin, phone);
            Directory::search_phone(phone, file);
            break;
        case 5:
            cin.ignore();
            cout << "Введіть рід діяльності для пошуку: ";
            getline(cin, activity);
            Directory::search_activity(activity, file);
            break;
        case 6:
            Directory::display(file);
            break;
        case 0:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Оберіть від 0-6\n";
        }
    } while (choice != 0);

    file.close();
    return 0;
}
