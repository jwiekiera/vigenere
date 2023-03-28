#pragma once
#include <vector>
#include <string>
#include "functions.h"

/** The function decrypts the text
 * @param string ciphertext
 * @param string key
 * @return string decrypted text
 */
std::string decrypting(const std::string& , const std::string& );


/** The function shifts char from text (as with a Caesar cipher)
 * @param char shifted char
 * @param int shift - how many number of place char will be shift
 * @return shifted char
 */
char character_shift_decryting(const char&, int&);

