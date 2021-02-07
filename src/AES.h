#ifndef _AES_H_
#define _AES_H_

#include <cstdint>
#include <vector>

#include "matrix.h"
#include "key.h"

class AES {
private:
    void alignData(std::vector<uint8_t> &data, int align);
    std::vector<uint8_t> encrypt(Matrix &state, Key &key, int rounds);
    void substitute(Matrix &state, uint8_t(*func)(uint8_t));
    void shiftRowsLeft(Matrix &state);
    void shiftRowsRight(Matrix &state);
    void mixColumns(Matrix &state, bool encrypt);
    std::vector<uint8_t> decrypt(Matrix &state, Key &key, int rounds);

public:
    std::vector<uint8_t> encrypt(std::vector<uint8_t> data, std::vector<uint8_t> key);
    std::vector<uint8_t> decrypt(std::vector<uint8_t> data, std::vector<uint8_t> key);
};

#endif