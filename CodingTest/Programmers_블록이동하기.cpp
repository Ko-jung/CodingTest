#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <array>

using namespace std;

const static vector<std::array<int, 4>> Move = {
    // 이동
    std::array<int, 4>{1,0,1,0},
    std::array<int, 4>{-1,0,-1,0},
    std::array<int, 4>{0,1,0,1},
    std::array<int, 4>{0,-1,0,-1},
};
const static vector<std::array<int, 4>> HorizontalRot = {
    // 회전 (좌우 배치기준)
    std::array<int, 4>{0,0,-1, 1},
    std::array<int, 4>{0,0,-1,-1},
    std::array<int, 4>{1,1,0,  0},
    std::array<int, 4>{1,-1,0, 0},
};
const static vector<std::array<int, 4>> HorizontalCollide = {
    // 회전 (좌우 배치기준)
    std::array<int, 4>{0,0,0, 1},
    std::array<int, 4>{0,0,0,-1},
    std::array<int, 4>{0,1,0, 0},
    std::array<int, 4>{0,-1,0,0},
};
const static vector<std::array<int, 4>> VertialRot = {
    // 회전 (상하 배치기준)
    std::array<int, 4>{0,0,-1,-1},  // (0,0,-1,0) 검사
    std::array<int, 4>{0,0,-1,+1},  // (0,0,+1,0) 검사
    std::array<int, 4>{-1,+1,0,0},
    std::array<int, 4>{+1,+1,0,0},
};
const static vector<std::array<int, 4>> VertialCollide = {
    // 회전 (상하 배치기준)
    std::array<int, 4>{0,0,-1,0},  // (0,0,-1,0) 검사
    std::array<int, 4>{0,0,+1,0},  // (0,0,+1,0) 검사
    std::array<int, 4>{-1,0,0,0},
    std::array<int, 4>{+1,0,0,0},
};

struct Node
{
    pair<int, int> FirstPos;
    pair<int, int> SecondPos;
    int Time;
    bool IsVertial;
    Node() : FirstPos({ 0,0 }), SecondPos({ 0,0 }), Time(0), IsVertial(false){}
    Node(int x1, int y1, int x2, int y2, int Time, bool IsVertial) : FirstPos({ x1,y1 }), SecondPos({ x2,y2 }), Time(Time), IsVertial(IsVertial)
    {
        if (FirstPos.first > SecondPos.first) std::swap(FirstPos.first, SecondPos.first);
        if (FirstPos.second > SecondPos.second) std::swap(FirstPos.second, SecondPos.second);
    }

    bool Check(const vector<vector<int>>& board, int M, int N)
    {
        if( FirstPos.first < 0 || FirstPos.first >= M ||
            FirstPos.second < 0 || FirstPos.second >= M ||
            SecondPos.first < 0 || SecondPos.first >= M ||
            SecondPos.second < 0 || SecondPos.second >= M ||
            board[FirstPos.second][FirstPos.first] == 1 ||
            board[SecondPos.second][SecondPos.first] == 1)
            return true;
        return false;
    }
    void Print()
    {
        cout << "(" << FirstPos.first << ", " << FirstPos.second << "), ("
            << SecondPos.first << ", " << SecondPos.second << "), Time:" << Time;
        cout << std::boolalpha;
        cout << ", Is:" << IsVertial << endl;;
    }
    bool operator==(const Node& A) const
    {
        return (FirstPos == A.FirstPos) && (SecondPos == A.SecondPos) && (IsVertial == A.IsVertial);
    }
    bool operator<(const Node& A) const
    {
        return (FirstPos.first < A.FirstPos.first);
    }
};

template <>
struct hash<Node> {
    size_t operator()(const Node& n) const noexcept {
        size_t h1 = hash<int>()(n.FirstPos.first);
        size_t h2 = hash<int>()(n.FirstPos.second);
        size_t h3 = hash<int>()(n.SecondPos.first);
        size_t h4 = hash<int>()(n.SecondPos.second);
        size_t h5 = hash<int>()(n.IsVertial);

        // 간단한 combine 방법 (Xor + shift)
        return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1) ^ (h4 << 2) ^ (h5 << 3);
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;

    int M = board[0].size();
    int N = board.size();

    unordered_set<Node> Visited;

    queue<Node> BFS;
    BFS.push({ 0,0,1,0,0,false });
    while (!BFS.empty())
    {
        Node NowPos = BFS.front();
        BFS.pop();
        //NowPos.Print();

        int x1 = NowPos.FirstPos.first;
        int y1 = NowPos.FirstPos.second;
        int x2 = NowPos.SecondPos.first;
        int y2 = NowPos.SecondPos.second;
        int Time = NowPos.Time;
        bool IsVertial = NowPos.IsVertial;
        
        // visited 문제있음!
        if (Visited.find(NowPos) != Visited.end())
        {
            continue;
        }
        if ((x1 == M - 1 && y1 == M - 1) || (x2 == M - 1 && y2 == M - 1))
        {
            answer = min(answer, Time);
            break;
        }

        Visited.insert(NowPos);

        for (const auto& m : Move)
        {
            Node NewNode = { x1 + m[0] ,y1 + m[1] ,x2 + m[2] ,y2 + m[3], Time + 1, IsVertial };
            if (!NewNode.Check(board, M, N))
                BFS.push(NewNode);
        }

        if (IsVertial)
        {
            for (int i = 0; i < 4; i++)
            {                
                Node NewNode = { x1 + VertialRot[i][0] ,y1 + VertialRot[i][1] ,x2 + VertialRot[i][2] ,y2 + VertialRot[i][3], Time + 1, !IsVertial };
                Node CollideCheckNode = { x1 + VertialCollide[i][0] ,y1 + VertialCollide[i][1] ,x2 + VertialCollide[i][2] ,y2 + VertialCollide[i][3], Time + 1, IsVertial };
                if (!NewNode.Check(board, M, N) && !CollideCheckNode.Check(board, M, N))
                    BFS.push(NewNode);
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                Node NewNode = { x1 + HorizontalRot[i][0] ,y1 + HorizontalRot[i][1] ,x2 + HorizontalRot[i][2] ,y2 + HorizontalRot[i][3], Time + 1, !IsVertial };
                Node CollideCheckNode = { x1 + HorizontalCollide[i][0] ,y1 + HorizontalCollide[i][1] ,x2 + HorizontalCollide[i][2] ,y2 + HorizontalCollide[i][3], Time + 1, IsVertial };
                if (!NewNode.Check(board, M, N) && !CollideCheckNode.Check(board, M, N))
                    BFS.push(NewNode);
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({  {0,0,0,1,1},
                {0,0,0,1,0},
                {0,1,0,1,1},
                {1,1,0,0,1},
                {0,0,0,0,0} });
}