//
//  material.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "material.h"

Material::Material() {}

Material::~Material() {}

Material::Material(float _reflectiveness) {
    reflectiveness =_reflectiveness;
}

float Material::getRef() {
    return reflectiveness;
}

void Material::setRef(float _reflectiveness) {
    reflectiveness = _reflectiveness;
}

Color Material::sample(Ray &ray,
                       Vector3d &position,
                       Vector3d &normal) {
    cout<< "Base Sample" <<endl;
    return Color();
}

