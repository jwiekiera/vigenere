#include "file.h"

std::string file_input(const std::string& FILE_NAME)
{
    std::string text;
    std::ifstream file(FILE_NAME);

    std::string line;
    while (std::getline(file, line))
    {
        text = text + line + "\n";
    }
    return text;
}

void file_output(const std::string& text, const std::string& FILE_NAME)
{
    std::ofstream file(FILE_NAME);
    if (file)
    {
        for (int i = 0; i < text.length(); i++)
        {
            file << text[i];
        }
    }
}