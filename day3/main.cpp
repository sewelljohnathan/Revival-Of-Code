
#include <fstream>
#include <iostream>
#include <vector>

int main(void) 
{
    std::ifstream inFile("question.in");

    int count = 0;

    std::vector<int> nums;
    std::string s;
    while (inFile >> s) 
    {
        nums.push_back(std::stoi(s));
    }

    for (int i = 0; i < nums.size() - 6; i += 9) {

        for (int j = i; j < i + 3; j++) 
        {
            int a = nums.at(j), b = nums.at(j + 3), c = nums.at(j + 6);
            count += (a + b > c && a + c > b && b + c > a);
        }
        
    }

    std::cout << count << std::endl;

}
