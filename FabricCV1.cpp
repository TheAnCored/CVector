#include "FabricCV1.hpp"

CVector1* FabricCVector1::create(double* vector, size_t length, std::string filename){
    return new CVector1(vector, length, filename);
}
