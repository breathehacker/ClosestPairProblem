//
//  ClosestPair.h
//  ClosestPoint
//
//  Created by F.K on 8/6/17.
//  Copyright (c) 2017 __PaneceaORG__. All rights reserved.
//

#ifndef ClosestPoint_ClosestPair_h
#define ClosestPoint_ClosestPair_h
#include <math.h>
#include <algorithm>
#include <float.h>
#include "PointSet.h"
#include "Point.h"
int compareX(const void* a, const void* b)
{
    Point<double> *p1 = (Point<double> *)a,  *p2 = (Point<double> *)b;
    return (p1->getX() - p2->getX());
}
int compareY(const void* a, const void* b)
{
    Point<double> *p1 = (Point<double> *)a,  *p2 = (Point<double> *)b;
    return (p1->getY() - p2->getY());
}
template <class T>

class ClosestPair {
    PointSet<T> p;
    double dist(Point<T> p1, Point<T> p2)
    {
        return sqrt( (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
                    (p1.getY() - p2.getY())*(p1.getY() - p2.getY())
                    );
    }
    T min(T x, T y)
    {
        return (x < y)? x : y;
    }
    T stripClosest(Point<T> strip[], int size, float d)
    {
        float min = d;  
        
        qsort(&p, p.getSize(), sizeof(p), compareY);
        
        for (int i = 0; i < size; ++i)
            for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j)
                if (dist(strip[i],strip[j]) < min)
                    min = dist(strip[i], strip[j]);
        
        return min;
    }
    T bruteForce(Point<T> P[], int n)
    {
        T min = FLT_MAX;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (dist(P[i], P[j]) < min)
                    min = dist(P[i], P[j]);
        return min;
    }
    float closestUtil(Point<T> P[], int n)
    {
        
        if (n <= 3)
            return bruteForce(P, n);
        
        int mid = n/2;
        Point<T> midPoint = P[mid];
        
        T dl = closestUtil(P, mid);
        T dr = closestUtil(P + mid, n-mid);
        T d = min(dl, dr);
        Point<T> *strip;
        
        strip=new Point<T>[p.getSize()];
        int j = 0;
        for (int i = 0; i < n; i++)
            if (abs(P[i].getX() - midPoint.getX()) < d)
                strip[j] = P[i], j++;
        
        return min(d, stripClosest(strip, j, d) );
    }
    
    
    T dividendconq(Point<T> P[], int n)
    {
        
        std::qsort(&P, n, sizeof(Point<T>), compareX);
        return closestUtil(P, n);
    }
    
public:
    ClosestPair(PointSet<T> p){
        this->p=p;
    }
           T callBruteForce(){
        return bruteForce(p.getArr(),p.getSize());
        //T val=;
    }
    T dividendConquer(){
       return dividendconq(p.getArr(), p.getSize());
    }
   };
#endif
