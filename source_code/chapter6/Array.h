#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <stdexcept>
#include <iostream>

class MJArray {
public:
    // Construtor padrão
    MJArray(size_t size = 0) : data(size, 0.0) {}

    // Construtor de inicialização com valores
    MJArray(const std::initializer_list<double>& values) : data(values) {}

    // Acesso ao elemento (leitura e escrita)
    double& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const double& operator[](size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Obter o tamanho do array
    size_t size() const {
        return data.size();
    }

    // Redimensionar o array
    void resize(size_t newSize) {
        data.resize(newSize);
    }

    // Imprimir o conteúdo do array
    void print() const {
        for (double value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<double> data; // Contém os dados do array
};

#endif // ARRAY_H
