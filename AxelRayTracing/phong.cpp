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

Color Phong::sample(Ray &ray, Vector3d &position, Vector3d &normal) {
    float n_dot_l = normal.dotMul(light_dir);
    Vector3d h = (light_dir -ray.getDirection()).normalize();
    float n_dot_h = normal.dotMul(h);
    Color diffuse_term = this->diffuse.multiply(std::max(n_dot_l, (float)0));
    Color specular_term = this->specular.multiply(pow(std::max(n_dot_h, (float)0), this->shininess));
    return light_color.modulate(diffuse_term.add(specular_term));
}