//
//  union.h
//  AxelRayTracing
//
//  Created by axel on 15/5/5.
//  Copyright (c) 2015年 axel. All rights reserved.
//

#ifndef __AxelRayTracing__union__
#define __AxelRayTracing__union__

#include "myobject.h"
#include <vector>

using namespace std;

class Union : public MyObject {
private:
    vector<MyObject*> objects;
    
public:
    Union();
    virtual ~Union();
    void push(MyObject* object);
    virtual IntersectResult isIntersected(Ray& _ray); 
};

#endif /* defined(__AxelRayTracing__union__) */
