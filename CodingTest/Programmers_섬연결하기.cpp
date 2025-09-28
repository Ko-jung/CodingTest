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

    // ���Ե� ���
    set<int> IncludeNode;
    IncludeNode.insert(0);

    // ������ ���
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

        // ������ ��� �� ����ġ�� ���� ������ Candidate�� ����ִ�
        IncludeNode.insert(Candidate.Y);
        ExcludeNode.erase(Candidate.Y);
        answer += Candidate.Weight;
    }


    return answer;
}

// Kruskal �˰��� (Union-Find) ���� �ٽ� ����

//#include <string>
//#include <vector>
//#include <queue>
//#include <map>
//#include <iostream>
//#include <numeric>
//
//using namespace std;
//
//// Union Find�� Parent
//vector<int> Parent;
//
//int Find(int i)
//{
//    //if(Parent[i] == i)
//    //    return i;
//    //return Find(Parent[i]);
//    if (Parent[i] != i)
//        Parent[i] = Find(Parent[i]);
//    return Parent[i];
//}
//
//void Union(int Start, int To)
//{
//    //int StartRoot = Find(Start);
//    //int ToRoot = Find(To);
//    //if(StartRoot != ToRoot)
//    //    Parent[ToRoot] = StartRoot;
//    Parent[To] = Find(Start);
//}
//
//int solution(int n, vector<vector<int>> costs) {
//    int answer = 0;
//
//    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
//    for (const auto& cost : costs)
//    {
//        BFS.emplace(cost[2], cost[0], cost[1]);
//    }
//
//    // Union Find�� Parent Init
//    Parent.assign(n, 0);
//    iota(Parent.begin(), Parent.end(), 0);
//
//    while (!BFS.empty())
//    {
//        auto [Weight, Start, To] = BFS.top();
//        BFS.pop();
//
//        // Start�� To�� �θ� ������ Ȯ�� ���ٸ� ����
//        if (Find(Start) == Find(To)) continue;
//
//        cout << Start << ", " << To << ", " << Weight << endl;
//        for (auto temp : Parent)
//            cout << temp << ", ";
//        cout << endl;
//
//        // �ٸ��ٸ� Union���� ���� �� ��� �߰�
//        Union(Start, To);
//        answer += Weight;
//    }
//
//    return answer;
//}