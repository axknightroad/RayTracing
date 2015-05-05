//
//  color.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "color.h"

Color::Color() {}

Color::~Color() {}

Color::Color(float _r, float _g, float _b) {
    r = _r;
    g = _g;
    b = _b;
}

Color Color::add(const Color &c) {
    return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::multiply(float s) const {
    return Color(r * s, g * s, b * s);
}

Color Color::modulate(const Color &c) const {
    return Color(r * c.r, g * c.g, b * c.b);
}

void Color::saturate() {
    r = r > 1.0 ? 1.0 : r;
    g = g > 1.0 ? 1.0 : g;
    b = b > 1.0 ? 1.0 : b;
}

void Color::getInfo() {
    cout << "r:" << r
    <<" g:" << g
    << " b:" << b <<endl;
}