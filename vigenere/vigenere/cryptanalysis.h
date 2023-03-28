#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "functions.h"
#include "decrypting.h"
#include "file.h"

/** The function cryptanalys text 
 * @param string ciphertext  
 * @return string text
 */
std::string cryptanalysis(const std::string& );

/** The function returns a vector containing the frequency of the letters in the text
 * @param string text - analyzed text
 * @param int text_length - which chars are counted (eq. text_length == 1 - each char, text_length == 2 - every second sign,..., text_length == n - every n sign)
 * @param int start_index 
 * @return vector<double> frequency vector*/
std::vector<double> frequency_vector(const std::string& , const int& , const int& );


/** The function shifts the examined frequency vector and checks whether it fit with the model vector
 * @param vector<double> vector_ciphertext - examined frequency vector
 * @param vector<double> example_vector - model vector
 * @return bool if key was found (0 - not found, 1 - found)
 */
int finding_key(const std::vector<double>& , const std::vector<double>& );


/** The function compares the frequency of the letters of the alphabet in the given text with those in English
 * @param vector<double> vector_ciphertext - examined frequency vector
 * @param vector<double> example_vector -  frequency vector letters in English
 * @return bool if vectors fits (0 - not fit, 1 - fit)
 */
bool match_histograms(const std::vector<double>& , const std::vector<double>& );