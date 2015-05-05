//
//  render.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "render.h"

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

//初始化
void initScene(int w,int h) {
    // 启用阴影平滑
    glShadeModel(GL_SMOOTH);
    // 黑色背景
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // 设置深度缓存
    glClearDepth(1.0);
    // 启用深度测试
    glEnable(GL_DEPTH_TEST);
    // 所作深度测试的类型
    glDepthFunc(GL_LEQUAL);
    // 告诉系统对透视进行修正
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
//绘图
void drawScene(GLFWwindow* window) {
    float color_span = 0.0005f;
    float color = 0.0f;
    float pixel_size = 2.0f;
    float pos_y = -1.0f;
    float pos_x = -1.0f;
    long max_depth = 20;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //将原点移动到左下角
    glTranslatef(-0.5f, -0.5f, -1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    double dx = 1.0f / WINDOW_WIDTH;
    double dy = 1.0f / WINDOW_HEIGHT;
    float dD = 255.0f / max_depth;
    glBegin(GL_POINTS);
    
    for (long y = 0; y < WINDOW_HEIGHT; ++y) {
        double sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x) {
            double sx = dx*x;
            float colorR = x*1.0 / WINDOW_WIDTH*255;
            float colorB = y*1.0 / WINDOW_HEIGHT*255;
            glColor3ub(colorR, 0, colorB);
            glVertex2f(sx, sy);
        }
    }
    
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}
//重置窗口大小后的回调函数
void resizeGL(GLFWwindow* window, int width, int height) {
    // 防止窗口大小变为0
    if (height == 0) {
        height = 1;
    }
    // 重置当前的视口
    glViewport(0, 0, (GLint)width, (GLint)height);
    // 选择投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 重置投影矩阵
    glLoadIdentity();
    // 设置视口的大小
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
    // 选择模型观察矩阵
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//渲染一个灰色球
void renderDepth0(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(-0.5f, -0.5f, -1.0f);
    glPointSize(2.0);
    float horiz = 0.0;
    float dep = 10;
    Camera camera0(Vector3d(horiz, 3, dep), Vector3d(0, 0, -1), Vector3d(0, 1, 0), 90);
    long max_depth = 18;
    Sphere* sphere1 = new Sphere(Vector3d(0, 3, -3), 3.0);
    float dx = 1.0f / WINDOW_WIDTH;
    float dy = 1.0f / WINDOW_HEIGHT;
    float dD = 255.0f / max_depth;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y) {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x) {
            float sx = dx*x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = sphere1 -> isIntersected(ray);
            if (result.is_hit) {
                double t = MIN(result.distance*dD, 255.0f);
                int depth = (int)(255 -t);
                glColor3ub(depth, depth, depth);
                glVertex2f(sx,sy);
            }
        }
    }
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}
//渲染一个有彩色球
void renderDepth1(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(-0.5f,-0.5f,-1.0f);
    glPointSize(2.0);
    Camera camera0( Vector3d(0, 3, 10),Vector3d(0, 0, -1),Vector3d(0, 1, 0), 90);
    long maxDepth=20;
    Sphere* sphere1 = new Sphere(Vector3d(0, 3, -3), 3.0);
    float dx=1.0f/WINDOW_WIDTH;
    float dy=1.0f/WINDOW_HEIGHT;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y)
    {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x)
        {
            float sx =dx*x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = sphere1->isIntersected(ray);
            if (result.is_hit)
            {
                //double t=MIN(result.distance*dD,255.0f);
                //int depth = (int)(255 -t);
                //xuanranshengdu
                //glColor3ub(depth,depth,depth);
                //xuanran normal
                glColor3ub(128*(result.normal.x+1),128*(result.normal.y+1),128*(result.normal.z+1));
                glVertex2f(sx,sy);
            }
        }
    }
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderDepth2(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(-0.5f,-0.5f,-1.0f);
    glPointSize(2.0);
    Camera camera0(Vector3d(0, 10, 10),Vector3d(0, -0.5, -1),Vector3d(0, 1, 0), 90);
    Plane plane1(Vector3d(0, 1, 0),1.0);
    Sphere sphere1(Vector3d(0, 1, -10), 3.0);
    plane1.material=new Checker(0.7f);
    sphere1.material=new Phong(Color::red(), Color::white(), 16);
    long max_depth=20;
    
    float dx=1.0f/WINDOW_WIDTH;
    float dy=1.0f/WINDOW_HEIGHT;
    float dD=255.0f/max_depth;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y)
    {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x)
        {
            float sx =dx*x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = sphere1.isIntersected(ray);
            //IntersectResult result = plane1.isIntersected(ray);
            if (result.is_hit)
            {
                Color color = sphere1.material->sample(ray, result.position, result.normal);
              //  Color color =plane1.material->sample(ray, result.position, result.normal);
                color.saturate();
            //    color.getInfo();
                glColor3ub(color.r*255,color.g*255,color.b*255);
                glVertex2f(sx,sy);
            }
        }
    }
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderUnion(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(-0.5f,-0.5f,-1.0f);
    glPointSize(2.0);
    Camera camera0(Vector3d(0, 10, 10),Vector3d(0, -0.5, -1),Vector3d(0, 1, 0), 90);
    Plane* plane1=new Plane(Vector3d(0, 1, 0),1.0);
    Sphere* sphere1=new Sphere(Vector3d(-2, 3, -10), 2.0);
    Sphere* sphere2=new Sphere(Vector3d(2, 2, -7), 1.0);
    plane1->material=new Checker(0.7f);
    sphere1->material=new Phong(Color::red(), Color::white(), 16);
    sphere2->material=new Phong(Color::blue(), Color::white(), 16);
    Union scence;
    scence.push(plane1);
    scence.push(sphere1);
    scence.push(sphere2);
    long maxDepth=20;
    
    float dx=1.0f/WINDOW_WIDTH;
    float dy=1.0f/WINDOW_HEIGHT;
    float dD=255.0f/maxDepth;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y)
    {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x)
        {
            float sx =dx*x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = scence.isIntersected(ray);
            //IntersectResult result = plane1.isIntersected(ray);
            if (result.is_hit)
            {
                Color color = result.object->material->sample(ray, result.position, result.normal);
                //Color color =plane1.material->sample(ray, result.position, result.normal);
                color.saturate();
                //color.show();
                glColor3ub(color.r*255,color.g*255,color.b*255);
                glVertex2f(sx,sy);
            }
        }
    }
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}

Color rayTraceRecursive(MyObject* scene,
                        Ray& ray,
                        long max_reflect) {
    IntersectResult result = scene->isIntersected(ray);
    if (result.object)
    {
        float reflectiveness = result.object->material->getRef();
        Color color = result.object->material->sample(ray, result.position, result.normal);
        color = color.multiply(1 - reflectiveness);
        if ((reflectiveness > 0) && (max_reflect > 0))
        {
            Vector3d r = result.normal*(-2 * result.normal.dotMul(ray.getDirection()))+ray.getDirection();
            Ray ray = Ray(result.position, r);
            Color reflectedColor = rayTraceRecursive(scene, ray, max_reflect - 1);
            color = color.add(reflectedColor.multiply(reflectiveness));
        }
        return color;
    } else
        return Color::black();
}

void renderRecursive(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(-0.5f,-0.5f,-1.0f);
    glPointSize(2.0);
    Camera camera0(Vector3d(0, 10, 10),Vector3d(0, -0.5, -1),Vector3d(0, 1, 0), 90);
    Plane* plane1=new Plane(Vector3d(0, 1, 0),1.0);
    Sphere* sphere1=new Sphere(Vector3d(-2, 3, -10), 2.0);
    Sphere* sphere2=new Sphere(Vector3d(2, 2, -7), 1.0);
    plane1->material=new Checker(0.7f,0.5f);
    sphere1->material=new Phong(Color::red(), Color::white(), 16,0.25);
    sphere2->material=new Phong(Color::green(), Color::white(), 16,0.25);
    Union scene;
    scene.push(plane1);
    scene.push(sphere1);
    scene.push(sphere2);
    long maxDepth=20;
    long maxReflect=5;
    float dx=1.0f/WINDOW_WIDTH;
    float dy=1.0f/WINDOW_HEIGHT;
    float dD=255.0f/maxDepth;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y)
    {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x)
        {
            float sx =dx*x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = scene.isIntersected(ray);
            //IntersectResult result = plane1.isIntersected(ray);
            if (result.is_hit)
            {
                Color color = rayTraceRecursive(&scene, ray, maxReflect);
                //Color color = result.object->material->sample(ray, result.position, result.normal);
                //Color color =plane1.material->sample(ray, result.position, result.normal);
                color.saturate();
                //color.show();
                glColor3ub(color.r*255,color.g*255,color.b*255);
                glVertex2f(sx,sy);
            }
        }
    }
    glEnd();
    // 交换缓冲区
    glfwSwapBuffers(window);
    glfwPollEvents();
}