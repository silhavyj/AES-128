#include <algorithm>
#include <cstring>
#include <iomanip>

#include "matrix.h"
#include "tables.h"

uint8_t &Matrix::Row::operator[](int x) {
    return data[x];
}

Matrix::Row &Matrix::operator[](int y) {
    return rows[y];
}

Matrix::Row::Row(int size) {
    data = std::vector<uint8_t>(size, 0);
}

void Matrix::Row::operator<<(int steps) {
    std::rotate(data.begin(), data.begin() + steps, data.end());
}

void Matrix::Row::operator>>(int steps) {
    std::rotate(data.begin(), data.begin() + data.size() - steps, data.end());
}

void Matrix::rotateColUp(int x, uint8_t(*substitute)(uint8_t)) {
    uint8_t tmp = (*this)[0][x];
    for (int i = 1; i < N; i++) {
        (*this)[i-1][x] = (*this)[i][x];
        if (substitute != NULL)
            (*this)[i-1][x] = substitute((*this)[i-1][x]);
    }
    (*this)[N-1][x] = tmp;
    if (substitute != NULL)
        (*this)[N-1][x] = substitute(tmp);
}

void Matrix::operator^=(Matrix &other) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            (*this)[i][j] ^= other[i][j]; 
}

Matrix::Matrix(const Matrix &other) {
    for (int i = 0; i < N; i++) {
        Matrix::Row row(N);
        for (int j = 0; j < N; j++)
            row[j] = other.rows[i].data[j];
        rows.push_back(row);
    }
}

Matrix::Matrix(std::vector<uint8_t> data) {
    int remainder = data.size() % BLOCK_SIZE;
    if (remainder != 0)
        remainder = BLOCK_SIZE - remainder;

    for (int i = 0; i < remainder; i++)
        data.push_back(0);

    for (int i = 0; i < N; i++) {
        Matrix::Row row(N);
        for (int j = 0; j < N; j++)
            row[j] = data[j * N + i];
        rows.push_back(row);
    }
}

std::vector<uint8_t> Matrix::getData() {
    std::vector<uint8_t> data;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            data.push_back((*this)[j][i]);
    return data;
}

std::ostream &operator<<(std::ostream &out, Matrix &matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            out << "0x" << std::setfill('0') << std::setw(2) << std::right << std::hex << (int)matrix[i][j] << " ";
        out << "\n";
    }
    return out;
}