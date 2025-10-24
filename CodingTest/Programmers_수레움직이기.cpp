#include <iostream>
#include <string>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> Move = {
    {+1,+0},
    {-1,+0},
    {+0,+1},
    {+0,-1}
};
bool EndR = false;
bool EndB = false;

struct Point {
    int x;
    int y;
};

bool Check(const Point& R, const Point& B, const Point& PrevR, const Point& PrevB,
    const vector<vector<bool>>& RVisited, const vector<vector<bool>>& BVisited,
    const vector<vector<int>>& maze)
{
    if (R.x < 0 || R.x >= M || R.y < 0 || R.y >= N ||
        B.x < 0 || B.x >= M || B.y < 0 || B.y >= N ||
        (!EndR && RVisited[R.y][R.x]) || (!EndB && BVisited[B.y][B.x]) ||
        maze[R.y][R.x] == 5 || maze[B.y][B.x] == 5)
        return false;

    if (R.x == B.x && R.y == B.y)
        return false;
    if ((R.x == PrevB.x && R.y == PrevB.y) &&
        (PrevR.x == B.x && PrevR.y == B.y))
        return false;

    return true;
}

int BackTracking(Point R, Point B, vector<vector<bool>> RVisited, vector<vector<bool>> BVisited,
    const vector<vector<int>>& maze, int Result)
{
    if (EndR && EndB) return Result;
    int Answer = 9999;

    for (int i = 0; i < 4; ++i)
    {
        Point TempR = R;
        if (!EndR)
        {
            TempR.x += Move[i][0];
            TempR.y += Move[i][1];
        }
        for (int j = 0; j < 4; ++j)
        {
            Point TempB = B;
            if (!EndB)
            {
                TempB.x += Move[j][0];
                TempB.y += Move[j][1];
            }

            if (!Check(TempR, TempB, R, B, RVisited, BVisited, maze)) continue;

            RVisited[TempR.y][TempR.x] = true;
            BVisited[TempB.y][TempB.x] = true;
            if (maze[TempR.y][TempR.x] == 3) EndR = true;
            if (maze[TempB.y][TempB.x] == 4) EndB = true;

            Answer = min(Answer, BackTracking(TempR, TempB, RVisited, BVisited,
                maze, Result + 1));
            RVisited[TempR.y][TempR.x] = false;
            BVisited[TempB.y][TempB.x] = false;
            EndR = false;
            EndB = false;
        }
    }

    return Answer;
}

int solution(vector<vector<int>> maze) {
    EndR = false;
    EndB = false;

    int answer = 0;

    M = maze[0].size();
    N = maze.size();

    Point Red;
    Point Blue;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == 1)
            {
                Red.x = j;
                Red.y = i;
            }
            if (maze[i][j] == 2)
            {
                Blue.x = j;
                Blue.y = i;
            }
        }

    vector<vector<bool>> RVisited(N, vector<bool>(M, false));
    RVisited[Red.y][Red.x] = true;
    vector<vector<bool>> BVisited(N, vector<bool>(M, false));
    BVisited[Blue.y][Blue.x] = true;
    answer = BackTracking(Red, Blue, RVisited, BVisited, maze, 0);

    if (answer == 9999) answer = 0;

    return answer;
}

int main()
{
    cout << solution({{1, 4}, {0, 0}, {2, 3}}) << endl;
    cout << solution({{1, 0, 2}, {0, 0, 0}, {5, 0, 5}, {4, 0, 3}}) << endl;
    cout << solution({{1, 5}, {2, 5}, {4, 5}, {3, 5}}) << endl;
    cout << solution({{4, 1, 2, 3}}) << endl;
}