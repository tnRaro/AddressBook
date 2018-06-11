#pragma once

class User {
public:
    User() = default;
    User(const char* name, const char* phone);
    ~User() = default;
    
    const char* getName() const;
    const char* getPhone() const;
protected:
    char name[32];
    char phone[32];
};