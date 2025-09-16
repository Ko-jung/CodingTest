#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <limits>

using namespace std;

struct Node {
	int x;
	int time;
	Node() :x(0), time(0) {}
	Node(int X, int T) : x(X), time(T) {}

	bool operator>(const Node& a) const
	{
		return time > a.time;
	}
};

int main()
{
	int N, K;
	cin >> N >> K;

	//vector<bool> Visited(100'001, false);
	vector<int> Visited(100'001, std::numeric_limits<int>::max());
	//std::iota(Visited.begin(), Visited.begin() + N, -N);
	//std::iota(Visited.begin() + N, Visited.end(), 0);

	int Ans = 0;
	priority_queue<Node, vector<Node>, greater<Node>> BFS;
	BFS.push(Node(N, 0));
	while (!BFS.empty())
	{
		int X = BFS.top().x;
		int Time = BFS.top().time;
		BFS.pop();

		if (X < 0 || X > 100'000 || Visited[X] <= Time)
			continue;

		if (X == K)
		{
			cout << Time;
			return 0;
		}

		Visited[X] = Time;

		BFS.push(Node(X - 1, Time + 1));
		BFS.push(Node(X + 1, Time + 1));
		BFS.push(Node(X * 2, Time));
	}
	cout << "NoFind";
}