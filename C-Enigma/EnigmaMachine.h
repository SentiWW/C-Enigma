#pragma once
#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H
#include <string>
#include "Rotor.h"

class EnigmaMachine
{
	private: 
		Rotor rotor1;
		Rotor rotor2;
		Rotor rotor3;
		Rotor rotorR;
	
	public: 
		EnigmaMachine(Rotor rotor3, Rotor rotor2, Rotor rotor1, Rotor rotorR);
		string cipher(string text);
};
#endif