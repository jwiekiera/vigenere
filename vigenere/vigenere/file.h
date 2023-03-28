#pragma once

#include <iostream>
#include <fstream>
#include <string>


/** The function downloads text from file
 * @param string FILE_NAME name of file
 * @return text (text, key or ciphertext)
 */
std::string file_input(const std::string& );


/** The function uploads text to file
 * @param string text (text, key or ciphertext) to upload
 * @param string FILE_NAME name of file
 */
void file_output(const std::string& , const std::string& );