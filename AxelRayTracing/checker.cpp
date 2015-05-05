//
//  check.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "checker.h"

Checker::Checker() {}

Checker::~Checker() {}

Checker::Checker(float _scale, float _reflectiveness) {
    scale = _scale;
    reflectiveness = _reflectiveness;
}

Color Checker::sample(Ray &ray, Vector3d &position, Vector3d &normal) {
    float d = abs((floor(position.x * this->scale)
                   + floor(position.z * this->scale)));
    d = fmod(d, 2);
    return d < 1 ? Color::black() : Color::white();
}