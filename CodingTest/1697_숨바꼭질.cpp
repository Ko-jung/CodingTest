#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x;
	int time;
	Node() :x(0), time(0) {}
	Node(int X, int T) : x(X), time(T) {}
};

int main()
{
	int N, K;
	cin >> N >> K;

	vector<bool> Visited(100'001, false);

	int Ans = 0;
	queue<Node> BFS;
	BFS.push(Node(N, 0));
	while (!BFS.empty())
	{
		int X = BFS.front().x;
		int Time = BFS.front().time;
		BFS.pop();

		if (X < 0 || X > 100'000 || Visited[X])
			continue;

		if (X == K)
		{
			cout << Time;
			return 0;
		}

		Visited[X] = true;

		BFS.push(Node(X - 1, Time + 1));
		BFS.push(Node(X + 1, Time + 1));
		BFS.push(Node(X * 2, Time + 1));
	}
}