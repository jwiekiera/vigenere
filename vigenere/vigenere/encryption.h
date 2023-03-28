#pragma once
#include <vector>
#include <string>
#include "functions.h"

/** The function encrypts the text
 * @param string text
 * @param string key 
 * @return string ciphertext
 */
std::string encryption(const std::string& , const std::string& );

/** The function shifts char from text (as with a Caesar cipher)
 * @param char shifted char
 * @param int shift - how many number of place char will be shift
 * @return shifted char
 */
char character_shift(const char&, int&);

