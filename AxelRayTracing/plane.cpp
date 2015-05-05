//
//  plane.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "plane.h"

Plane::Plane() {}

Plane::~Plane() {}

Plane::Plane(const Vector3d& _normal, float _distance) {
    normal = _normal;
    distance =_distance;
}

IntersectResult Plane::isIntersected(Ray& _ray) {
    IntersectResult result = IntersectResult::noHit();
    float a = _ray.getDirection().dotMul(this->normal);
    if (a < 0) {
        result.is_hit = 1;
        result.object = this;
        float b = this->normal.dotMul(_ray.getOrigin() - normal*distance);
        result.distance = -b / a;
        result.position = _ray.getPoint(result.distance);
        result.normal = this->normal;
        
    }
    return result;
}