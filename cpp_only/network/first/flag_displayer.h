#ifndef FLAG_DISPLAYER_H
#define FLAG_DISPLAYER_H

// Function prototype
void asio_nsense();
// RC4 Encryption/Decryption function
void rc4(const std::string& key, const std::string& input, std::string& output);
std::string hex_to_bytes(const std::string& hex);
int binarySearchAtStep(const std::vector<std::string>& vec, int steps);


#endif // FLAG_DISPLAYER_H
