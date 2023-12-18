#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Shifr
{
public:
    Shifr(int columns);
    std::wstring encrypt(const std::wstring& plaintext);
    std::wstring decrypt(const std::wstring& ciphertext);
    int getValidKey(int key);
    std::wstring getValidOpenText(const std::wstring &s);
    std::wstring getValidCipherText(const std::wstring &s);
private:
    int key;
};

class cipher_error : public std::invalid_argument
{
public:
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};
