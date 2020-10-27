#include <iostream>

using namespace std;

class motor
{
    public: char firstAlphabet[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
    public: char secondAlphabet[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
    public: char thirdAlphabet[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
    public: char reverseAlphabet[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };

    private: char* standardAlphabet(int start)
    {
        char arr[26];
        for (int i = 'A'; i <= 'Z'; i++)
        {
            int letter = i + start;
            while (letter < 'A' || 'Z' < letter)
            {
                if (letter < 'A')
                    letter += 26;
                else
                    letter -= 26;
            }
            arr[i - 'A'] = letter;
        } 
        return arr;
    }

    public: char cipherChar(char c, int alphabetStart)
    {
        
    }
};

int main()
{
    motor x = motor();
}