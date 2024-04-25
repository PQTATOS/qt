#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <cmath>
#include <vector>
#include <unordered_set>

#include <QObject>
#include <QPointF>

#include "character.h"

class game_scene : public QObject
{
    Q_OBJECT

signals:
    void playerDied();
public:
    game_scene();

    Q_INVOKABLE void recive_joystick_input(QPointF input = QPointF());
    Q_INVOKABLE void update();

    const character& get_player();
    std::unordered_set<game_object*>& get_enemies();
    std::unordered_set<game_object*>& get_projectiles();
private:
    int ticks;
    character player;    
    std::unordered_set<game_object*>** field;
    std::unordered_set<game_object*> enemies;
    std::unordered_set<game_object*> projectiles;
    bool pojectile_collisions(QPoint& int_coords, const QPointF& coords);

    void spawn_enemies();
    void update_enemies();

    void spawn_projectiles();
    void update_projectiles();
};

#endif // GAME_SCENE_H
