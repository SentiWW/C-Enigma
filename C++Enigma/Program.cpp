#include <iostream>
#include <string>

using namespace std;

class rotor
{
	private: char* rotorAlphabet;
	private: bool isFirst;

	public: rotor() { }

	public: rotor(char rotorAlphabet[26], bool isFirst)
	{
		this->rotorAlphabet = rotorAlphabet;
		this->isFirst = isFirst;
	}

	public: char cipherChar(char letter, unsigned int charI, bool reversing)
	{
		char result;

		if (isFirst && !reversing)
			result = rotorAlphabet[indexOf(letter, standardAlphabet(charI))];
		else if (isFirst && reversing)
			result = standardAlphabet(charI)[indexOf(letter, rotorAlphabet)];
		else
		{
			if (!reversing)
				result = rotorAlphabet[indexOf(letter, standardAlphabet(0))];
			else
				result = standardAlphabet(0)[indexOf(letter, rotorAlphabet)];
		}
		return result;
	}

	private: static string standardAlphabet(unsigned int start)
	{
		string result = "";
		start %= 26;

		for (unsigned short i = 'A'; i <= 'Z'; i++)
		{
			short letter = i + start;
			while (letter < 'A' || 'Z' < letter)
				if (letter < 'A')
					letter += 26;
				else
					letter -= 26;
			result += letter;
		}
			
		return result;
	}

	private: static short indexOf(char letter, string alphabet)
	{
		for (unsigned short i = 0; i < alphabet.length(); i++)
			if (letter == alphabet[i])
				return i;
		return -1;
	}
};

class enigma
{
	private: rotor rotor1;
	private: rotor rotor2;
	private: rotor rotor3;
	private: rotor rotorR;

	public: enigma(rotor rotor3, rotor rotor2, rotor rotor1, rotor rotorR)
	{
		this->rotor3 = rotor3;
		this->rotor2 = rotor2;
		this->rotor1 = rotor1;
		this->rotorR = rotorR;
	}

	public: string cipher(string text)
	{
		string result = "";
		char temp;

		for (unsigned int i = 0; i < text.length(); i++)
		{
			temp = rotor3.cipherChar(text[i], i, false);
			temp = rotor2.cipherChar(temp, i, false);
			temp = rotor1.cipherChar(temp, i, false);
			temp = rotorR.cipherChar(temp, i, false);
			temp = rotor1.cipherChar(temp, i, true);
			temp = rotor2.cipherChar(temp, i, true);
			temp = rotor3.cipherChar(temp, i, true);
			result += temp;
		}

		return result;
	}
};

int main()
{
	char alphabet3[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
	char alphabet2[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
	char alphabet1[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
	char alphabetR[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };

	enigma e = enigma(rotor(alphabet3, true),
					  rotor(alphabet2, false),
					  rotor(alphabet1, false),
					  rotor(alphabetR, false));
	
	cout << e.cipher("TEST") << endl;
}