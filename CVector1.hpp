#include "CVector.hpp"

#pragma once

class CVector1:public CVector{
public:
    
    CVector1():CVector(){}
    CVector1(double*, size_t);
    CVector1(double*, size_t, std::string);

    // Оператор копирования
    CVector1(const CVector&);
    CVector1(const CVector1&);

    // Конструктор перемещения
    CVector1(CVector&&);

    using CVector::operator*;
    using CVector::operator=;
    CVector1& operator=(const CVector1&);

    virtual void output();

    ~CVector1()=default;
};
