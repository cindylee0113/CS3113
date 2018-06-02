//
//  GameState.hpp
//  NYUCodebase
//
//  Created by Cindy Lee on 3/6/18.
//  Copyright © 2018 Ivan Safrin. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <vector>
#include <stdio.h>
#include "Entity.h"
#include "SheetSprite.h"
#include "FlareMap.h"
#include "ShaderProgram.h"
#include "ParticleEmitter.h"

class GameState {
public:
    GameState ();
    void Initiate (int spriteTiles, int spritesterPlayer, int spritesterEnemy, int textureID);
    void LoadLevel ();
    void UpdateEnemyMovement (float elapsed);
    void UpdateLevel ();
    void Update ();
    int GetLevel ();
    int GetLives ();
    void Draw (ShaderProgram* program);
    void CollisionEntities ();
    void CollisionX ();
    void CollisionY ();
    void Reset ();
    float lerp(float v0, float v1, float t);
    
    Entity player;
    Entity key;
    Entity powerUp; 
    std::vector <Entity> enemies;
    std::vector <Entity> platforms;
    FlareMap* mappy;
    bool keyObtained = false;
    bool powerUpObtained = false;
    ParticleEmitter partSystem;
    int partTexture;
    bool nextLevel = false;
    
private:
    int sprites = 0;
    int spritePlayer = 0;
    int spriteEnemy = 0;
    int level = 0;
    int lives = 5;
    std::vector <int> solidTiles = {0, 1, 2, 3, 5, 6, 7, 132, 133, 134, 135, 198, 199, 200, 201, 202, 203, 204, 205, 227, 228};
};


#endif /* GameState_hpp */
