#include <iostream>
#include <sstream>
#include <string>

#include "CVector.hpp"
#include "CVector0.hpp"
#include "Fabric.hpp"
#include "FabricCV0.hpp"
#include "FabricCV1.hpp"

// Функция, считывающая все вектора из файла
CVector** reading_from_file(std::string, Fabric**, size_t&);

// Функция, считывающая вектор из строки
double* reading_vector(std::string str, size_t& amount);

// Очистка веткоров
void delete_vectors(CVector**, size_t);
