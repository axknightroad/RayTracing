//
//  union.cpp
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#include "union.h"

Union::Union() {}

Union::~Union() {}

void Union::push(MyObject* object) {
    objects.push_back(object);
}

IntersectResult Union::isIntersected(Ray& _ray)
{
    const float Infinity=1e30;
    float minDistance = Infinity;
    IntersectResult minResult = IntersectResult::noHit();
    long size=this->objects.size();
    for (long i=0;i<size;++i){
        IntersectResult result = this->objects[i]->isIntersected(_ray);
        if (result.object && (result.distance < minDistance)) {
            minDistance = result.distance;
            minResult = result;
        }
    }
    return minResult;
}
