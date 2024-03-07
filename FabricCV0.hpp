#include "Fabric.hpp"

class FabricCVector0:public Fabric{
public:
    virtual CVector0* create(double*, size_t, std::string);

    ~FabricCVector0(){};
};
