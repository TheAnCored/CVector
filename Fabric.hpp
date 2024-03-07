#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"

#pragma once

class Fabric{
public:
    virtual CVector* create(double*, size_t, std::string)=0;

    virtual ~Fabric(){};
};
