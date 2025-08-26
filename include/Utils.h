#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// takes file convert it to string and return it
std::string readfile(const std::string& filename);

// takes string split it on any space or , then return it in a vector
std::vector<std::string> tokenization(const std::string& text);

std:: string Cleanword(const std:: string& word);

#endif // UTILS_H
