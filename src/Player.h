// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Global.h"

typedef struct {
    Entity base;
    float width;
    float height;
    int lives;
} Player;

#endif // PLAYER_H
