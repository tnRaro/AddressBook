#pragma once

#include <vector>
#include <string>

class User;

class AddressBook {
protected:
    enum class UI { TUI };      // UI 제어용 더미 자료형입니다.
    char state = 'i';           // 상태를 담습니다.
    std::vector<User*> users;   // 유저 목록입니다.
public:
    AddressBook() = default;    // 기본 생성자입니다.
    int run();                  // 프로그램을 돌립니다.
protected:
    // 데이터 제어 메소드
    void add(const std::string& name, const std::string& phone);
    void add(User* user);
    User* find(const std::string& name) const;
    void print(User* user) const;
    void print() const;
    void remove(const std::string& name);

    // UI 제어용 메소드
    void add(UI);
    void find(UI);
    void print(UI) const;
    void remove(UI);
};