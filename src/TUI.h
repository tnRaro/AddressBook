#pragma once

#include <vector>

class User;


class TUI {
public:
    enum class State {
        IDLE,
        ADD,
        SEARCH,
        PRINT,
        REMOVE,
        EXIT,
    };
    explicit TUI(std::vector<User*>& list);
    ~TUI();
protected:
    std::vector<User*>& list;
    bool opened;
    State state;
public:
    State getState() const;
    void setState(State next_state);
    void setState(int next_state);
    bool isOpened() const;
    void close();

    void add();
    void search();
    void print();
    void remove();
protected:
    State toState(int state) const{
        switch (state) {
            case 0: return State::EXIT;
            case 1: return State::ADD;
            case 2: return State::SEARCH;
            case 3: return State::PRINT;
            case 4: return State::REMOVE;
            default:
                return State::IDLE;
        }
    }
};