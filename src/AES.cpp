#include <algorithm>
#include "AES.h"
#include "tables.h"

std::vector<uint8_t> AES::encrypt(std::vector<uint8_t> data, std::vector<uint8_t> key) {
    Key keyBlock(key);
    keyBlock.expand(NUMBER_OF_ROUNDS);
    alignData(data, BLOCK_SIZE);

    std::vector<uint8_t> encryptedData;
    std::vector<uint8_t> dataBlock;

    for (int i = 0; i < (int)data.size() / BLOCK_SIZE; i++) {
        dataBlock = std::vector<uint8_t>(data.begin() + i * BLOCK_SIZE,
                                         data.begin() + i * BLOCK_SIZE + BLOCK_SIZE);
        Matrix state(dataBlock);
        auto enctyptedBlock = encrypt(state, keyBlock, NUMBER_OF_ROUNDS);
        encryptedData.insert(encryptedData.end(), enctyptedBlock.begin(), enctyptedBlock.end());
    }
    return encryptedData;
}

void AES::alignData(std::vector<uint8_t> &data, int align) {
    int remainder = data.size() % align;
    if (remainder != 0)
        remainder = align - remainder;
    for (int i = 0; i < remainder; i++)
        data.push_back(0);

    for (int i = 0; i < BLOCK_SIZE; i++)
        data.push_back(remainder);
}

void AES::substitute(Matrix &state, uint8_t(*func)(uint8_t)) {
    if (func == NULL)
        return;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            state[i][j] = func(state[i][j]);
}

void AES::shiftRowsLeft(Matrix &state) {
    for (int i = 0; i < N; i++)
        state[i] << i;
}

void AES::shiftRowsRight(Matrix &state) {
    for (int i = 0; i < N; i++)
        state[i] >> i;
}

void AES::mixColumns(Matrix &state, bool encrypt) {
    uint8_t tmp[N];
    for (int j = 0; j < N; j++) {
        if (encrypt) {
            tmp[0] = GF_MUL_02[state[0][j]] ^ state[3][j] ^ state[2][j] ^ GF_MUL_03[state[1][j]];
            tmp[1] = GF_MUL_02[state[1][j]] ^ state[0][j] ^ state[3][j] ^ GF_MUL_03[state[2][j]];
            tmp[2] = GF_MUL_02[state[2][j]] ^ state[1][j] ^ state[0][j] ^ GF_MUL_03[state[3][j]];
            tmp[3] = GF_MUL_02[state[3][j]] ^ state[2][j] ^ state[1][j] ^ GF_MUL_03[state[0][j]];
        } else {
            tmp[0] = GF_MUL_14[state[0][j]] ^ GF_MUL_09[state[3][j]] ^ GF_MUL_13[state[2][j]] ^ GF_MUL_11[state[1][j]];
            tmp[1] = GF_MUL_14[state[1][j]] ^ GF_MUL_09[state[0][j]] ^ GF_MUL_13[state[3][j]] ^ GF_MUL_11[state[2][j]];
            tmp[2] = GF_MUL_14[state[2][j]] ^ GF_MUL_09[state[1][j]] ^ GF_MUL_13[state[0][j]] ^ GF_MUL_11[state[3][j]];
            tmp[3] = GF_MUL_14[state[3][j]] ^ GF_MUL_09[state[2][j]] ^ GF_MUL_13[state[1][j]] ^ GF_MUL_11[state[0][j]];
        }
        for (int i = 0; i < N; i++)
            state[i][j] = tmp[i];
    }
}

std::vector<uint8_t> AES::decrypt(std::vector<uint8_t> data, std::vector<uint8_t> key) {
    Key keyBlock(key);
    keyBlock.expand(NUMBER_OF_ROUNDS);

    std::vector<uint8_t> decryptedData;
    std::vector<uint8_t> dataBlock;

    int blocks = (int)data.size() / BLOCK_SIZE;

    for (int i = 0; i < blocks; i++) {
        dataBlock = std::vector<uint8_t>(data.begin() + i * BLOCK_SIZE,
                                         data.begin() + i * BLOCK_SIZE + BLOCK_SIZE);
        Matrix state(dataBlock);
        auto decryptedBlock = decrypt(state, keyBlock, NUMBER_OF_ROUNDS);

        if (i < blocks - 1)
            decryptedData.insert(decryptedData.end(), decryptedBlock.begin(), decryptedBlock.end());
        else {
            for (int j = 0; j < decryptedBlock[0]; j++)
                decryptedData.pop_back();
        }
    }
    return decryptedData;
}

std::vector<uint8_t> AES::encrypt(Matrix &state, Key &key, int rounds) {
    state ^= key[0];
    for (int i = 0; i < rounds - 1; i++) {
        substitute(state, &s_box);    
        shiftRowsLeft(state);
        mixColumns(state, true);
        state ^= key[i+1];
    }
    substitute(state, &s_box);    
    shiftRowsLeft(state);
    state ^= key[rounds];
    
    return state.getData();
}

std::vector<uint8_t> AES::decrypt(Matrix &state, Key &key, int rounds) {
    state ^= key[rounds];
    shiftRowsRight(state);
    substitute(state, &s_box_inv);

    for (int i = rounds - 2; i >= 0; i--) {
        state ^= key[i+1];
        mixColumns(state, false);
        shiftRowsRight(state);
        substitute(state, &s_box_inv);
    }
    state ^= key[0];

    return state.getData();
}