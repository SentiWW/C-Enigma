#include <iostream>
#include <string>

using namespace std;

class motor
{
    public: char cipherChar(char c, char* alphabetTo, int iNum)
    {
        return alphabetTo[indexOf(c, alphabet(iNum))];
    }

    private: int indexOf(char c, char* arr)
    {
        for (int i = 0; i < 26; i++)
        {
#if DEBUG
            cout << i << " : " << arr[i] << endl;
#endif
            if (arr[i] == c)
            {
#if DEBUG
                cout << c << " at index " << i;
#endif
                return i;
            }
        }
            
#if DEBUG
        cout << "????";
#endif
        return -1;
    }
    private: char* alphabet(int start)
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
    
    #if DEBUG
        for (char c : arr)
            cout << c << " ";
        cout << endl;
    #endif
    
        return arr;
    }
};

class enigma
{
    private: char firstAlphabet[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
    private: char secondAlphabet[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
    private: char thirdAlphabet[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
    private: char reverseAlphabet[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };
    private: char testAlphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I','J','K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    motor motors = motor();

    public: string cipher(string text)
    {
        char temp;
        string result = "";
        for (int i = 0; i < text.length(); i++)
        {
            temp = motors.cipherChar(text[i], secondAlphabet, i);
            //temp = motors.cipherChar(temp, firstAlphabet, i);
            //temp = motors.cipherChar(temp, reverseAlphabet, i);
            //temp = motors.cipherChar(temp, firstAlphabet, i);
            //temp = motors.cipherChar(temp, secondAlphabet, i);
            //temp = motors.cipherChar(temp, thirdAlphabet, i);
            //temp = motors.cipherChar(temp, testAlphabet, i);
            result += temp;
        }
        return result;
    }
};

int main()
{
    enigma e = enigma();
    cout << e.cipher("P");
    //cout << e.cipher("F");
}