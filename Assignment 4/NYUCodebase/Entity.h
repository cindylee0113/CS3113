//
//  Entity.hpp
//  NYUCodebase
//
//  Created by Cindy Lee on 3/4/18.
//  Copyright © 2018 Ivan Safrin. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "SheetSprite.h"
#include "ShaderProgram.h"
#include "Vector3.h"
class Entity {
public:
    Entity ();
    Entity (int sprites, int index, float x, float y, float z, float size);
    void Draw(ShaderProgram* program);
    void Update(float elapsed);
    bool Collision (Entity* other);
    void worldToTileCoordinates(float worldX, float worldY, int *gridX, int *gridY);
    
    Vector3 position = Vector3 (0.0f, 0.0f, 0.0f);
    Vector3 velocity = Vector3 (0.0f, 0.0f, 0.0f);
    Vector3 acceleration = Vector3 (0.0f, 0.0f, 0.0f);
    Vector3 sizeEnt = Vector3 (0.0f, 0.0f, 0.0f);
    Vector3 gravity = Vector3 (0.0f, 0.0f, 0.0f);
    
    float rotation;
    SheetSprite sprite;
    bool collidedTop = false;
    bool collidedBottom = false;
    bool collidedLeft = false;
    bool collidedRight = false;
    Matrix modelMatrix;
};



#endif /* Entity_hpp */
