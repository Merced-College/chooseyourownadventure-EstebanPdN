#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include <iostream>
#include "Room.h"
#include "Food.h"
using namespace std;

class Node {
public:
    Room room;
    Food food;
    shared_ptr<Node> next;

    Node(Room room, Food food);
};

class LinkedList {
private:
    shared_ptr<Node> head;

public:
    LinkedList();
    void addRoom(const Room& room);
    void displayRooms();
    shared_ptr<Node> getHead() const;
};

#endif