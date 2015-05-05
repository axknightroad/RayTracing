//
//  check.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__check__
#define __AxelRayTracing__check__

#include <stdlib.h>
#include "color.h"
#include "material.h"

class Check : public Material {
private:
    float scale;
public:
    Check();
    Check(float _scale, float _reflectiveness=0);
    virtual ~Check();
    virtual Color sample(const Ray& ray,const Vector3d& position,const Vector3d& normal);
};

#endif /* defined(__AxelRayTracing__check__) */
