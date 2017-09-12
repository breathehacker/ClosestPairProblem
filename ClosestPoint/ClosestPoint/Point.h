//
//  Point.h
//  ClosestPoint
//
//  Created by F.K on 8/6/17.
//  Copyright (c) 2017 __PaneceaORG__. All rights reserved.
//

#ifndef ClosestPoint_Point_h
#define ClosestPoint_Point_h
template <class T>
class Point {
    T x;
    T y;
public:
    void set(T xC, T yC){
        x=xC;
        y=yC;
    }
    void say(){
        std::cout<<"X ---- >  "<<x<<"    Y ---- >"<<y<<std::endl;
        
    }
    T getX(){
        return x;
    }
    T getY(){
        return y;
    }
};


#endif
