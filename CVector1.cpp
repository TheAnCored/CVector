#include "CVector1.hpp"
#include "CVector0.hpp"

// Перегружаемая функция
void CVector1::output(){
    std::ofstream out;

    if(this->get_filename_length() > 0){
        out.open(this->filename, std::ios::app);

        for(size_t i=0;i<this->length; ++i){ out<<this->vector[i]<<'\n';}
        out.close();
    }
}


// Обычный конструктор
CVector1::CVector1(double* vector, size_t lenght):
    CVector(1,vector,lenght){}


CVector1::CVector1(double* vector, size_t length, std::string filename):
    CVector(1,vector,length,filename){}

// Оператор присваивания
CVector1& CVector1::operator=(const CVector1& second){

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
CVector1::CVector1(const CVector& second) : CVector(second){
}

CVector1::CVector1(const CVector1& second) : CVector(second){
}

// Конструктор перемещения
CVector1::CVector1(CVector&& second){

    this->vector=second.get_vector();
    this->length=second.get_length();

    this->filename=second.get_filename();
    this->index=second.get_index();
}
