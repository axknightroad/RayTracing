//
//  phong.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__phong__
#define __AxelRayTracing__phong__

#include "vector3d.h"
#include "color.h"
#include "ray.h"
#include "material.h"

static Vector3d light_dir = Vector3d(1, 1, 1).normalize();
static Color light_color = Color::white();

class Phong : public Material {
private:
    Color   diffuse;
    Color   specular;
    float   shininess;
    
public:
    Phong();
    Phong(const Color& _diffuse,
          const Color& _specular,
          const float& _shininess,
          float _reflectiveness=0);
    virtual ~Phong();
    virtual Color sample(const Ray& ray,
                         const Vector3d& position,
                         const Vector3d& normal);
};


#endif /* defined(__AxelRayTracing__phong__) */
