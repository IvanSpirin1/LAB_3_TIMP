#include "shifr.h"

int shifr::getValidKey(int &key){
    if (key < 2){
        throw cipher_error("Negative key");
    }
    return key;
}
std::string shifr::getValidOpenText(std::string &s)
{
    std::string tmp;
    for(auto c:s){
        if (isalpha(c))
        {
           if (isupper(c))
                tmp.push_back(c);
            else
                tmp.push_back(c);
        }
        
    }
        if (tmp.empty())
        {
            throw cipher_error("Empty open text");
        }
        
    return tmp;
}
int shifr::getValidKeyText(int key, std::string &text){
    if(key > int(text.length())){
        throw cipher_error("The key is bigger than the text");
    }
    return 0;
}
std::string shifr::encrypt(const std::string& user_str) 
{
    std::string new_str = user_str;
    int length, line_count, position, i; 
    length = user_str.size(); 
    line_count = (length - 1) / newkey + 1; 
    i = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line_count; line_number++) { 
            position = newkey*line_number+colum_number; 
            if (position-1<length){
            new_str[position-1] = user_str[i];
            i++;
            }
        }
    }
    return new_str;
}
std::string shifr::decrypt(const std::string& user_str) 
{
    std::string new_str = user_str;
    int length, line_count, position, i; 
    length = user_str.size(); 
    line_count = (length - 1) / newkey + 1; 
    i = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line_count; line_number++) { 
            position = colum_number+newkey*line_number;
            if (position-1<length){
            new_str[i] = user_str[position-1];
            i++;
            }
        }
    }
    return new_str;
}
