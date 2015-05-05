//
//  render.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//
//  定义了渲染用的函数

#ifndef __AxelRayTracing__render__
#define __AxelRayTracing__render__

#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
#include "camera.h"
#include "sphere.h"
#include "plane.h"
#include "phong.h"
#include "checker.h"
#include "union.h"

//初始化窗口
void initWindow(int w,int h);

//构造光线追踪反射函数
Color rayTraceRecursive(MyObject* scene, Ray& ray,long max_reflect);

//渲染函数
void rendering(GLFWwindow* window);

#endif /* defined(__AxelRayTracing__render__) */
