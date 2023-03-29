#include <iostream>

#include "file.h"
#include "encryption.h"
#include "decrypting.h"
#include "cryptanalysis.h"


int main()
{
	{
		const std::string text = file_input("../texts/encryption/text.txt"); //load text
		const std::string key = file_input("../texts/encryption/key.txt"); //load key
		std::string encrypted = encryption(text, key); 
		file_output(encrypted, "../texts/encryption/encryption_result.txt");
	}
	{
		const std::string ciphertext = file_input("../texts/decrypting/ciphertext.txt"); //load text
		const std::string key = file_input("../texts/decrypting/key.txt"); //load key
		std::string descrypted = decrypting(ciphertext, key);
		file_output(descrypted, "../texts/decrypting/descrypting_result.txt");
	}
	{
		const std::string ciphertext = file_input("../texts/cryptanalysis/ciphertext.txt"); //load text
		std::string descrypted = cryptanalysis(ciphertext);
		file_output(descrypted, "../texts/cryptanalysis/cryptanalysis_result.txt");
	}

	return 0;
}