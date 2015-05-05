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


void initWindow(int w,int h) {
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

Color rayTraceRecursive(MyObject* scene, Ray& ray, long max_reflect) {
    IntersectResult result = scene->isIntersected(ray);
    if (result.object) {
        float reflectiveness = result.object->material->getRef();
        Color color = result.object->material->sample(ray, result.position,
                                                      result.normal);
        color = color.multiply(1 - reflectiveness);
        if ((reflectiveness > 0) && (max_reflect > 0)) {
            Vector3d r = result.normal
                         * (-2 * result.normal.dotMul(ray.getDirection()))
                         + ray.getDirection();
            Ray ray = Ray(result.position, r);
            Color reflectedColor = rayTraceRecursive(scene, ray,
                                                     max_reflect - 1);
            color = color.add(reflectedColor.multiply(reflectiveness));
        }
        return color;
    } else {
        return Color::black();
    }
}

void rendering(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-0.5f, -0.5f, -1.0f);
    glPointSize(2.0);
    Camera camera0(Vector3d(0, 10, 10), Vector3d(0, -0.5, -1),
                   Vector3d(0, 1, 0), 90);
    Plane* plane1 = new Plane(Vector3d(0, 1, 0), 1.0);
    Sphere* sphere1 = new Sphere(Vector3d(-2, 3, -10), 2.0);
    Sphere* sphere2 = new Sphere(Vector3d(1, 3.5, -6), 2.5);
    plane1->material = new Checker(0.7f,0.5f);
    sphere1->material = new Phong(Color(0,1,1), Color::white(), 16,0.25);
    sphere2->material = new Phong(Color(1,1,0), Color::white(), 16,0.25);
    Union scene;
    scene.push(plane1);
    scene.push(sphere1);
    scene.push(sphere2);
    long max_reflect = 5;
    float dx = 1.0f / WINDOW_WIDTH;
    float dy = 1.0f / WINDOW_HEIGHT;
    glBegin(GL_POINTS);
    for (long y = 0; y < WINDOW_HEIGHT; ++y) {
        float sy = 1 - dy*y;
        for (long x = 0; x < WINDOW_WIDTH; ++x) {
            float sx = dx * x;
            Ray ray(camera0.generateRay(sx, sy));
            IntersectResult result = scene.isIntersected(ray);
            if (result.is_hit) {
                Color color = rayTraceRecursive(&scene, ray, max_reflect);
                color.saturate();
                glColor3ub(color.r*255, color.g*255, color.b*255);
                glVertex2f(sx, sy);
            }
        }
    }
    glEnd();
    glfwSwapBuffers(window);
    glfwPollEvents();
}