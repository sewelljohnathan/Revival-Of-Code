
const std::vector<std::vector<int>> pad = {
    {0, 0,  0,  0,  0, 0, 0},
    {0, 0,  0,  1,  0, 0, 0},
    {0, 0,  2,  3,  4, 0, 0},
    {0, 5,  6,  7,  8, 9, 0},
    {0, 0, 10, 11, 12, 0, 0},
    {0, 0,  0, 13,  0, 0, 0},
    {0, 0,  0,  0,  0, 0, 0},
};

constexpr char toHex(int val) {

    if (val >= 0 && val <= 9) 
    {
        return val + '0';
    }
    if (val >= 10 && val <= 14) 
    {
        return (val - 10) + 'A';
    }
    return -1;
}