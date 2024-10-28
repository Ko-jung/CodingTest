// 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> Nodes[1001];
vector<int> Visited;
int N, M;

void DFS(int Node, int Count)
{
	Visited[Node] = Count;

	for (int i = 0; i < Nodes[Node].size(); i++)
	{
		if (Visited[Nodes[Node][i]] == 0)
		{
			DFS(Nodes[Node][i], Count);
		}
	}	
}

int main()
{
	cin >> N >> M;
		
	Visited.assign(N + 1, false);
	int Count{ 0 };
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Nodes[a].emplace_back(b);
		Nodes[b].emplace_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (Visited[i] == false)
		{
			DFS(i, ++Count);
		}
	}

	cout << Count;
}