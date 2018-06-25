#include "AddressBook.h"
#include "User.h"

#include <iostream>

using namespace std;

int AddressBook::run() {
    int input;
    // 프로그램 루틴이 시작됩니다.
    // 상태가 `q`(종료)가 아닐 경우 실행됩니다.
    while (state != 'q') {
        cout << "[A]dd [S]earch [D]a print [R]emove [Q]uit" << endl;

        try {
            cin >> input;   // 다음 상태를 입력받습니다.

            switch (input) {
                case 'a':
                case 'A':
                    // 다음 상태가 `a`(추가) 이면, void add(UI)를 호출합니다.
                    add(UI::TUI);
                    state = 'i';
                    break;
                case 's':
                case 'S':
                    // 다음 상태가 `s`(검색) 이면, void find(UI)를 호출합니다.
                    find(UI::TUI);
                    state = 'i';
                    break;
                case 'd':
                case 'D':
                    // 다음 상태가 `d`(출력) 이면, void print(UI) const를 호출합니다.
                    print(UI::TUI);
                    state = 'i';
                    break;
                case 'r':
                case 'R':
                    // 다음 상태가 `r`(제거) 이면, void remove(UI)를 호출합니다.
                    remove(UI::TUI);
                    state = 'i';
                    break;
                case 'q':
                case 'Q':
                    // 다음 상태가 `q`(q) 이면, 상태를 q로 바꿉니다.
                    state = 'q';
                    break;
                default:
                    // 그 외의 모든 입력은 `i`(대기)로 간주합니다.
                    state = 'i';
            }

        } catch(const char* err) {    // 예외처리
            cerr << err << endl;      // 예외 메시지를 출력합니다.
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
            throw "ERR! Exist same name";   // 유저 이름이 유일하지 않으면 예외를 발생시킵니다.
        }
    }
    users.push_back(user);  // 유저목록에 유저를 추가합니다.
}
User* AddressBook::find(const std::string& name) const {
    for (auto user : users) {
        if (user->name.compare(name) == 0) {
            return user;    // 유저 반환
        }
    }
    throw "ERR! Not Found"; // 유저가 없으면 예외를 발생시킵니다.
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
            users.erase(it);    // 유저 목록에서 제거합니다.
            delete user;        // 유저를 메모리에서 해제합니다.
            break;              // 유저 이름은 unique하므로 루프를 멈추는 것이 좋습니다.
        }
    }
}

// 이하 UI용 메소드입니다.
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