#include "CVector.hpp"

// КОНСТРУКТОРЫ
CVector::CVector(){
    this->vector=nullptr;
    this->length=0; this->index=0;
}

CVector::CVector(bool index, double* vector, size_t length){
    this->index = index;
    this->length = length;

    this->vector = new double[length];
    for(size_t i=0; i<length; ++i){ this->vector[i]=vector[i];}
}

CVector::CVector(bool index, double* vector, size_t length, std::string filename){
    this->index = index;

    this->length = length;
    this->vector = new double[length];

    for(size_t i=0; i<length; ++i){ this->vector[i]=vector[i];}

    this->filename=filename;
}
//----------------

// Конструктор копирования
CVector::CVector(const CVector& second){

    this->length = second.length;

    this->vector = new double[this->length];

    for(size_t i=0; i<length; ++i){
        this->vector[i]=second.vector[i];
    }

    this->filename = second.filename;
}

// Оператор присваивания
CVector& CVector::operator=(const CVector& second){

    if(this!=&second){

        delete[] this->vector;
  
        this->length=second.length;
        this->index=second.index;

        if(second.get_filename_length()>0){
            this->filename = second.filename;
        }else {
            this->filename = nullptr;
        }

        this->vector = new double[second.length];

        for(size_t i=0; i<this->length; ++i){
            this->vector[i] = second.vector[i];
        }
    }
    return *this;
}

// Конструктор перемещения
CVector::CVector(CVector&& second){

    this->vector=second.vector;
    this->length=second.length;

    this->filename=second.filename;
    this->index=second.index;

    second.filename=nullptr;
    second.vector=nullptr;
}

// Оператор присваивания с перемещением
CVector& CVector::operator=( CVector&& second){

    if(this!=&second){
        delete this->vector;

        this->length=second.length;
        this->index=second.index;

        this->vector = second.vector;

        second.vector = nullptr;
    }

    return *this;
}

// Скалярное умножение векторов
double CVector::operator*(const CVector& second) const&{
    double dot_product=0.;
    try{ 
        if(this->length!=second.length) throw "НЕравная длина векторов!\n";

        for(size_t i=0; i<second.length;++i){ dot_product+= this->vector[i]*second.vector[i]; }
    }
    catch(const char* error_message){ std::cout<<error_message<<std::endl;}

    return dot_product;
}

// Получение длины вектора
double CVector::get_length()const{ return this->length; }

// Получение название файла
std::string CVector::get_filename()const{

    std::string tmp = this->filename;
    return tmp;
}

int CVector::get_filename_length()const{
    return this->filename.size();
}

// Получение копии вектора
double* CVector::get_vector()const{
    double* vect_copy = new double[this->length];

    for(size_t i=0;i<this->length; ++i){ vect_copy[i]=this->vector[i];}

    return vect_copy;
}
