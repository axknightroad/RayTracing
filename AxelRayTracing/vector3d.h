//
//  vector3d.h
//  AxelRayTracing
//
//  Created by axel on 15/4/29.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef AxelRayTracing_vector3d_h
#define AxelRayTracing_vector3d_h

#include <iostream>
#include <cmath>

#define MIN(x,y) (x)>(y)?(y):(x);
#define MAX(x,y) (x)>(y)?(x):(y);

using namespace std;

//三维向量类,也可以用来表示空间中的点
class Vector3d {
 public:
    float x;
    float y;
    float z;
    // 缺省构造函数
    Vector3d();
    ~Vector3d();
    // 用户构造函数
    Vector3d(float pos_x, float pos_y, float pos_z);
    
    //输出向量信息
    void getInfo();
    //向量加法
    Vector3d operator + (Vector3d v);
    //向量减法
    Vector3d operator - (Vector3d v);
    //数乘
    Vector3d operator * (float n);
    //数除
    Vector3d operator / (float n);
    //向量点积
    float dotMul(Vector3d v);
    //向量叉乘
    Vector3d crossMul(Vector3d v);
    //绝对值化
    Vector3d abs();
    //获取分量中的最大值
    float max();
    //获取分量的最小值
    float min();
    //获取向量长度
    float getLength();
    //向量单位化
    Vector3d normalize();
    //求两点之间的距离
    float getDist(Vector3d v);
    
    //返回零向量
    static inline Vector3d zero() { return Vector3d(0, 0, 0); }
};

#endif
