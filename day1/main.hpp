
enum Direction 
{ 
    FIRST_DIRECTION = 0,
    NORTH = FIRST_DIRECTION, 
    EAST, 
    SOUTH, 
    WEST, 
    LAST_DIRECTION
};
Direction operator++(Direction& dir) 
{
    dir = static_cast<Direction>((static_cast<int>(dir) + 1) % static_cast<int>(LAST_DIRECTION));
    return dir;
}
Direction operator--(Direction& dir) 
{
    dir = static_cast<Direction>((static_cast<int>(dir) - 1 + static_cast<int>(LAST_DIRECTION)) % static_cast<int>(LAST_DIRECTION));
    return dir;
}