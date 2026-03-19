#include "Ally.h"
#include <iostream>

Ally::Ally(string name, string type, int level)
    : name(name), type(type), level(level) {}

void Ally::display() const {
    cout << "Ally: " << name << " | Type: " << type << " | Level: " << level << endl;
}

void Ally::levelUp() {
    level++;
    cout << name << " leveled up to " << level << "!\n";
}