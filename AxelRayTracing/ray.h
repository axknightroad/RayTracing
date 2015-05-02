//
//  ray.h
//  AxelRayTracing
//
//  Created by axel on 15/4/30.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_ray_h
#define AxelRayTracing_ray_h

#include <iostream>
#include "vector3d.h"

#define PI 3.14159

using namespace std;

class Ray {

private:
    Vector3d origin;
    Vector3d direction;
public:
    Ray();
    Ray(Vector3d o,Vector3d d);
    ~Ray();
    void setOrigin(Vector3d o);
    void setDirection(Vector3d d);
    Vector3d getOrigin();
    Vector3d getDirection();
    //通过向射线的参数方程传入参数t而获得在射线上的点
    Vector3d getPoint(double t);
    
};

#endif
