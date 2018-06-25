#pragma once

#include <string>

class User {
    friend class AddressBook;   // 맴버 변수에 직접 접근하고 싶었기에 friend를 정의했습니다.
protected:
    std::string name;
    std::string phone;
public:
    User() = default;
    User(const std::string& name, const std::string& phone);
};