//
//  PointSet.h
//  ClosestPoint
//
//  Created by F.K on 8/6/17.
//  Copyright (c) 2017 __PaneceaORG__. All rights reserved.
//

#ifndef ClosestPoint_PointSet_h
#define ClosestPoint_PointSet_h
#include "Point.h"
template <class T>
class PointSet{
    Point<T>* set;
    int size;
    //Point<T>;
public:
    void setPointSet(int size, Point<T> *p){
        set=p;
        this->size=size;
    }
    Point<T>* getArr(){
        return set;
    }
    int getSize(){
        return size;
    }
};
#endif
