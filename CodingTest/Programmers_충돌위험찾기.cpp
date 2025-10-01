#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    int x = routes.size();
    vector<tuple<int, int, int>> BotPos;
    BotPos.reserve(x);
    for (const auto& route : routes)
    {
        int First = route[0] - 1;
        BotPos.emplace_back(1, points[First][0], points[First][1]);
    }


    // �浹ó��
    vector<vector<char>> Board(101, vector<char>(101, 0));
    for (const auto& [RouteNum, BotX, BotY] : BotPos)
    {

        if (++Board[BotY][BotX] == 2)
        {
            answer++;
            //cout << BotX << ", " << BotY << "@";
        }
    }

    int BotCount = x;
    while (BotCount > 0)
    {
        vector<tuple<int, int>> BotCollision;
        // ��� ��Ʈ ����
        for (int i = 0; i < x; ++i)
        {
            auto& [RouteNum, BotX, BotY] = BotPos[i];
            // ���� �̹� ��������� pass
            if (RouteNum >= routes[i].size())
                continue;

            int ToX = points[routes[i][RouteNum] - 1][0];
            int ToY = points[routes[i][RouteNum] - 1][1];

            // // ���� �̹� ��������� pass
            // if(BotX == ToX && BotY == ToY)
            //     continue;

            if (BotX != ToX)
            {
                bool IsGoLeft = BotX > ToX;
                IsGoLeft ? (BotX--) : (BotX++);
            }
            else
            {
                bool IsGoUp = BotY > ToY;
                IsGoUp ? (BotY--) : (BotY++);
            }

            // ���ο� ��ġ�� �浹ó�� �غ�
            BotCollision.emplace_back(BotX, BotY);

            if (BotX == ToX && BotY == ToY)
            {
                if (++RouteNum >= routes[i].size())
                    BotCount--;
            }
        }

        //cout <<"//";
        //for(const auto& [RouteNum, BotX, BotY] : BotPos)
        //    cout << BotX << ", " << BotY << "@";
        //cout <<"//    ";

    // �浹ó��
        vector<vector<char>> Board(101, vector<char>(101, 0));
        for (const auto& [BotX, BotY] : BotCollision)
        {

            if (++Board[BotY][BotX] == 2)
            {
                answer++;
                //cout << BotX << ", " << BotY << "@";
            }
        }
    }

    return answer;
}