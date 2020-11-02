#include <iostream>
#include <string>

using namespace std;

class rotor
{
	private: char* rotorAlphabet;

	public: rotor() { }

	public: rotor(char rotorAlphabet[26])
	{
		this->rotorAlphabet = rotorAlphabet;
	}

	public: char cipherChar(char letter, unsigned int charI)
	{
		return rotorAlphabet[standardAlphabet(charI)[letter - 'A'] - 'A'];
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
};

class enigma
{
	private: rotor rotor1;
	private: rotor rotor2;
	private: rotor rotor3;
	private: rotor rotorR;

	public: enigma(rotor rotor1, rotor rotor2, rotor rotor3, rotor rotorR)
	{
		this->rotor1 = rotor1;
		this->rotor2 = rotor2;
		this->rotor3 = rotor3;
		this->rotorR = rotorR;
	}

	public: char cipher(string text)
	{
		/*string result = "";
		
		for (unsigned int i = 0; i < text.length(); i++)
		{
			
		}

		return result;*/

		return rotor3.cipherChar('R', 1);
	}
};

int main()
{
	char alphabet3[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
	char alphabet2[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
	char alphabet1[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
	char alphabetR[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };

	enigma e = enigma(rotor(alphabet1),
					  rotor(alphabet2),
					  rotor(alphabet3),
					  rotor(alphabetR));
	
	cout << e.cipher("PROGRAMOWANIE") << endl;
}