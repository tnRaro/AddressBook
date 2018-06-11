#include <iostream>
#include <cstring>

#include "User.h"

using namespace std;

User::User(const char* name, const char* phone) {
    strcpy(this->name, name);
    strcpy(this->phone, phone);
}

const char* User::getName() const { return name; }
const char* User::getPhone() const { return phone; }

#include "TUI.h"

TUI::TUI(std::vector<User*>& list): list(list),
                                    opened(true),
                                    state(TUI::State::IDLE) {
    
}

TUI::~TUI() {
    for(User* user : list) {
        delete user;
    }
    list.clear();
}

TUI::State TUI::getState()  const{
    return state;
}

void TUI::setState(TUI::State next_state) {
    state = next_state;
}

void TUI::setState(int next_state) {
    TUI::setState(toState(next_state));
}

bool TUI::isOpened()  const{
    return opened;
}

void TUI::close() {
    opened = false;
}

void TUI::add() {
    cout << "#### Add User ####\n";

    char name[32];
    char phone[32];
    
    cout << "name: ";
    cin >> name;
    cout << "phone: ";
    cin >> phone;

    // validate name
    for (User* const& user : list) {
        if (strcmp(user->getName(), name) == 0) {
            cerr << "ERR! Exist same name." << endl;
            return;
        }
    }

    User* user = new User(name, phone);

    list.push_back(user);
}

void TUI::search() {
    cout << "#### Search User ####\n";
    char name[32];
    
    cout << "name: ";
    cin >> name;

    for (User* const& user : list) {
        if (strcmp(user->getName(), name) == 0) {
            cout << user->getName() << ", "
                 << user->getPhone() << endl;
            break;
        }
    }
}

void TUI::print() {
    cout << "#### Print Users ####\n";
    for (User* const& user : list) {
        cout << user->getName() << ", "
             << user->getPhone() << '\n';
    }
    cout << flush;
}

void TUI::remove() {
    cout << "#### Remove User ####\n";
    char name[32];
    
    cout << "name: ";
    cin >> name;

    for (vector<User*>::iterator it = list.begin(); it != list.end(); it++) {
        User* user = *it;
        if (strcmp(user->getName(), name) == 0) {
            list.erase(it);
            delete user;
            break;
        }
    }
}