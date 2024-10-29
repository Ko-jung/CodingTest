//https://www.acmicpc.net/problem/10451
// 1���� N���� ���� N���� �̷���� ������ ��Ÿ���� ����� ���� ������ �ִ�.
// ���� ���, 8���� ���� �̷���� ����(3, 2, 7, 8, 1, 4, 5, 6)�� �迭�� �̿��� ǥ���ϸ�
//
// (1 & 2 & 3 & 4 & 5 & 6 & 7 & 8)
// (3 & 2 & 7 & 8 & 1 & 4 & 5 & 6)  �� ����.�Ǵ�, Figure 1�� ���� ���� �׷����� ��Ÿ�� ���� �ִ�.
//
//Figure 1�� �����ִ� �� ó��, ���� �׷���(3, 2, 7, 8, 1, 4, 5, 6) ���� �� 3���� ����Ŭ�� �ִ�.
// �̷��� ����Ŭ�� "���� ����Ŭ" �̶�� �Ѵ�.
//
//N���� ������ �̷���� ������ �־����� ��, ���� ����Ŭ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>

using namespace std;

vector<int> Nodes;
vector<bool> Visited;

bool DFS(int Node, int Parent, int Count)
{
	Visited[Node] = true;

	if (Visited[Nodes[Node]] == false)
	{
		return DFS(Nodes[Node], Parent, Count);
	}
	else if(Nodes[Node] == Parent)
	{
		return true;
	}

	return false;
}

int main()
{
	int T;
	cin >> T;

	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		int Count{ 0 };

		Visited.assign(N + 1, false);
		Nodes.assign(N + 1, 0);
		for (int i = 1; i < Nodes.size(); i++)
		{
			cin >> Nodes[i];
		}

		for (int i = 1; i < Nodes.size(); i++)
		{
			if (Visited[i] == false)
			{
				if (DFS(i, i, 1))
				{
					++Count;
				}
				else
				{

				}

			}
		}



		cout << Count << endl;
	}
}