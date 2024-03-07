#include "header.hpp"

int main(){

    Fabric** fabrics = new Fabric*[2];
    fabrics[0] = new FabricCVector0;
    fabrics[1] = new FabricCVector1;

    size_t amount_of_vectors=0;

    std::string filename="data.txt";
    CVector** vectors;

    vectors = reading_from_file(filename,fabrics, amount_of_vectors);

    for(size_t i=0;i<amount_of_vectors;++i){vectors[i]->output(); }

    delete_vectors(vectors, amount_of_vectors);

    delete fabrics[0];
    delete fabrics[1];

    delete[] fabrics;

////--------------------

    double* tmp1 = new double[6];
    double* tmp2 = new double[6];

    for(size_t i=0; i<6;++i){ tmp1[i]=1;tmp2[i]=2; }

    CVector0 a = CVector1(tmp1, 6);
    CVector0 b = CVector1(tmp2, 6);

    CVector0 c;
    c = a+b;

   delete[] tmp1; delete[] tmp2;


    return 0;
}
