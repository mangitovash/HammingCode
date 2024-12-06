#include "HammingCode.h"

int main() {
    std::vector<int> data_bits(4);

    std::cout << "Enter 4 data bits (as 1 0 1 1): ";
    for (int& bit : data_bits) {
        std::cin >> bit;
        while (bit != 0 && bit != 1) {
            std::cout << "Invalid input. Please enter 0 or 1." << std::endl;
            std::cin >> bit;
        }
    }

    std::vector<int> encoded_message = HammingCode::encode(data_bits);
    std::cout << "Correctly Formatted Encoded Message: ";
    for (int bit : encoded_message) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter the 8-bit encoded message (you can introduce an error if you like): ";
    for (int& bit : encoded_message) {
        std::cin >> bit;
        while (bit != 0 && bit != 1) {
            std::cout << "Invalid input. Please enter 0 or 1." << std::endl;
            std::cin >> bit;
        }
    }

    auto result = HammingCode::decode(encoded_message);
    int error_position = result.first;
    std::vector<int> corrected_data = result.second;

    if (error_position == -1) {
        std::cout << "Multiple errors detected. Correction is not possible." << std::endl;
    } else if (error_position == 0) {
        std::cout << "No error detected. Message is correct and error-free." << std::endl;
    } else {
        std::cout << "Error detected at position: " << error_position << std::endl;
        std::cout << "Corrected Encoded Message: ";
        for (int bit : encoded_message) {
            std::cout << bit << " ";
        }
        std::cout << std::endl;
        std::cout << "Decoded (and corrected) Message: ";
        for (int bit : corrected_data) {
            std::cout << bit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
