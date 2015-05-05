//
//  plane.h
//  AxelRayTracing
//
//  Created by axel on 15/5/4.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_plane_h
#define AxelRayTracing_plane_h

#include "vector3d.h"
#include "intersectResult.h"
#include "ray.h"
//#include "checkermaterial.h"
#include "myobject.h"

class Plane : public MyObject {
private:
    //法向量
    Vector3d normal;
    //到原点的距离
    float distance;
public:
    Plane();
    Plane(const Vector3d& _normal, float _distance);
    virtual ~Plane();
    virtual IntersectResult isIntersected(Ray& _ray);
};

#endif
