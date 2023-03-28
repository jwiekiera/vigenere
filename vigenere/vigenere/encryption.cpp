#include "encryption.h"

constexpr
int alphabet()
{
    return 'z' - 'a' + 1;
}

std::string encryption(const std::string& text, const std::string& key)
{
    //std::vector<double> czesto = zliczanie_czestotliwosci(text, 1, 0);
    std::string ciphertext = "";
    const std::string fixed_key = fix_text(key);
    const std::size_t key_length = fixed_key.length();
    const std::size_t text_length = text.length();
    int key_index = 0;
    std::vector<int> vector_of_shift = vector_with_shifts(fixed_key);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            ciphertext += character_shift(text[i], vector_of_shift[key_index]);
            key_index++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            ciphertext += character_shift(text[i], vector_of_shift[key_index]);
            key_index++;
        }
        else
        {
            ciphertext += text[i];
        }
        key_index %= key_length;
    }
    return ciphertext;
}

char character_shift(const char& my_char, int& shift)
{
    if (my_char >= 'a' && my_char <= 'z')
    {
        if (my_char + shift > 'z')
        {
            return my_char + shift - alphabet();
        }
        return my_char + shift;
    }
    else if (my_char >= 'A' && my_char <= 'Z')
    {
        if (my_char + shift > 'Z')
        {
            return my_char + shift - alphabet();
        }
        return my_char + shift;
    }
    return my_char;
}