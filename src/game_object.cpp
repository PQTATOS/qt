#include "game_object.h"

game_object::game_object(game_types type)
{
    this->type = type;
    coordinates = QPointF(0,0);
    direction = QPointF(0,1);
    velocity = 0;
}

const QPointF& game_object::get_coordinates() const
{
    return coordinates;
}
void game_object::set_coordinates(float x, float y)
{
    coordinates.setX(x);
    coordinates.setY(y);
}
void game_object::add_coordinates(QPointF newc)
{
    coordinates.setX(coordinates.x()+newc.x());
    coordinates.setY(coordinates.y()+newc.y());
}

const QPointF& game_object::get_direction() const
{
    return direction;
}
void game_object::change_direction(float x, float y)
{
    direction.setX(x);
    direction.setY(y);
}

float game_object::get_velocity() const
{
    return velocity;
}
void game_object::change_velocity(float change)
{
    velocity = change;
}

void game_object::move()
{
    QPointF move = direction*velocity*0.1;
    QPointF test = coordinates+move;
    if (type == game_types::player)
    {
        if (test.x() < 0 || test.x() > 720)
            move.setX(0);
        if (test.y() < 0 || test.y() > 1280)
            move.setY(0);
    }

    add_coordinates(move);
}

void game_object::move_to(const QPointF &to_point)
{
    QPointF dif(to_point.x()-coordinates.x(), to_point.y()-coordinates.y());
    float len = std::sqrt(dif.x()*dif.x() + dif.y()*dif.y());
    direction.setX(dif.x()/len);
    direction.setY(dif.y()/len);

    move();
}

QPoint game_object::copy_int_coordinates() const
{
    return QPoint(coordinates.x(), coordinates.y());
}
