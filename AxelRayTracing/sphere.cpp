//
//  sphere.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "sphere.h"
#include "intersectResult.h"


Sphere::Sphere() {}

Sphere::Sphere(Vector3d c, double r) {
    center = c;
    radius = r;
}

Sphere::~Sphere() {}

Sphere::Sphere(Sphere& s) {
    center = s.getCenter();
    radius = s.getRadius();
}

void Sphere::setCenter(Vector3d &c) {
    center = c;
}

void Sphere::setRadius(double r) {
    radius = r;
}

Vector3d Sphere::getCenter() {
    return center;
}

double Sphere::getRadius() {
    return radius;
}

Vector3d Sphere::getNormal(Vector3d p) {
    return p - center;
}

IntersectResult Sphere::isIntersected(Ray& _ray) {
    IntersectResult result = IntersectResult::noHit();
    Vector3d v = _ray.getOrigin() -center;
    float a = v.dotMul(v) - radius*radius;
    float d_dot_v = _ray.getDirection().dotMul(v);
    
    if (d_dot_v <= 0) {
        float discr = d_dot_v*d_dot_v - a;
        if (discr >= 0) {
            result.is_hit = 1;
            result.object = this;
            result.distance = -d_dot_v - sqrt(discr);
            result.position = _ray.getPoint(result.distance);
            result.normal = result.position - center;
            result.normal.normalize();
        }
    }
    return result;
}