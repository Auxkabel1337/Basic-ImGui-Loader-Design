#include <iostream> 

class c_aesar {
public:
    static std::string encipher(std::string str, int shift)
    {
        std::string temp = str;
        int length;
        length = (int)temp.length();

        for (int i = 0; i < length; i++)
        {
            if (isalpha(temp[i]))
            {
                for (int j = 0; j < shift; j++)
                {
                    if (temp[i] == 'z')
                    {
                        temp[i] = 'a';
                    }
                    else if (temp[i] == 'Z')
                    {
                        temp[i] = 'A';
                    }
                    else
                    {
                        temp[i]++;
                    }
                }
            }
        }

        return temp;
    }

    static std::string decipher(std::string text, int s) {
        return encipher(text, 26 - s);
    }
};