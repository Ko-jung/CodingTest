//https://www.acmicpc.net/problem/10451
// 1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법은 여러 가지가 있다.
// 예를 들어, 8개의 수로 이루어진 순열(3, 2, 7, 8, 1, 4, 5, 6)을 배열을 이용해 표현하면
//
// (1 & 2 & 3 & 4 & 5 & 6 & 7 & 8)
// (3 & 2 & 7 & 8 & 1 & 4 & 5 & 6)  와 같다.또는, Figure 1과 같이 방향 그래프로 나타낼 수도 있다.
//
//Figure 1에 나와있는 것 처럼, 순열 그래프(3, 2, 7, 8, 1, 4, 5, 6) 에는 총 3개의 사이클이 있다.
// 이러한 사이클을 "순열 사이클" 이라고 한다.
//
//N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수를 구하는 프로그램을 작성하시오.

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