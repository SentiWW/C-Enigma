#include <iostream>
#include <string>

using namespace std;

class motor
{
    public: char cipherChar(char c, char* alphabet0, char* alphabet1)
    {
        return alphabet1[indexOf(c, alphabet0)];
    }

    private: int indexOf(char c, char* arr)
    {
        for (int i = 0; i < 26; i++)
            if (arr[i] == c)
                return i;

        return -1;
    }
};

class enigma
{
    private: char firstAlphabet[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
    private: char secondAlphabet[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
    private: char thirdAlphabet[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
    private: char reverseAlphabet[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };
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

    motor third = motor();
    motor second = motor();
    motor first = motor();
    motor reverse = motor();

    public: string cipher(string text)
    {
        char temp;
        string result = "";
        for (int i = 0; i < text.length(); i++)
        {
            temp = third.cipherChar(text[i], standardAlphabet(i), thirdAlphabet);
            temp = second.cipherChar(temp, thirdAlphabet, secondAlphabet);
            //temp = first.cipherChar(temp, secondAlphabet, firstAlphabet);
            //temp = reverse.cipherChar(temp, firstAlphabet, reverseAlphabet);
            //temp = reverse.cipherChar(temp, reverseAlphabet, firstAlphabet);
            //temp = first.cipherChar(temp, firstAlphabet, secondAlphabet);
            //temp = first.cipherChar(temp, secondAlphabet, thirdAlphabet);
            //temp = first.cipherChar(temp, thirdAlphabet, standardAlphabet(i));
            result += temp;
        }
        return result;
    }
};

int main()
{
    enigma e = enigma();
    cout << e.cipher("PROGRAMOWANIE");
}