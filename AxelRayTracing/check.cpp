//
//  check.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "check.h"

Check::Check() {}

Check::~Check() {}

Check::Check(float _scale, float _reflectiveness) {
    scale = _scale;
    reflectiveness = _reflectiveness;
}

Color Check::sample(const Ray &ray, const Vector3d &position, const Vector3d &normal) {
    float d = abs((floor(position.x * this->scale) + floor(position.z * this->scale)));
    d = fmod(d, 2);
    return d < 1 ? Color::black() : Color::white();
}