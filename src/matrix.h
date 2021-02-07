#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>
#include <cstdint>

class Matrix {
public:
    struct Row {
        std::vector<uint8_t> data;
        uint8_t &operator[](int x);
        void operator<<(int steps);
        void operator>>(int steps);
        Row(int size);
    };

private:
    std::vector<Row> rows;

public:
    Matrix(const Matrix &other);
    Matrix(std::vector<uint8_t> data);
    Matrix::Row &operator[](int y);
    void operator^=(Matrix &other);
    void rotateColUp(int x, uint8_t(*substitute)(uint8_t));
    friend std::ostream &operator<<(std::ostream &out, Matrix &matrix);
    std::vector<uint8_t> getData();
};

#endif