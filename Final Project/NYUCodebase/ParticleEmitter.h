//
//  ParticleEmitter.hpp
//  NYUCodebase
//
//  Created by Cindy Lee on 5/29/18.
//  Copyright © 2018 Ivan Safrin. All rights reserved.
//

#ifndef ParticleEmitter_hpp
#define ParticleEmitter_hpp

#include <stdio.h>
#include <vector>
#include "Vector3.h"
#include "ShaderProgram.h"
#include "Matrix.h"


class Particle {
public:
    Vector3 position = Vector3(0.0, 0.0, 0.0);
    Vector3 velocity = Vector3 (0.0, 0.0f, 0.0);
    float lifetime;
};

class ParticleEmitter {
public:
    
    ParticleEmitter( int textureID, unsigned int particleCount, float x, float y);
    ParticleEmitter();
    ~ParticleEmitter();
    
    void ResetLocations (float x, float y);
    void ResetLife (float maxLife);
    float lerp(float v0, float v1, float t);
    void Update(float elapsed);
    
    void UpdateFireworks (float elapsed);
    
    void Render(ShaderProgram* program);
    Vector3 position;
    Vector3 gravity = Vector3 (0.0, -8.0, 0.0);
    float maxLifetime;
    std::vector <Particle> particles;
    Vector3 velocity = Vector3 (-0.3, -1.0, 0.0);
    Vector3 deviation = Vector3 (0.3, 2.0, 0.0);
    
    int textureID;
    float startSize = 0.15f;
    float endSize = 0.05f;
};

#endif /* ParticleEmitter_hpp */
