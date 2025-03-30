//N��Mũ���� ���簢���� �ִ�.
// �� ĭ���� �� �ڸ� ���ڰ� ���� �ִ�.
// �� ���簢������ �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã�� ���α׷��� �ۼ��Ͻÿ�.
// 
// �̶�, ���簢���� �� �Ǵ� ���� �����ؾ� �Ѵ�.

#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> Board;

	for (int i = 0; i < N; i++)
	{
		std::string Temp;
		std::cin >> Temp;

		std::vector<int> Line;
		for (const auto& c : Temp)
		{
			Line.emplace_back(c - '0');
		}
		Board.emplace_back(Line);
	}

	int Answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = std::min(N - 1 - i, M - 1 - j); k > Answer; k--)
			{
				if (Board[i][j] == Board[i + k][j] &&
					Board[i][j] == Board[i][j + k] &&
					Board[i][j] == Board[i + k][j + k])
				{
					Answer = k;
					break;
				}
			}
		}
	}

	Answer++;
	std::cout << (Answer * Answer) << std::endl;
}