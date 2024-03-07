#include "Fabric.hpp"

class FabricCVector1:public Fabric{
public:
    virtual CVector1* create(double*, size_t, std::string);

    ~FabricCVector1(){};
};
