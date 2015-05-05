//
//  phong.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__phong__
#define __AxelRayTracing__phong__

#include "material.h"

static Vector3d light_dir = Vector3d(1, 1, 1).normalize();
static Color light_color = Color::white();

//phong类材质
class Phong : public Material {
 public:
    Phong();
    Phong(const Color& _diffuse,
          const Color& _specular,
          const float& _shininess,
          float _reflectiveness=0);
    virtual ~Phong();
    
    virtual Color sample(Ray& ray, Vector3d& position, Vector3d& normal);
    
 private:
    Color   diffuse;
    Color   specular;
    float   shininess;
};


#endif /* defined(__AxelRayTracing__phong__) */
