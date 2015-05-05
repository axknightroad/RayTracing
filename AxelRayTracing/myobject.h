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

//空间三维物体类
class MyObject {
 public:
    Material* material;
    MyObject();
    virtual ~MyObject();
    
    virtual IntersectResult isIntersected(Ray& _ray)=0;
};

#endif
