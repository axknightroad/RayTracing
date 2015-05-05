//
//  sphere.h
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_sphere_h
#define AxelRayTracing_sphere_h

#include "myobject.h"

//空间球体类
class Sphere : public MyObject {
 public:
    Sphere();
    Sphere(Vector3d c, double r);
    virtual ~Sphere();
    Sphere(Sphere& s);
 
    void setCenter(Vector3d& c);
    void setRadius(double r);
    Vector3d getCenter();
    double getRadius();
    //获取物体表面一点的法线
    virtual Vector3d getNormal(Vector3d p);
    //用于判断光线和该物体的交点
    virtual IntersectResult isIntersected(Ray& _ray);
    
 private:
    Vector3d center;
    double radius;
    
};

#endif
