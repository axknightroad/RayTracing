//
//  phong.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "phong.h"

Phong::Phong() {}

Phong::~Phong() {}

Phong::Phong(const Color& _diffuse,
             const Color& _specular,
             const float& _shininess,
             float _reflectiveness) {
    diffuse = _diffuse;
    specular = _specular;
    shininess = _shininess;
    reflectiveness = _reflectiveness;
}

Color Phong::sample(const Ray &ray, const Vector3d &position, const Vector3d &normal) {
    Vector3d n = normal;
    float n_dot_l = n.dotMul(light_dir);
    
}