#ifndef ALLY_H
#define ALLY_H

#include <string>
#include <vector>
using namespace std;

class Ally {
private:
    string name;
    string type;
    int level;

public:
    Ally(string name, string type, int level);

    void display() const;
    void levelUp();
};

#endif