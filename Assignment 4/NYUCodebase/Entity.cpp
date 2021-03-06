//
//  Entity.cpp
//  NYUCodebase
//
//  Created by Cindy Lee on 3/4/18.
//  Copyright © 2018 Ivan Safrin. All rights reserved.
//

#include "Entity.h"
#include "ShaderProgram.h"
#include "SheetSprite.h"

Entity::Entity () {}

// creating an entity
Entity::Entity (int sprites, int index, float x, float y, float z, float size) : position (Vector3 (x,y,z)), sizeEnt (Vector3 (size, size, 0.0f)) {
    sprite = SheetSprite (index, sprites, size ); 
}

// drawing an entity
void Entity::Draw(ShaderProgram *program ) {
        modelMatrix.Identity();
        modelMatrix.Translate (position.x, position.y, position.z);
        program -> SetModelMatrix(modelMatrix);
        sprite.Draw (program);
}

//checking for entity collision
bool Entity::Collision (Entity* other){
    if (!  (position.y - sizeEnt.y/2 > other->position.y + other->sizeEnt.y / 2 ||
           position.y + sizeEnt.y/2 < other->position.y - other->sizeEnt.y/2 ||
           position.x - sizeEnt.x/2 > other->position.x + other->sizeEnt.x/2 ||
           position.x + sizeEnt.x/2 < other->position.x - other->sizeEnt.x/2) ) {
        return true;
    }
    return false;
}


//converting to Tile coordinates
void Entity::worldToTileCoordinates(float worldX, float worldY, int *gridX, int *gridY) {
    *gridX = (int)(worldX / 0.2f);
    *gridY = (int)(-worldY / 0.2f);
}

