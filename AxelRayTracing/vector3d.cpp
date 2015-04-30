//
//  vector3d.cpp
//  AxelRayTracing
//
//  Created by axel on 15/4/29.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "vector3d.h"

Vector3d::Vector3d() {
}

Vector3d::~Vector3d() {
}

Vector3d::Vector3d(float pos_x, float pos_y, float pos_z) {
    x = pos_x;
    y = pos_y;
    z = pos_z;
}

Vector3d Vector3d::operator + (Vector3d v) {
    return Vector3d(x + v.x, y + v.y, z + v.z);
}

Vector3d Vector3d::operator - (Vector3d v) {
    return Vector3d(x - v.x, y - v.y, z - v.z);
}

Vector3d Vector3d::operator * (float n) {
    return Vector3d(x * n, y * n, z * n);
}

Vector3d Vector3d::operator / (float n) {
    return Vector3d(x / n, y / n, z / n);
}

void Vector3d::getInfo() {
    cout << "the 3d vector:\nx:" << x
    << " y:" << y << " z:" << z << endl;
}

Vector3d Vector3d::abs() {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (z < 0) z = -z;
    return Vector3d(x, y, z);
}

float Vector3d::dotMul(Vector3d v) {
    return (x*v.x + y*v.y + z*v.z);
}

Vector3d Vector3d::crossMul(Vector3d v) {
    Vector3d v_out;
    v_out.x = ((y * v.z) - (z * v.y));
    v_out.y = ((z * v.x) - (x * v.z));
    v_out.z = ((x * v.y) - (y * v.x));
    return v_out;
}

float Vector3d::getLength() {
    return (float)sqrt(x*x + y*y + z*z);
}

Vector3d Vector3d::normalize() {
    float length = getLength();
    x = x / length;
    y = y / length;
    z = z / length;
    return Vector3d(x, y, z);
}

float Vector3d::max() {
    float tmp = MAX(x, y);
    return MAX(tmp, z);
}

float Vector3d::min() {
    float tmp = MIN(x, y);
    return MIN(tmp, z);
}

float Vector3d::getDist(Vector3d v) {
    float tmp=(x-v.x)*(x-v.x) + (y-v.y)*(y-v.y) + (z-v.z)*(z-v.z);
    return sqrt(tmp);
}

