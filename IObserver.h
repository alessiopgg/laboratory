//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_IOBSERVER_H
#define LABORATORY_IOBSERVER_H

#endif //LABORATORY_IOBSERVER_H

#include<iostream>
using namespace std;

class IObserver{ //interfaccia
public:
    virtual void update(float u,float c,float t,string n,int un) =0;
    virtual string getUsername()=0;
    virtual ~IObserver()=default;
};