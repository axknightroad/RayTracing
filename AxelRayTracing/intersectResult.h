//
//  intersectResult.h
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_intersectResult_h
#define AxelRayTracing_intersectResult_h

#include "vector3d.h"
//#include "myobject.h"
class MyObject;
//表示物体和光线相交结果
struct IntersectResult {
    float distance;
    bool is_hit;
    MyObject* object;
    Vector3d position;
    Vector3d normal;
    static inline IntersectResult noHit() {
        return IntersectResult();
    }
};

#endif
