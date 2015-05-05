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

class Checker : public Material {
private:
    float scale;
public:
    Checker();
    Checker(float _scale, float _reflectiveness=0);
    virtual ~Checker();
    virtual Color sample(Ray& ray,Vector3d& position,Vector3d& normal);
};

#endif /* defined(__AxelRayTracing__check__) */
