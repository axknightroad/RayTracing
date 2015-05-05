//
//  plane.h
//  AxelRayTracing
//
//  Created by axel on 15/5/4.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_plane_h
#define AxelRayTracing_plane_h

#include "myobject.h"

//地板类
class Plane : public MyObject {
 public:
    Plane();
    Plane(const Vector3d& _normal, float _distance);
    virtual ~Plane();

    virtual IntersectResult isIntersected(Ray& _ray);

 private:
    //法向量
    Vector3d normal;
    //到原点的距离
    float distance;
};

#endif
