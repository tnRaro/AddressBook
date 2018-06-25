#pragma once

#include <string>

class User {
    friend class AddressBook;
protected:
    std::string name;
    std::string phone;
public:
    User() = default;
    User(const std::string& name, const std::string& phone);
};