//
//  ray.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "ray.h"

Ray::Ray() {
}

Ray::~Ray() {
}

Ray::Ray(Vector3d o, Vector3d d) {
    origin = o;
    direction = d;
}

void Ray::setOrigin(Vector3d o) {
    origin = o;
}

void Ray::setDirection(Vector3d d) {
    direction = d;
}

Vector3d Ray::getOrigin() {
    return origin;
}

Vector3d Ray::getDirection() {
    return direction;
}

Vector3d Ray::getPoint(double t) {
    return origin+direction*t;
}
