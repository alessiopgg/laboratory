//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_IOBSERVER_H
#define LABORATORY_IOBSERVER_H

#endif //LABORATORY_IOBSERVER_H

#include<iostream>
using namespace std;

class IObserver{
public:
    virtual void update(string basicString) =0;
    virtual const string getUsername() const=0;
    virtual ~IObserver()=default;
};