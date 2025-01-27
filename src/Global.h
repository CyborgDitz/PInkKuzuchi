#ifndef GLOBAL_H
#define GLOBAL_H

#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define TILE_WIDTH 80
#define TILE_HEIGHT 40
#define BLOCK_SIZE TILE_WIDTH


typedef struct {
    Vector2 position;
    Vector2 velocity;
    bool isActive;
} Entity;

extern GameState currentGameState;

#endif // GLOBAL_H
