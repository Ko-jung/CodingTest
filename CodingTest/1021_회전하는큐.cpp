// �����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�.�����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.
//
// �����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.
//
// ù ��° ���Ҹ� �̾Ƴ���.�� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
// �������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
// ���������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak - 1�� �ȴ�.
// ť�� ó���� ���ԵǾ� �ִ� �� N�� �־�����.�׸��� �����̰� �̾Ƴ����� �ϴ� ������ ��ġ�� �־�����.
// (�� ��ġ�� ���� ó�� ť������ ��ġ�̴�.)
// �̶�, �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	int M, N;
	std::cin >> N >> M;

	std::vector<int> Arr(N);
	std::iota(Arr.begin(), Arr.end(), 1);

	std::vector<int> Target;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;

		Target.push_back(temp);
	}

	int Count = 0;
	int NowIndex = 0;
	while (true)
	{
		for (const auto& target : Target)
		{
			// �� �� �������� Ž��
			// ���� ���� �� ���� ũ�ٸ� �ݴ뿡�� ����ؾ��ϹǷ� ���� �����Ѵ�
			int Index = std::distance(Arr.begin(), std::find(Arr.begin(), Arr.end(), target));

			// |||ť�����ε���||||Ÿ���ε���||||
			if (Index > NowIndex)
			{
				int TempCount = 0;
				for (int i = 0; i < Arr.size()/2; i++)
				{
					if (!Arr[i + NowIndex]) continue;
					if (Arr[i + NowIndex] == target)
					{
						TempCount = i;
					}
				}

				if (TempCount)
				{
					// find
					Count += TempCount;
				}
				else
				{
					// cant find
				}
			}
			// |||Ÿ���ε���||||ť�����ε���||||
			else
			{

			}

			if (abs(Index - NowIndex) <= Arr.size() / 2)
			{
				Count += (abs(Index - NowIndex));
			}
			else
			{
				if (Index > NowIndex)
				{
					int LeftCount = NowIndex;
					int RightCount = Arr.size() - Index - 1;
					Count += ();
				}
				else
				{

				}
			}

			NowIndex = Index;
		}
	}
}