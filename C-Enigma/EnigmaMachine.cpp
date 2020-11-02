#include <iostream>
#include <string>
#include "Rotor.h"
#include "EnigmaMachine.h"

using namespace std;
	
EnigmaMachine::EnigmaMachine(Rotor rotor3, Rotor rotor2, Rotor rotor1, Rotor rotorR)
	{
		this->rotor3 = rotor3;
		this->rotor2 = rotor2;
		this->rotor1 = rotor1;
		this->rotorR = rotorR;
	}

string EnigmaMachine::cipher(string text)
{
	string result = "";
	char temp;

	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
		{
			result += ' ';
			continue;
		}

		temp = rotor3.cipherChar(text[i], i);
		temp = rotor2.cipherChar(temp, i);
		temp = rotor1.cipherChar(temp, i);
		temp = rotorR.cipherChar(temp, i);
		temp = rotor1.cipherChar(temp, i);
		temp = rotor2.cipherChar(temp, i);
		temp = rotor3.cipherChar(temp, i);
		result += temp;
	}

	return result;
}