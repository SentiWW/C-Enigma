#include <string>
#include <iostream>
#include "Rotor.h"

using namespace std;

Rotor::Rotor() { }

Rotor::Rotor(char rotorAlphabet[26], bool isFirst)
{
	this->rotorAlphabet = rotorAlphabet;
	this->isFirst = isFirst;
}

char Rotor::cipherChar(char letter, unsigned int charI)
{
	char result;

	if (!isFirst)
	{
		if (!reversing)
			result = rotorAlphabet[indexOf(letter, standardAlphabet(0))];
		else
			result = standardAlphabet(0)[indexOf(letter, rotorAlphabet)];
	}
	else
	{
		if (!reversing)
			result = rotorAlphabet[indexOf(letter, standardAlphabet(charI))];
		else
			result = standardAlphabet(charI)[indexOf(letter, rotorAlphabet)];
	}

	reversing = reversing ? false : true;

	return result;
}

string Rotor::standardAlphabet(unsigned int start)
{
	string result = "";
	start %= 26;

	for (unsigned short i = 'A'; i <= 'Z'; i++)
	{
		unsigned int letter = i + start;
		while (letter < 'A' || 'Z' < letter)
			if (letter < 'A')
				letter += 26;
			else
				letter -= 26;
		result += letter;
	}

	return result;
}

short Rotor::indexOf(char letter, string alphabet)
{
	for (unsigned short i = 0; i < alphabet.length(); i++)
		if (letter == alphabet[i])
			return i;

	throw runtime_error("Index not of "+to_string(letter) +" found in supplied alphabet");
}