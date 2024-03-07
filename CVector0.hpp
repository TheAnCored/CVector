#include "CVector.hpp"

#pragma once

class CVector0:public CVector{
public:
    CVector0():CVector(){}
    CVector0(double*, size_t);
    CVector0(double* vector, size_t length, std::string filename);

    // Оператор копирования
    CVector0(const CVector&);
    CVector0(const CVector0&);

    // Конструктор перемещения
    CVector0(CVector&&);

    friend CVector0 operator+(const CVector&, const CVector&);
    friend CVector0 operator-(const CVector&, const CVector&);

    using CVector::operator*;
    using CVector::operator=;
    CVector0& operator=(const CVector0&);

    virtual void output();

    ~CVector0()=default;
};

// Объявление оператора сложения
CVector0 operator+(const CVector& first, const CVector& second);
CVector0 operator-(const CVector& first, const CVector& second);
