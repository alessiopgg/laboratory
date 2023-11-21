//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_ISUBJECT_H
#define LABORATORY_ISUBJECT_H

#endif //LABORATORY_ISUBJECT_H

#include<iostream>
#include "IObserver.h"
using namespace std;

class ISubject{ //interfaccia
public:
    virtual void registerObserver(IObserver*observer)=0;
    virtual void unregisterObserver(IObserver*observer)=0;
    virtual void notify()=0;
    virtual ~ISubject()=default;
};