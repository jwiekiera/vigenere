#include <iostream>

#include "file.h"
#include "encryption.h"
#include "decrypting.h"
#include "cryptanalysis.h"


int main()
{
	{
		const std::string text = file_input("../texts/hamlet.txt"); //load text
		const std::string key = file_input("../texts/key.txt"); //load key
		std::string encrypted = encryption(text, key); 
		file_output(encrypted, "../texts/encrypted.txt");
	}
	{
		const std::string ciphertext = file_input("../texts/encrypted.txt"); //load text
		const std::string key = file_input("../texts/key.txt"); //load key
		std::string descrypted = decrypting(ciphertext, key);
		file_output(descrypted, "../texts/descrypted.txt");
	}
	{
		const std::string ciphertext = file_input("../texts/encrypted.txt");
		std::string descrypted = cryptanalysis(ciphertext);
		file_output(descrypted, "../texts/cryptanalysis_result.txt");
	}

	return 0;
}