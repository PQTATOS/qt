#include "game_scene.h"

#include <QDebug>

game_scene::game_scene(): player(game_types::player)
{
    player.set_coordinates(200,500);
    ticks = 0;
    field = new std::unordered_set<game_object*>*[18];
    for (int i = 0; i < 18; ++i)
        field[i] = new std::unordered_set<game_object*>[11];
}

void game_scene::recive_joystick_input(QPointF input)
{
    float len = std::sqrt(input.x()*input.x() + input.y()*input.y());
    player.change_velocity(len);
    if (len != 0)
        player.change_direction(input.x()/len, input.y()/len);
}

const character& game_scene::get_player()
{
    return player;
}

std::unordered_set<game_object*>& game_scene::get_enemies()
{
    return enemies;
}

void game_scene::update()
{
    ++ticks;
    if (ticks > 100)
        ticks = 0;

    update_projectiles();
    update_enemies();
    player.move();
    spawn_enemies();
    spawn_projectiles();
}

void game_scene::spawn_enemies()
{
    if (ticks != 100) return;
    character* enemy = new character(game_types::enemy);
    enemy->set_coordinates(-1,-1);
    field[1][1].insert(enemy);
    enemies.insert(enemy);
}

void game_scene::update_enemies()
{
    for (auto x : enemies)
    {
        QPoint prev_coord = x->copy_int_coordinates()/80;

        x->move_to(player.get_coordinates());
        QPointF tmp = x->get_coordinates()-player.get_coordinates();
        float len = std::sqrt(tmp.x()*tmp.x() + tmp.y()*tmp.y());
        if (len < 15)
        {
            emit playerDied();
            break;
        }
        QPoint coord = x->copy_int_coordinates()/80;
        if (prev_coord != coord)
        {
            field[coord.y()+1][coord.x()+1].insert(x);
            field[prev_coord.y()+1][prev_coord.x()+1].erase(x);
        }
    }
}

void game_scene::spawn_projectiles()
{
    if (ticks % 20 != 0) return;
    game_object* project = new game_object(game_types::projectile);
    QPointF ply = player.get_coordinates();
    project->set_coordinates(ply.x(),ply.y());

    project->change_direction(player.get_direction().x(), player.get_direction().y());
    project->change_velocity(200);

    field[int(ply.y()/80)][int(ply.x()/80)].insert(project);
    projectiles.insert(project);
}

std::unordered_set<game_object*>& game_scene::get_projectiles()
{
    return projectiles;
}

void game_scene::update_projectiles()
{
    std::vector<game_object*> to_delete;

    for (auto x : projectiles)
    {
        QPoint prev_coord = x->copy_int_coordinates()/80;
        x->move();
        QPoint coord = x->copy_int_coordinates()/80;

        qDebug() << coord;
        if (coord.y() < -1 || coord.y() > 16
                || coord.x() < -1 || coord.x() > 9
                || pojectile_collisions(coord, x->get_coordinates()))
        {
            field[prev_coord.y()+1][prev_coord.x()+1].erase(x);
            to_delete.push_back(x);
            continue;
        }
        if (prev_coord != coord)
        {
            field[coord.y()+1][coord.x()+1].insert(x);
            field[prev_coord.y()+1][prev_coord.x()+1].erase(x);
        }
    }

    for (auto p : to_delete)
    {
        projectiles.erase(p);
        delete p;
    }
}

bool game_scene::pojectile_collisions(QPoint& int_coords, const QPointF& coords)
{
    game_object* to_delete = nullptr;
    for (auto enemy: field[int_coords.y()+1][int_coords.x()+1])
    {
        if (enemy->get_type() != game_types::enemy)
            continue;
        QPointF tmp = enemy->get_coordinates()-coords;
        float len = std::sqrt(tmp.x()*tmp.x() + tmp.y()*tmp.y());
        if (len < 15)
        {
            to_delete=enemy;
            break;
        }
    }

    if (to_delete != nullptr)
    {
        field[int_coords.y()+1][int_coords.x()+1].erase(to_delete);
        enemies.erase(to_delete);
        delete to_delete;
        return true;
    }
    return false;
}
