//
//  myobject.h
//  AxelRayTracing
//
//  Created by axel on 15/5/4.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_myobject_h
#define AxelRayTracing_myobject_h

#include "material.h"
#include "intersectResult.h"
#include "ray.h"

class MyObject {
public:
    Material* material;
    MyObject();
    virtual IntersectResult isIntersected(Ray& _ray)=0;
    virtual ~MyObject();
};

#endif
