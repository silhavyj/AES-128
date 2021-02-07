#ifndef _KEY_H_
#define _KEY_H_

#include <vector>
#include <cstdint>

#include "matrix.h"

class Key {
private:
    std::vector<Matrix> keys;

private:
    Matrix expand(Matrix &key);

public:
    Key(std::vector<uint8_t> data);
    Matrix &operator[](int index);
    void expand(int rounds);
};

#endif