#include "cryptanalysis.h"


constexpr
int alphabet()
{
    return 'z' - 'a' + 1;
}

std::string cryptanalysis(const std::string& ciphertext)
{
    std::string text = "";
    const std::string example_text = file_input("../texts/the-master-and-margarita.txt");
    std::vector<double> vector_example = frequency_vector(example_text, 1, 0);
    std::size_t ciphertext_length = ciphertext.length();
    std::vector<double> vector_of_shift;

    bool if_key_was_found = false;
    int key_length = 1;
    while (!if_key_was_found and key_length <= ciphertext_length) //dopóki nie odnaleziono klucza lub tekst siê nie skoñczy³
    {
        for (int i = 0; i < key_length; i++)
        {
            std::vector<double> vector_ciphertext = frequency_vector(ciphertext, key_length, i);
            int key = finding_key(vector_ciphertext, vector_example);
            if (key != -1)
            {
                vector_of_shift.push_back(key);
                if_key_was_found = true;
            }
        }
        key_length++;
    }
    if (!if_key_was_found)
    {
        return "Ket not found";
    }
    else
    {
        std::string key = "";
        for (int i = 0; i < vector_of_shift.size(); i++)
        {
            key += char('a' + vector_of_shift[i]);
        }
        return decrypting(ciphertext, key);
    }
}


std::vector<double> frequency_vector(const std::string& text, const int& text_length, const int& start_index)
{
    int char_array[alphabet()] = { 0 };
    int char_counter = 0;
    std::string new_text = fix_text(text);

    for (int i = start_index; i < new_text.length(); i++)
    {
        if ((i - start_index) % text_length == 0)
        {
            if (new_text[i] >= 'a' && new_text[i] <= 'z')
            {
                char_counter++;
                char_array[new_text[i] - 'a']++;
            }
            else if (new_text[i] >= 'A' && new_text[i] <= 'Z')
            {
                char_counter++;
                char_array[new_text[i] - 'A']++;
            }
        }
    }

    std::vector<double> freq_array;
    for (int i = 0; i < alphabet(); i++)
    {
        freq_array.push_back(1.0 * char_array[i] / char_counter);
    }

    return freq_array;
}


int finding_key(const std::vector<double>& vector_ciphertext, const std::vector<double>& example_vector)
{
    for (int i = 0; i < alphabet(); i++)
    {
        std::vector<double> analyzed_vector;

        for (int j = i; j < i + alphabet(); j++)
        {
            analyzed_vector.push_back(vector_ciphertext[j % alphabet()]);         //j % alfabet() -> 26 % 26 = 0 ("zapêtlenie" indeksu wektora)
        }
        if (match_histograms(analyzed_vector, example_vector))
        {
            return i;
        }
    }
    return -1;
}

bool match_histograms(const std::vector<double>& vector_ciphertext, const std::vector<double>& example_vector)
{
    double sum_of_differences = 0;
    for (int i = 0; i < alphabet(); i++)
    {
        double columns_differences = vector_ciphertext[i] - example_vector[i];
        sum_of_differences += pow(columns_differences, 2);
    }
    if (sum_of_differences < 0.001)   //gdy histogramy s¹ dopasowane, wartoœæ wyraŸnie spada (np. niedopasowane - 0.0630293, dopasowane - 0.000559347) 
    {
        return true;
    }
    return false;

}
