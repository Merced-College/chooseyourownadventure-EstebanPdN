#include "Food.h"

Food::Food(string name, string type, int calories, string description, vector<string> actions)
    : name(name), type(type), calories(calories), description(description), actions(actions) {}

string Food::getName() const {
    return name;
}

string Food::toString() const {
    return "Food: " + name + " (" + type + ")";
}