// Класс вектора(общий)
#include <cstring>
#include <iostream>
#include <fstream>

#pragma once

class CVector{
protected:
    double* vector;
    size_t length;
    std::string filename;
    bool index;

public:
    // Стандартный конструктор
    CVector();
    // Без файла
    CVector(bool, double*, size_t);
    // С файлом
    CVector(bool index, double* vector, size_t length, std::string filename);

    // Оператор копирования
    CVector(const CVector&);
    // Оператор присваивания 
    CVector& operator=(const CVector&);

    // Конструктор перемещения
    CVector(CVector&&);
    // Оператор присваивания с перемещением
    CVector& operator=(CVector&&);

    // Деструктор
    virtual ~CVector(){
        delete[] vector;
    }

    // Скалярное произведение
    double operator*(const CVector&) const&;

    // Получение индекса
    bool get_index()const{ return this->index; }

    // Получение длины вектора
    double get_length()const;

    // Получение название файла и длины названия
    std::string get_filename()const;
    int get_filename_length()const;

    // Получение копии вектора
    double* get_vector()const;

    // Функция вывода 
    virtual void output()=0;
};
