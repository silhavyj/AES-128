#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <cstring>

#include "AES.h"
#include "tables.h"

int main(int argc, char *argv[]) {
    if (argc != 8) {
        std::cout << "invalid number of parameters\n";
        std::cout << "./aes -<e/d> -in <input_file> -out <output_file> -key <key>\n";
        return 1;
    }

    std::string inputFile  = "UNKNOWN";
    std::string outputFile = "UNKNOWN";
    std::string key        = "UNKNOWN";
    bool encrypt           = true;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0)
            encrypt = true;
        else if (strcmp(argv[i], "-d") == 0)
            encrypt = false;
        else if (strcmp(argv[i], "-in") == 0)
            inputFile = std::string(argv[++i]);
        else if (strcmp(argv[i], "-out") == 0)
            outputFile = std::string(argv[++i]);
        else if (strcmp(argv[i], "-key") == 0)
            key = std::string(argv[++i]);
    }

    AES aes;
    std::ifstream input(inputFile, std::ios::binary);
    if (input.fail()) {
        std::cout << "file not found\n";
        return 1;
    }
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(input), {});
    input.close();

    std::vector<uint8_t> data;
    if (encrypt)
        data = aes.encrypt(buffer, std::vector<uint8_t>(key.begin(), key.end()));
    else 
        data = aes.decrypt(buffer, std::vector<uint8_t>(key.begin(), key.end()));

    std::ofstream output(outputFile, std::ios::binary);
    output.write((const char *)&data[0], data.size());
    output.close();

    return 0;
}