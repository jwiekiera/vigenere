#include "decrypting.h"

constexpr
int alphabet()
{
    return 'z' - 'a' + 1;
}

std::string decrypting(const std::string& ciphertext, const std::string& key)
{
    std::string text = "";
    std::string fixed_key = fix_text(key);

    const std::size_t key_length = fixed_key.length();
    int key_index = 0;

    std::vector<int> vector_of_shift = vector_with_shifts(fixed_key);

    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            text += character_shift_decryting(ciphertext[i], vector_of_shift[key_index]);
            key_index++;
        }
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
        {
            text += character_shift_decryting(ciphertext[i], vector_of_shift[key_index]);
            key_index++;
        }
        else
        {
            text += ciphertext[i];
        }
        key_index %= key_length;
    }
    return text;
}

char character_shift_decryting(const char& my_char, int& shift)
{
    if (my_char >= 'a' && my_char <= 'z')
    {
        if (my_char - shift < 'a')
        {
            return my_char - shift + alphabet();
        }
        return my_char - shift;
    }
    else if (my_char >= 'A' && my_char <= 'Z')
    {
        if (my_char - shift < 'A')
        {
            return my_char - shift + alphabet();
        }
        return my_char - shift;
    }
    return my_char;
}