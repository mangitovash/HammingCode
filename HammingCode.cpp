#include "HammingCode.h"

std::vector<int> HammingCode::encode(const std::vector<int>& data_bits) {
    int p1 = data_bits[0] ^ data_bits[1] ^ data_bits[3];
    int p2 = data_bits[0] ^ data_bits[2] ^ data_bits[3];
    int p3 = data_bits[1] ^ data_bits[2] ^ data_bits[3];
    int p4 = data_bits[0] ^ data_bits[1] ^ data_bits[2] ^ data_bits[3];
    return {p1, p2, data_bits[0], p3, data_bits[1], data_bits[2], data_bits[3], p4};
}

std::pair<int, std::vector<int>> HammingCode::decode(std::vector<int>& encoded_bits) {
    int p1 = encoded_bits[0] ^ encoded_bits[2] ^ encoded_bits[4] ^ encoded_bits[6];
    int p2 = encoded_bits[1] ^ encoded_bits[2] ^ encoded_bits[5] ^ encoded_bits[6];
    int p3 = encoded_bits[3] ^ encoded_bits[4] ^ encoded_bits[5] ^ encoded_bits[6];
    int p4 = encoded_bits[7] ^ encoded_bits[0] ^ encoded_bits[1] ^ encoded_bits[2] ^ encoded_bits[3] ^ encoded_bits[4] ^ encoded_bits[5] ^ encoded_bits[6];
    
    int error_position = p1 + (p2 << 1) + (p3 << 2) + (p4 << 3);
    
    if (error_position == 0) {
        return {0, {encoded_bits[2], encoded_bits[4], encoded_bits[5], encoded_bits[6]}}; 
    } else if (error_position > 8) {
        return {-1, {encoded_bits[2], encoded_bits[4], encoded_bits[5], encoded_bits[6]}}; 
    } else {
        encoded_bits[error_position - 1] ^= 1; 
    }
    
    std::vector<int> data_bits = {encoded_bits[2], encoded_bits[4], encoded_bits[5], encoded_bits[6]};
    return {error_position, data_bits};
}
