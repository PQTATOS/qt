#include "character.h"

character::character(game_types type): game_object(type)
{
    switch (type) {
    case game_types::player:
        health = 5;
        clr = QColor(64,50,255,255);
        break;
    case game_types::enemy:
        health = 1;
        velocity = 50;
        clr = QColor(128,50,0,255);
        break;
    }
}
