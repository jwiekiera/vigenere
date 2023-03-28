#include "functions.h"


std::string fix_text(const std::string& text)
{
    std::string fixed_text = "";
    for (int i = 0; i < text.length(); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            fixed_text += text[i];
        }
    }
    return fixed_text;
}

std::vector<int> vector_with_shifts(const std::string& key)
{
    std::vector<int> vector;
    const std::size_t key_length = key.length();
    for (int i = 0; i < key_length; i++)
    {
        int shift = shift_values(key[i]);
        if (shift != -1)
        {
            vector.push_back(shift);
        }
    }
    return vector;
}



int shift_values(const char& my_char)
{
    if (my_char >= 'a' && my_char <= 'z')
    {
        return int(my_char - 'a');
    }
    else if (my_char >= 'A' && my_char <= 'Z')
    {
        return int(my_char - 'A');
    }
    return -1;
}
