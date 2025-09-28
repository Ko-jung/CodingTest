#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

struct Node
{
    int Weight;
    int X;
    int Y;
    Node(int w, int x, int y) : Weight(w), X(x), Y(y) {}
    Node() : Weight(0), X(0), Y(0) {}

    bool operator<(const Node& a) const
    {
        return Weight < a.Weight;
    }
};

struct NodeCmp {
    bool operator()(Node a, Node b)
    {
        return a.Weight < b.Weight;
    }
};

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vector<vector<int>> Board(n, vector<int>(n));
    for (const auto& cost : costs)
    {
        Board[cost[1]][cost[0]] = cost[2];
        Board[cost[0]][cost[1]] = cost[2];
    }
    for (int i = 0; i < n; ++i)
    {
        Board[i][i] = 0;
    }

    priority_queue<Node, vector<Node>, NodeCmp> BFS;
    for (const auto& cost : costs)
    {
        BFS.emplace(cost[2], cost[0], cost[1]);
    }

    // 포함된 노드
    set<int> IncludeNode;
    IncludeNode.insert(0);

    // 미포함 노드
    set<int> ExcludeNode;
    for (int i = 1; i < n; ++i)
    {
        ExcludeNode.insert(i);
    }

    // while(!ExcludeNode.empty())
    for (int Temp = 0; Temp < n - 1; ++Temp)
    {
        Node Candidate(110000, 0, 0);
        for (const auto INode : IncludeNode)
        {
            for (int i = 0; i < n; ++i)
            {
                if (Board[INode][i] == 0) continue;
                if (IncludeNode.find(i) != IncludeNode.end()) continue;
                Candidate = min(Candidate, Node(Board[INode][i], INode, i));
            }
        }
        //cout << "ExcludeNode size: " << ExcludeNode.size() << endl;
        //cout << "Candidate: " << Candidate.Weight << ", " << Candidate.X << ", " << Candidate.Y << endl;

        // 미포함 노드 중 가중치가 가장 작은게 Candidate에 들어있다
        IncludeNode.insert(Candidate.Y);
        ExcludeNode.erase(Candidate.Y);
        answer += Candidate.Weight;
    }


    return answer;
}