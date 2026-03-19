#include "LinkedList.h"

Node::Node(Room room, Food food) : room(room), food(food), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::addRoom(const Room& room) {
    // Temporary Food (simple integration for assignment)
    vector<string> actions = {"Eat", "Ignore"};
    Food food("Apple", "Fruit", 50, "A red apple", actions);

    shared_ptr<Node> newNode = make_shared<Node>(room, food);

    if (!head) {
        head = newNode;
        return;
    }

    auto temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::displayRooms() {
    auto temp = head;
    while (temp) {
        cout << temp->room.toString() << endl;
        cout << temp->food.toString() << endl;
        cout << "----------------------\n";
        temp = temp->next;
    }
}

shared_ptr<Node> LinkedList::getHead() const {
    return head;
}