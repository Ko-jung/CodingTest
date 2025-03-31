//예술을 사랑하는 사람들이 시장에 모여서 그들의 그림을 서로 거래하려고 한다.
// 모든 그림의 거래는 다음과 같은 조건을 만족해야 한다.
//
//그림을 팔 때, 그림을 산 가격보다 크거나 같은 가격으로 팔아야 한다.
//같은 그림을 두 번 이상 사는 것은 불가능하다.
//방금 시장에 새로운 그림이 들어왔다.
// 1번 아티스트는 그 그림을 외부 상인에게 가격 0을 주고 샀다.
// 이제 그 그림을 자신의 예술가 친구들에게 팔려고 한다.
// 위의 조건을 모두 만족하는 거래만 이루어진다고 가정했을 때,
// 그림을 소유했던 사람의 수의 최댓값을 출력하는 프로그램을 작성하시오.
// (1번 아티스트와 마지막으로 그 그림을 소유한 사람도 포함한다).
//
// 해설 봐도 이해 실패

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

//void BFS(const std::vector<std::vector<int>>& Price)
//{
//	// 번호
//	// 1번부터 현재 노드까지의 비용
//	// visited 배열
//
//}

class NODE
{
public:
	NODE(int owner, int depth, int price, int N)
		: Depth(depth), Owner(owner), Price(price), BuyPrice(0)
	{
		Visited.assign(N, false);
	}
	int Depth;
	int Owner;
	int Price;
	int BuyPrice;
	std::vector<bool> Visited;
};

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> Price( N, std::vector<int>(N, 0) );
	for (auto& price : Price)
	{
		for (auto& p : price)
		{
			char c;
			std::cin >> c;
			p = c - '0';
		}
	}

	std::queue<NODE> BFS;
	NODE n(0, 1, 0, N);
	n.Visited[0] = true;
	BFS.push(n);

	int Answer = std::numeric_limits<int>::min();
	std::vector<int> MinPrice(N + 1, std::numeric_limits<int>::max());
	while (!BFS.empty())
	{
		NODE Node = BFS.front();
		BFS.pop();

		Answer = std::max(Answer, Node.Depth);

		for (int i = 0; i < N; i++)
		{
			if (Node.Visited[i])  continue;
			if (i == Node.Owner) continue;
			if (Node.BuyPrice > Price[Node.Owner][i]) continue;
			
			if (Node.Price + Price[Node.Owner][i] <= MinPrice[Node.Depth + 1])
			{
				NODE nn(i, Node.Depth + 1, Node.Price + Price[Node.Owner][i], N);
				nn.Visited.assign(Node.Visited.begin(), Node.Visited.end());
				nn.Visited[i] = true;
				nn.BuyPrice = Price[Node.Owner][i];

				MinPrice[Node.Depth] = Node.Price + Price[Node.Owner][i];

				BFS.push(nn);
			}

		}
	}

	std::cout << Answer;
}