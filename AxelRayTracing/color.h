//
//  color.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__color__
#define __AxelRayTracing__color__

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;

class Color {
public:
    float r;
    float g;
    float b;
    Color();
    Color(float _r, float _g, float _b);
    virtual ~Color();
    Color add(const Color& c);
    Color multiply(float s) const;
    Color modulate(const Color& c) const;
    void saturate();
    void getInfo();
    static inline Color black() { return Color(0,0,0); }
    static inline Color white() { return Color(1,1,1); }
    static inline Color red() { return Color(1,0,0); }
    static inline Color green() { return Color(0,1,0); }
    static inline Color blue() { return Color(0,0,1); }
    
};

#endif /* defined(__AxelRayTracing__color__) */
