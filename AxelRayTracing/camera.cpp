//
//  camera.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "camera.h"


Camera::Camera() {}

Camera::~Camera() {}

Camera::Camera(const Vector3d& _eye,
               const Vector3d& _front,
               const Vector3d& _ref_up,
               const float _fov) {
    eye = _eye;
    front = _front;
    ref_up = _ref_up;
    fov = _fov;
    right = front.crossMul(ref_up);
    up = right.crossMul(front);
    fov_scale = tan(fov * (PI * 0.5f / 180)) / 2;
    
}

Ray Camera::generateRay(float x, float y) {
    Vector3d r = right * ((x - 0.5f) * fov_scale);
    Vector3d u = up * ((y - 0.5f) * fov_scale);
    Vector3d tmp = front + r + u;
    tmp.normalize();
    return Ray(eye,tmp);
}