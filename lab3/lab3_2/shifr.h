#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <codecvt>
#include <algorithm>

class shifr
{
private:
    int newkey;
    
public:
    int getValidKey(int &s);
    int getValidKeyText(int key, std::string &text);
    std::string getValidOpenText(std::string &s);
    shifr ()=delete;
    shifr(const int& key, std::string) :newkey(key) {};   
    std::string encrypt(const std::string& user_str);  
    std::string decrypt(const std::string& user_str); 
};

class cipher_error: public std::invalid_argument {
    public:
        explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
        explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
