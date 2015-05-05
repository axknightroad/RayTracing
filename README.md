# RayTracing
advanced CG homework

Realistic renderer by ray tracing

计算机图形学作业

简单光线追踪算法实现的真实感图形渲染器

-----------------------------------------

###开发环境及框架

* OS X 10.10.3
* Xcode 6.3.1
* openGL
* GLFW


--------------------

###说明

该渲染器实现了简单的光线追踪算法。

分别编程实现了底层三维向量、光线类、摄像机类，球体类和材质类等光线追踪算法利用到的类，
通过光线与物体交点及反射，并利用开源库GLFW和openGL实现了渲染。

--------

###文件说明

`vector3d.h` `vector3d.cpp` 三维向量类

`ray.h` `ray.cpp` 光线类

`camera.h` `camera.cpp`摄像机类

`myobject.h` `myobject.cpp`三维物体类

`sphere.h` `sphere.cpp`三维球体类

`plane.h` `plane.cpp`三维平面类

`intersectResult.h` `intersectResult.cpp`表示物体与光线相交结果的结构体

`material.h` `material.cpp`材质类

`color.h` `color.cpp`颜色类

`phong.h` `phong.cpp`phong材质类

`checker.h` `checker.cpp`棋盘材质类

`union.h` `union.cpp`多个物体联合类

`render.h` `render.cpp`渲染函数实现

`main.cpp` 主函数