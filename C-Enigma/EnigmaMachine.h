#pragma once
#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H
#include <string>
#include "Rotor.h"

class EnigmaMachine
{
	private: 
		Rotor rotor1, rotor2, rotor3, rotorR;
	
	public: 
		EnigmaMachine(Rotor rotor3, Rotor rotor2, Rotor rotor1, Rotor rotorR);
		string cipher(string text);
};
#endif