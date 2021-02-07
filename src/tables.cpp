#include "tables.h"

uint8_t s_box(uint8_t val) {
    return S_BOX[Y(val) * BLOCK_SIZE + X(val)];
}

uint8_t s_box_inv(uint8_t val) {
    return S_BOX_INV[Y(val) * BLOCK_SIZE + X(val)];
}