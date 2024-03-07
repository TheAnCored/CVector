#include "header.hpp"

// Функция, считывающая все вектора из файла
CVector** reading_from_file(std::string filename, Fabric** fabrics, size_t& amount_of_vectors){

    std::string tmp;
    std::ifstream filestream(filename);

    if(filestream.is_open()){
        while(getline(filestream, tmp)){
            amount_of_vectors++;
        }
    }filestream.close();

    filestream.open(filename);

    CVector** vectors = new CVector*[amount_of_vectors];

    for(size_t i=0; i<amount_of_vectors; ++i){

        int index=0;
        size_t length=0;

        std::string string, filename_str, vector_str;
        std::stringstream stream;

        getline(filestream, string);

        stream<<string;

        stream>>index;

        stream>>filename_str;

        std::ofstream filename(filename_str, std::ios_base::trunc);

        getline(stream, vector_str,'\n');

        if(vector_str[vector_str.size()-1]=='\r' || vector_str[vector_str.size() -1] =='\n' || vector_str[vector_str.size() -1] =='\0'){ vector_str.erase(vector_str.size()-1); }

        double* vector;
        vector = reading_vector(vector_str, length);

        // Сборка
        vectors[i] = fabrics[index]->create(vector, length, filename_str);

        delete[] vector;
    }

    filestream.close();

    return vectors;
}

// Функция, считывающая вектор из строки
double* reading_vector(std::string str, size_t& length){

    std::stringstream stream1, stream2;
    stream1<<str; stream2<<str;
    
    while(!stream1.eof()){ 
        double digit;
        stream1>>digit; ++length; 
    }

    double* vector = new double[length];
  
    for(size_t i=0; i<length; ++i){
        stream2>>vector[i];
    }

    return vector;
}

// Очистка векторов
void delete_vectors(CVector** vectors, size_t amount_of_vectors){
    for(size_t i=0; i<amount_of_vectors; ++i){
        delete vectors[i];
    }
    delete[] vectors;
}
