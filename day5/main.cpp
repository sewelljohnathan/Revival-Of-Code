
#include <iostream>

#include "md5.hpp"


int main(void)
{

    std::string base = "ojvtpuvg";
    char password[8] = {0};
    for (int i = 0; i < 8; i++) std::cout << (int) password[i] << std::endl;

    int index = 0;
    int foundCount = 0;
    while (foundCount < 8)
    {
        std::string hash = md5(base + std::to_string(index++));
        if (hash.substr(0, 5) == "00000")
        {
            int pos = hash[5] - '0';
            if (0 <= pos && pos <= 7 && password[pos] == 0)
            {
                password[pos] = hash[6];
                foundCount++;
            }
        }
    }

    std::cout << password << std::endl;
    return 0;
}
