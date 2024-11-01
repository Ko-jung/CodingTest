// https://school.programmers.co.kr/learn/courses/30/lessons/250136

// 효율성 통과를 위해선 석유 덩어리에 번호를 매겨보자


#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> Direction = { {1,0},{0,1}, {-1,0}, {0,-1}};
vector<vector<int>> DP;

void DFS(int x, int y, int& Count, vector<vector<int>>& land)
{
    Count++;
    land[y][x] = 0;
    for (const auto& d : Direction)
    {
        int NewX = x + d.first;
        int NewY = y + d.second;
        if (NewX < 0 || NewY < 0 || NewX >= land[0].size() || NewY >= land.size() || land[NewY][NewX] != 1) continue;

        DFS(NewX, NewY, Count, land);
    }

    DP[y][x] = max(Count, DP[y][x]);
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    DP.assign(land.size(), vector<int>(land[0].size(), 0));

    for (int j = 0; j < land[0].size(); j++)
    {
        int Count{ 0 };
        vector<vector<int>> TempLand = land;
        for (int i = 0; i < land.size(); i++)
        {
            if (TempLand[i][j])
                DFS(j, i, Count, TempLand);
        }
        answer = max(Count, answer);
    }
    return answer;
}

int main()
{
    solution({{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}} );
    solution({{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}} );
}