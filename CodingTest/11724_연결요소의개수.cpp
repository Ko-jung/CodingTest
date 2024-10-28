// ���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> Nodes;
vector<int> Visited;
int N, M;

void DFS(int Node, int Count)
{
	Visited[Node - 1] = Count;

	for (int i = 0; i < Nodes.size(); i++)
	{
		if (Nodes[i].first == Node)
		{
			if (Visited[Nodes[i].second - 1] == 0)
			{
				DFS(Nodes[i].second, Count);
			}
		}
	}
	
}

int main()
{
	cin >> N >> M;
		
	Visited.assign(N, false);
	int Count{ 0 };
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Nodes.emplace_back(pair<int, int>{a, b});
		Nodes.emplace_back(pair<int, int>{b, a});
	}

	for (const auto& n : Nodes)
	{
		if (Visited[n.first - 1] == false)
		{
			DFS(n.first, ++Count);
		}
	}

	cout << Count;
}