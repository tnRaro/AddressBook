#pragma once

#include <vector>
#include <string>

class User;

class AddressBook {
protected:
    enum class UI { TUI };
    char state = 'i';
    std::vector<User*> users;
public:
    AddressBook();
    int run();
protected:
    void add(const std::string& name, const std::string& phone);
    void add(User* user);
    User* find(const std::string& name) const;
    void print(User* user) const;
    void print() const;
    void remove(const std::string& name);

    void add(UI);
    void find(UI);
    void print(UI) const;
    void remove(UI);
};