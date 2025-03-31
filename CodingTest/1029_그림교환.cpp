//������ ����ϴ� ������� ���忡 �𿩼� �׵��� �׸��� ���� �ŷ��Ϸ��� �Ѵ�.
// ��� �׸��� �ŷ��� ������ ���� ������ �����ؾ� �Ѵ�.
//
//�׸��� �� ��, �׸��� �� ���ݺ��� ũ�ų� ���� �������� �Ⱦƾ� �Ѵ�.
//���� �׸��� �� �� �̻� ��� ���� �Ұ����ϴ�.
//��� ���忡 ���ο� �׸��� ���Դ�.
// 1�� ��Ƽ��Ʈ�� �� �׸��� �ܺ� ���ο��� ���� 0�� �ְ� ���.
// ���� �� �׸��� �ڽ��� ������ ģ���鿡�� �ȷ��� �Ѵ�.
// ���� ������ ��� �����ϴ� �ŷ��� �̷�����ٰ� �������� ��,
// �׸��� �����ߴ� ����� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// (1�� ��Ƽ��Ʈ�� ���������� �� �׸��� ������ ����� �����Ѵ�).
//
// �ؼ� ���� ���� ����

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

//void BFS(const std::vector<std::vector<int>>& Price)
//{
//	// ��ȣ
//	// 1������ ���� �������� ���
//	// visited �迭
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