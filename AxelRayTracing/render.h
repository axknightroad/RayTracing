//
//  render.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__render__
#define __AxelRayTracing__render__

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>
//#include "ray.h"
#include "camera.h"
//#include "vector3d.h"
#include "sphere.h"
//#include "material.h"
//#include "color.h"
//#include "myobject.h"
#include "plane.h"
#include "phong.h"
#include "checker.h"

void initScene(int w,int h);

void drawScene(GLFWwindow* window);

void resizeGL(GLFWwindow* window, int width, int height);

void renderDepth0(GLFWwindow* window);

void renderDepth1(GLFWwindow* window);

void renderDepth2(GLFWwindow* window);

#endif /* defined(__AxelRayTracing__render__) */
