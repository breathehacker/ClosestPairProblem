//
//  main.cpp
//  ClosestPoint
//
//  Created by F.K on 8/6/17.
//  Copyright (c) 2017 __PaneceaORG__. All rights reserved.
//

#include <iostream>
#include "ClosestPair.h"
using namespace std;
int main(int argc, const char * argv[])
{
    //Condidering points
    //{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
   
    int x[]={2,12,40,5,12,3};
    int y[]={3,30,50,1,10,4};
    Point<float> *p;
    int size=6;
    p=new Point<float>[size];
      
    for (int i=0; i<size; i++) {
        p[i].set(x[i], y[i]);
    }
    PointSet <float>s;
    s.setPointSet(size, p);
    ClosestPair<float> sp(s);
    int a;
    cout<<"Enter 1 for bruteForce\nEnter 2 for divide nd conq"<<endl;
    cin>>a;
    switch (a) {
        case 1:
            cout<<"By brute Force\t"<<sp.callBruteForce()<<endl;
            break;
        case 2:
              cout<<"By Divide nd Conq \t"<<sp.dividendConquer()<<endl;
            break;
        default:
            cout<<"INVALID CHOICE!\n";
            break;
    }
    return 0;
}

