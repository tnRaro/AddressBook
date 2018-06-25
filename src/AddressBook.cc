#include "AddressBook.h"
#include "User.h"

#include <iostream>

using namespace std;

AddressBook::AddressBook() {
    
}

int AddressBook::run() {
    while (state != 'q') {
        cout << "[A]dd [S]earch [D]a print [R]emove [Q]uit" << endl;

        try {
            cin >> state;

            switch (state) {
                case 'a':
                case 'A':
                    add(UI::TUI);
                    state = 'i';
                    break;
                case 's':
                case 'S':
                    find(UI::TUI);
                    state = 'i';
                    break;
                case 'd':
                case 'D':
                    print(UI::TUI);
                    state = 'i';
                    break;
                case 'r':
                case 'R':
                    remove(UI::TUI);
                    state = 'i';
                    break;
                case 'q':
                case 'Q':
                    state = 'q';
                    break;
                default:
                    state = 'i';
            }

        } catch(const char* err) {
            cerr << err << endl;
        }
    }

    return 0;
}

void AddressBook::add(const std::string& name, const std::string& phone) {
    User* user = new User(name, phone);

    add(user);
}
void AddressBook::add(User* user) {
    // validate name
    for (auto user2 : users) {
        if (user2->name.compare(user->name) == 0) {
            throw "ERR! Exist same name";
        }
    }
    users.push_back(user);
}
User* AddressBook::find(const std::string& name) const {
    for (auto user : users) {
        if (user->name.compare(name) == 0) {
            return user;
        }
    }
    throw "ERR! Not Found";
}
void AddressBook::print(User* user) const {
    cout << user->name << " ("
         << user->phone << ")" << endl;
}
void AddressBook::print() const {
    for (auto user : users) {
        print(user);
    }
}
void AddressBook::remove(const std::string& name) {
    for (vector<User*>::iterator it = users.begin(); it != users.end(); it++) {
        User* user = *it;
        if (user->name.compare(name) == 0) {
            users.erase(it);
            delete user;
            break;
        }
    }
}

void AddressBook::add(AddressBook::UI ui) {
    cout << "#### Add User ####\n";

    char name[32];
    char phone[32];
    
    cout << "name: ";
    cin >> name;
    cout << "phone: ";
    cin >> phone;

    add(name, phone);
}
void AddressBook::find(AddressBook::UI ui) {
    cout << "#### Search User ####\n";
    char name[32];
    
    cout << "name: ";
    cin >> name;

    User* user = find(name);

    print(user);
}
void AddressBook::print(AddressBook::UI ui) const {
    cout << "#### Print Users ####\n";
    
    print();
}
void AddressBook::remove(AddressBook::UI ui) {
    cout << "#### Remove User ####\n";
    char name[32];
    
    cout << "name: ";
    cin >> name;

    remove(name);
}