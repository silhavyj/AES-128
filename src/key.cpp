#include "key.h"
#include "tables.h"

Key::Key(std::vector<uint8_t> data) {
    keys.push_back({data});
}

void Key::expand(int rounds) {
    while (rounds--)
        keys.push_back(expand(keys.back()));
}

Matrix Key::expand(Matrix &key) {
    static int round = 1;
    Matrix expandedKey = key;

    expandedKey.rotateColUp(N-1, &s_box);

    for (int i = 0; i < N; i++)
        expandedKey[i][0] ^= expandedKey[i][N-1];

    expandedKey[0][0] ^= R_CON[round++];
    
    for (int j = 1; j < N; j++)
        for (int i = 0; i < N; i++)
            expandedKey[i][j] = key[i][j] ^ expandedKey[i][j-1];

    return expandedKey;
}

Matrix &Key::operator[](int index) {
    return keys[index];
}