#include "readings.h"
#include <iostream>
#include <fstream>
#include <new>        // std::nothrow
#include <iomanip>    // std::setprecision

float* crear_arreglo(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new float[size];
}

void liberar_arreglo(float*& arr) {
    //TODO
    delete[] arr;
    arr = nullptr;
}

int cargar_desde_archivo(const std::string& ruta, float* arr, int size) {
    //TODO
    if (arr == nullptr || size <= 0)    return 0;
    else {
        std::ifstream file(ruta);
        if (!file.is_open()) {
            return 0;
        }
        int count = 0;
        while (count < size && file >> arr[count]) {
            count++;
        }
        file.close();
        return count;
    }   
}

bool guardar_en_archivo(const std::string& ruta, const float* arr, int size) {
    // TODO
    if (arr == nullptr || size <= 0) {
        return false;
    } else {
        std::ofstream file(ruta);
        if (!file.is_open()) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            file << std::fixed << std::setprecision(2) << arr[i] << "\n";
        }
        file.close();
        return true;
    }
}

void imprimir(const float* arr, int size) {
    // TODO
    if (arr == nullptr || size <= 0) {
        std::cout << "No hay datos para mostrar." << std::endl;
    } else {
        for (int i = 0; i < size; i++) {
            std::cout << std::fixed << std::setprecision(2) << arr[i] << "\n";
        }
    }
}
