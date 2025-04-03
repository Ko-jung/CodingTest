#include <iostream>
#include <string>
#include <vector>

class POS
{
public:
    POS() : X(0), Y(0) {}
    POS(int x, int y) : X(x), Y(y) {}

    int X;
    int Y;
    POS operator+(const POS& r)
    {
        return {this->X + r.X, this->Y + r.Y};
    }
    POS operator-(const POS& r)
    {
        return { this->X - r.X, this->Y - r.Y };
    }
    bool operator==(POS& r)
    {
        return (this->X == r.X && this->Y == r.Y);
    }
};

bool BoardCheck(POS pos)
{
    if (pos.X < 1 || pos.X >= 9 ||
        pos.Y < 1 || pos.Y >= 9)
        return false;
    return true;
}

int main()
{
    char a, b;
    int p, q;
    int MoveCount;
    std::cin >> a >> p >>
        b >> q >>
        MoveCount;

    POS KingPos = { a - 'A' + 1, p };
    POS RockPos = { b - 'A' + 1, q };
    std::vector<std::string> Move;
    for (int i = 0; i < MoveCount; i++)
    {
        std::string Temp;
        std::cin >> Temp;
        Move.emplace_back(Temp);
    }

    for (const auto& m : Move)
    {
        //int Direction = 0;
        POS Direction;
        for (const auto& c : m)
        {
            if (c == 'R') Direction.X = 1;
            else if (c == 'L') Direction.X = -1;
            if (c == 'B') Direction.Y = -1;
            else if (c == 'T') Direction.Y = 1;
        }

        //std::cout << "Direction = { " << Direction.first << ", " << Direction.second << "}" << std::endl;

        POS NewKingPos = KingPos + Direction;
        if (!BoardCheck(NewKingPos)) continue;

        if (NewKingPos == RockPos)
        {
            POS NewRockPos = RockPos + Direction;
            if (BoardCheck(NewRockPos))
            {
                KingPos = RockPos;
                RockPos = NewRockPos;
            }
        }
        else
        {
            KingPos = KingPos + Direction;
        }
    }
    std::cout << (char)(KingPos.X + 'A' - 1) << KingPos.Y << std::endl <<
        (char)(RockPos.X + 'A' - 1) << RockPos.Y << std::endl;
}