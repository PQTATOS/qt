#include "joystick.h"

#include <QDebug>

joystick::joystick()
{
    center_x = 0;
    center_y = 0;
    last_x = 0;
    last_y = 0;
    isActive = false;
}

void joystick::requestPaint()
{
    update();
}

void joystick::paint(QPainter *painter)
{
    if (!isActive) return;
    painter->setBrush(
                QBrush(QColor(255,0,0,128),
                Qt::SolidPattern)
                );
    painter->drawEllipse(center_x-100, center_y-100, max_length,max_length);

    painter->setBrush(
                QBrush(QColor(26,0,0,255),
                Qt::SolidPattern)
                );
    painter->drawEllipse(last_x-25, last_y-25, 50,50);
}

void joystick::activate(bool state, int x, int y)
{
    isActive = state;
    if (state)
    {
        center_x = x;
        center_y = y;
        last_x = x;
        last_y = y;
    }
}

void joystick::changePosition(int x, int y)
{
    int tmp_x = x - center_x;
    int tmp_y = y - center_y;
    float len = std::sqrt(tmp_x*tmp_x+tmp_y*tmp_y);

    if (len > max_length/2)
    {
        last_x = center_x+(tmp_x/len)*max_length/2;
        last_y = center_y+(tmp_y/len)*max_length/2;
        return;
    }
    last_x = x;
    last_y = y;
}

QPointF joystick::input()
{
    return QPointF(last_x-center_x, last_y-center_y);
}
