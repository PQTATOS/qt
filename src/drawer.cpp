#include "drawer.h"

drawer::drawer()
{

}

void drawer::requestPaint()
{
    update();
}

void drawer::paint(QPainter *painter)
{
    draw_field(painter);
    draw_enemies(painter);
    draw_projectiles(painter);
    draw_character(painter, scene->get_player());
}

void drawer::draw_character(QPainter *painter, const character& charact)
{
    painter->setBrush(
                QBrush(charact.clr,
                Qt::SolidPattern)
                );

    QPointF coord = charact.get_coordinates();
    painter->drawEllipse(coord.x()-15, coord.y()-15, 30,30);

    QPointF dir = charact.get_direction()*charact.get_velocity();
    painter->drawLine(coord.x(), coord.y(),
                      coord.x() + dir.x(), coord.y()+dir.y());
}

void drawer::draw_enemies(QPainter *painter)
{
    for (auto var : scene->get_enemies())
    {
        draw_character(painter, *(character*)var);
    }
}

void drawer::draw_projectiles(QPainter *painter)
{
    QPen prev = painter->pen();
    QPen newPen = QPen();
    newPen.setWidth(10);
    painter->setPen(newPen);
    for (auto var : scene->get_projectiles())
    {
        painter->drawPoint(var->get_coordinates());
    }

    painter->setPen(prev);
}

void drawer::draw_field(QPainter *painter)
{
    QImage img("://images/map.png");
    QRect target(0,0,720,1280);

    painter->drawImage(target, img);
}
