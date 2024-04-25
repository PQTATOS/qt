#ifndef CHARACTER_H
#define CHARACTER_H

#include "game_object.h"
#include <QColor>

class character: public game_object
{
public:
    character(game_types type);
    QColor clr;
private:
    int health;
};

#endif // CHARACTER_H
