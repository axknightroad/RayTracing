//
//  material.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__material__
#define __AxelRayTracing__material__

#include "vector3d.h"
#include "color.h"
#include "intersectResult.h"
#include "ray.h"

class Material {
protected:
    float reflectiveness;
public:
    Material();
    Material(float _reflectiveness);
    virtual ~Material();
    float getRef();
    void setRef(float _reflectiveness);
    virtual Color sample(const Ray& ray,
                         const Vector3d& position,
                         const Vector3d& normal);
};

#endif /* defined(__AxelRayTracing__material__) */
