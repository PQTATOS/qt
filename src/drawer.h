#ifndef DRAWER_H
#define DRAWER_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QBrush>
#include <QPen>

#include "game_scene.h"

class drawer: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(game_scene* scene MEMBER scene)
public:
    drawer();
    Q_INVOKABLE void requestPaint();
    void paint(QPainter *painter);
    void draw_character(QPainter *painter, const character& charact);
    void draw_field(QPainter *painter);
    void draw_enemies(QPainter *painter);
    void draw_projectiles(QPainter *painter);

    game_scene* scene;
};

#endif // DRAWER_H
