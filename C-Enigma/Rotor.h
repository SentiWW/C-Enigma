#pragma once
#ifndef ROTOR_H
#define ROTOR_H
#include <string>

using namespace std;

class Rotor
{
	private: 
		char* rotorAlphabet;
		bool isFirst = false;
		static string standardAlphabet(unsigned int start);
		static short indexOf(char letter, string alphabet);

	public: 
		bool reversing = false;
		Rotor();
		Rotor(char rotorAlphabet[26], bool isFirst = false);
		char cipherChar(char letter, unsigned int charI);
};
#endif