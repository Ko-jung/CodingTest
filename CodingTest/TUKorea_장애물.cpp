#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;
constexpr int MAX = std::numeric_limits<int>::max();

class NODE
{
public:
	int u;	// Start Node
	int v;	// End Node
	int w;	// Weight
};

void Print(const vector<vector<int>>& Board)
{
	for (const auto& board : Board)
	{
		for (const auto b : board)
		{
			cout << (b == MAX ? -1 : b) << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<NODE> Path(E, NODE());
	for (auto& node : Path)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node.u = u - 1;
		node.v = v - 1;
		node.w = w;
	}

	vector<vector<int>> Board(V, vector<int>(V, MAX));
	// 초기값 설정
	for (const auto& node : Path)
	{
		Board[node.u][node.v] = node.w;
		Board[node.v][node.u] = node.w;
	}
	for (int i = 0; i < V; i++)
	{
		Board[i][i] = 0;
	}
	Print(Board);

	// 거처가는 빠른길 설정
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Dijkstra;
	vector<bool> Visited(V, false);
	Dijkstra.emplace(0, 0);
	while (!Dijkstra.empty())
	{
		int Node = Dijkstra.top().first;
		int Weight = Dijkstra.top().second;
		Dijkstra.pop();
		cout << "(" << Node << ") , " << Weight << endl;

		// 경로 갱신
		//Board[Start][End] = Weight;
		//Board[End][Start] = Weight;
		Visited[Node] = true;

		Print(Board);

		if (Node == V - 1)
		{
			cout << Weight << endl;
			return 0;
		}

		for (int i = 0; i < V; i++)
		{
			// 가본적 없는 구역, 현재 노드
			if (Board[Node][i] == MAX || Node == i || Visited[i]) continue;

			Dijkstra.emplace(i, Weight + Board[Node][i]);
		}
	}
}