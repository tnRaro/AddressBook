#include <iostream>

#include "User.h"
#include "TUI.h"

using namespace std;

int main() {
    vector<User*> list;

    TUI tui(list);

    while(tui.isOpened()) {
        int event;

        switch(tui.getState()){
            case TUI::State::ADD:
                tui.add();
                tui.setState(-1);
                break;
            case TUI::State::SEARCH:
                tui.search();
                tui.setState(-1);
                break;
            case TUI::State::PRINT:
                tui.print();
                tui.setState(-1);
                break;
            case TUI::State::REMOVE:
                tui.remove();
                tui.setState(-1);
                break;
            case TUI::State::EXIT:
                tui.close();
                break;
            default: // TUI::State::IDLE
                cout << "#### Main Page ####\n";
                cout << "[1] Add\t[2] Search\t[3] Print all";
                cout << "\t[4] Remove\t[0] Exit\n";
                cin >> event;
                
                tui.setState(event);
        }
    }

    return 0;
}