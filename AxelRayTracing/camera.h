//
//  camera.h
//  AxelRayTracing
//
//  Created by axel on 15/5/2.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_camera_h
#define AxelRayTracing_camera_h

#include <math.h>
#include "ray.h"

//摄像机/眼睛类
class Camera {
 public:
    Camera();
    ~Camera();
    Camera(const Vector3d& _eye,
           const Vector3d& _front,
           const Vector3d& _ref_up,
           const float _fov);
    
    Ray generateRay(float x, float y);
    
 private:
    Vector3d eye;
    Vector3d front;
    Vector3d ref_up;
    float fov;
    Vector3d right;
    Vector3d up;
    float fov_scale;
};

#endif
