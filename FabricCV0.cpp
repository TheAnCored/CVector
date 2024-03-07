#include "FabricCV0.hpp"

CVector0* FabricCVector0::create(double* vector, size_t length, std::string filename){
    return new CVector0(vector, length, filename);
}
