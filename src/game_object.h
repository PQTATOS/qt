#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <cmath>

#include <QPointF>

enum class game_types
{
    player,
    enemy,
    projectile
};

class game_object
{
public:
    game_object(game_types type);

    game_types&  get_type() { return type; };

    const QPointF& get_coordinates() const;
    QPoint copy_int_coordinates() const;
    void set_coordinates(float x, float y);
    void add_coordinates(QPointF ponit);

    const QPointF& get_direction() const;
    void change_direction(float x, float y);

    float get_velocity() const;
    void change_velocity(float change);

    void move();
    void move_to(const QPointF& to_point);
protected:
    QPointF coordinates;
    QPointF direction;
    float velocity;

    game_types type;
};

#endif // GAME_OBJECT_H
