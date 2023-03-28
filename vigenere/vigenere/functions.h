#pragma once
#include <vector>
#include <string>

/** The function removes all special characters from the text
 * @param string text
 * @return string fixed_text
 */
std::string fix_text(const std::string&);

/** The function creates vectors that contain integers which represents shift values (eg. a - 0, b - 1,..., z - 25 and A - 0, B - 1,..., Z - 25)
 * @param string key
 * @return vector<int> vector with integers which shift text
 */
std::vector<int> vector_with_shifts(const std::string&);

/** The function returns shift values (eg. a - 0, b - 1,..., z - 25 and A - 0, B - 1,..., Z - 25)
 * @param char from key
 * @return int shift values
 */
int shift_values(const char&);

