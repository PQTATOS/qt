#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <cmath>

#include <QQuickPaintedItem>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPointF>

class joystick : public QQuickPaintedItem
{
    Q_OBJECT
public:
    joystick();

    Q_INVOKABLE void requestPaint();
    void paint(QPainter *painter);

    Q_INVOKABLE void changePosition(int x, int y);
    Q_INVOKABLE void activate(bool stat, int x, int y);

    Q_INVOKABLE QPointF input();

private:
    int center_x;
    int center_y;
    int last_x;
    int last_y;

    float max_length = 200;

    bool isActive;
};

#endif // JOYSTICK_H
