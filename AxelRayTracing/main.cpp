//
//  main.cpp
//  AxelRayTracing
//
//  Created by axel on 15/4/29.
//  Copyright (c) 2015年 axel. All rights reserved.
//
#include "render.h"

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

int main(void) {
    //初始化 GLFW
    GLFWwindow* window;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    // 创建一个窗口
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ray Tracing",
                              NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //初始化窗口
    initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    //渲染循环
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        rendering(window);
    }
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
}