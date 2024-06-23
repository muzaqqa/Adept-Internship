#include <iostream>
#include <string>

unsigned int crc32(const std::string &data) {
    unsigned int crc = 0xFFFFFFFF;
    for (size_t i = 0; i < data.size(); ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }
    }
    return crc ^ 0xFFFFFFFF;
}

int main() {
    std::string input;
    std::cout << "Enter the input data: ";
    std::cin >> input;
    unsigned int checksum = crc32(input);
    std::cout << "CRC32 Checksum: " << std::hex << checksum << std::endl;
    return 0;
}
