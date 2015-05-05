//
//  main.cpp
//  AxelRayTracing
//
//  Created by axel on 15/4/29.
//  Copyright (c) 2015年 axel. All rights reserved.
//
/*
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>
#include "ray.h"
#include "camera.h"
#include "vector3d.h"
#include "sphere.h"
 */
#include "render.h"

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

int main(void) {
    //初始化 GLFW
    GLFWwindow* window;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    // 创建一个窗口
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //初始化窗口
    initScene(WINDOW_WIDTH, WINDOW_HEIGHT);
    //设置窗口大小发生变化时的回调函数
    //glfwSetWindowSizeCallback(window, resizeGL);
    //主循环
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        //drawScene(window);
        renderDepth2(window);
    }
    glfwTerminate();
    exit( EXIT_SUCCESS );
}