#ifndef HAMMING_CODE_H
#define HAMMING_CODE_H

#include <vector>
#include <iostream>
#include <vector>

class HammingCode {
public:
    static std::vector<int> encode(const std::vector<int>& data_bits);
    static std::pair<int, std::vector<int>> decode(std::vector<int>& encoded_bits);
};

#endif // HAMMING_CODE_H
