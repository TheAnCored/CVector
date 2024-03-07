#include "CVector0.hpp"


// Обычный конструктор
CVector0::CVector0(double* vector, size_t lenght):
    CVector(0,vector,lenght){}

CVector0::CVector0(double* vector, size_t length, std::string filename):
    CVector(0,vector,length,filename){}

// Перегружаемая функция
void CVector0::output(){
    std::ofstream out;

    if(this->get_filename_length() > 0){
        out.open(this->filename, std::ios::app);
        for(size_t i=0;i<this->length; ++i){ out<<this->vector[i]<<' ';}
        out.close();
    }
}

// Оператор присваивания
CVector0& CVector0::operator=(const CVector0& second){

    if(this!=&second){

        delete[] this->vector;

        this->length=second.length;
        this->index=second.index;

        if(second.get_filename_length()>0){
            this->filename = second.filename;
        }

        this->vector = new double[second.length];

        for(size_t i=0; i<this->length; ++i){
            this->vector[i] = second.vector[i];
        }
    }
    return *this;
}

// Конструктор копирования
CVector0::CVector0(const CVector& second) : CVector(second){}

CVector0::CVector0(const CVector0& second) : CVector(second){}

// Конструктор перемещения
CVector0::CVector0(CVector&& second){

    this->vector=second.get_vector();
    this->length=second.get_length();

    this->filename=second.get_filename();
    this->index=second.get_index();
}

CVector0 operator+(const CVector& first, const CVector& second){

    size_t length1 = first.get_length();

    double* tmp_vector = new double[length1];

    double* tmp_vec1 = first.get_vector();
    double* tmp_vec2 = second.get_vector();

    try{
        size_t length2 = second.get_length();
        if(length1 != length2){ throw "НЕравная длина векторов!\n"; }

        for(size_t i=0; i<length1; ++i){
            tmp_vector[i] = 0;
            tmp_vector[i] = tmp_vec1[i] + tmp_vec2[i];
        }
    }catch(const char* error_message){ std::cout<<error_message<<std::endl; }

    delete[] tmp_vec1;
    delete[] tmp_vec2;

    CVector0 result = CVector0(tmp_vector, length1);

    delete[] tmp_vector;

    return result;
}
CVector0 operator-(const CVector& first, const CVector& second){

    size_t length = first.get_length();

    double* tmp_vector = new double[length];
    double* tmp_vec1 = first.get_vector();
    double* tmp_vec2 = second.get_vector();

    try{
        size_t length1 = first.get_length();
        size_t length2 = second.get_length();
        if(length1 != length2){ throw "НЕравная длина векторов!\n"; }

        for(size_t i=0; i<length; ++i){
            tmp_vector[i] = 0;
            tmp_vector[i] = tmp_vec1[i] - tmp_vec2[i];
        }
    }catch(const char* error_message){ std::cout<<error_message<<std::endl; }

    delete[] tmp_vec1;
    delete[] tmp_vec2;

    CVector0 result = CVector0(tmp_vector, length);

    delete[] tmp_vector;

    return result;
}
