#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LinkedList.h"
#include "Ally.h"

using namespace std;

void introduction() {
    cout << "Welcome to the Castle Adventure!\n";
    cout << "You will navigate through various rooms in the castle.\n\n";
}

void showAlly(const Ally& ally) {
    ally.display();
}


void levelUpAlly(Ally& ally) {
    ally.levelUp();
}

int main() {
    LinkedList castleRooms;
    ifstream file("rooms.csv");
    string line;

    // Load rooms
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, description, actionsStr, item;
            vector<string> actions;

            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, actionsStr, ',');
            getline(ss, item);

            stringstream actionStream(actionsStr);
            string action;
            while (getline(actionStream, action, ';')) {
                actions.push_back(action);
            }

            Room newRoom(name, description, actions, item);
            castleRooms.addRoom(newRoom);
        }
        file.close();
    } else {
        cout << "Unable to open file\n";
        return 1;
    }

    introduction();

    //ally
    Ally ally("Knight", "Warrior", 1);

    cout << "\nYou meet an ally!\n";
    showAlly(ally);

    cout << "\nYour ally helps you...\n";
    levelUpAlly(ally);

    auto current = castleRooms.getHead();

    // MAIN LOOP
    while (current != nullptr) {

        cout << "\n====================================\n";
        cout << "        CURRENT ROOM\n";
        cout << "====================================\n";

        cout << current->room.toString() << endl;
        cout << current->food.toString() << endl;

        vector<string> actions = current->room.getActions();

        cout << "\nActions:\n";
        for (int i = 0; i < actions.size(); i++) {
            cout << i + 1 << ". " << actions[i] << endl;
        }

        cout << "4. Exit game\n";

        cout << "\n------------------------------------\n";
        cout << "Choose an action (1-4): ";

        int choice;
        cin >> choice;

        // exit
        if (choice == 4) {
            cout << "\nExiting game... Goodbye!\n";
            break;
        }

        // VALIDATION
        if (choice < 1 || choice > actions.size()) {
            cout << "\nInvalid choice. Try again.\n";
            continue;
        }

        cout << "\n👉 You chose: " << actions[choice - 1] << endl;

        //NEXT ROOM
        if (actions[choice - 1] == "Leave the room") {
            current = current->next;
        }

        cout << "\n------------------------------------\n";
    }

    cout << "\nEnd of adventure!\n";
    return 0;
}