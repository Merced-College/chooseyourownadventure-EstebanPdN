#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>
using namespace std;

class Food {
private:
    string name;
    string type;
    int calories;
    string description;
    vector<string> actions;

public:
    Food(string name, string type, int calories, string description, vector<string> actions);

    string getName() const;
    string toString() const;
};

#endif