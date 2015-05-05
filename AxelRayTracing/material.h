//
//  material.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__material__
#define __AxelRayTracing__material__

#include "color.h"
#include "intersectResult.h"
#include "ray.h"

//材质类
class Material {
 public:
    Material();
    Material(float _reflectiveness);
    virtual ~Material();
    
    float getRef();
    void setRef(float _reflectiveness);
    virtual Color sample(Ray& ray, Vector3d& position, Vector3d& normal);
    
 protected:
    float reflectiveness;
};

#endif /* defined(__AxelRayTracing__material__) */
