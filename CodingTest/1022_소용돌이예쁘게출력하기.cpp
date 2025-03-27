//ũ�Ⱑ ������ ���簢�� �����̰� �ִ�.
// �������� �� ���簢���� ��� ���� ������ ǥ���� �� �ִ�.
//
//�� ������ ��ü�� ���� ������ �ҿ뵹�� ������� ä�� ���̴�.
// �ϴ� ���� 1�� 0�� 0���� ����.�׸��� ���� 0�� 1���� ���� 2�� ����.
// �ű⼭ ���� �ҿ뵹�̴� �ݽð� �������� ���۵ȴ�.
// ���� ���ڴ� ������ ���� ä��� �ȴ�.
//
//		- 3 - 2 - 1  0  1  2  3
//		--------------------
//	-3 | 37 36 35 34 33 32 31
//	-2 | 38 17 16 15 14 13 30
//	-1 | 39 18  5  4  3 12 29
//	 0 | 40 19  6  1  2 11 28
//	 1 | 41 20  7  8  9 10 27
//	 2 | 42 21 22 23 24 25 26
//	 3 | 43 44 45 46 47 48 49
// 
//�� ������ ���� ���� ä�� ���� ���ڰ� ����ϸ� �ȴ�.
// r1, c1, r2, c2�� �Է����� �־�����.
// r1, c1�� ���� ���� �� ĭ�̰�, r2, c2�� ���� ������ �Ʒ� ĭ�̴�.
//
//���ڰ� ����Ѵٴ� ���� ������ ���� ����ϴ� ���̴�.
// 1. ����� r1����� r2����� ���ʴ�� ����Ѵ�.
// 2. �� ���Ҵ� �������� �����Ѵ�.
// 3. ��� ���� ���� ���̸� ������ �Ѵ�.
// 4. ������ ���̴� �ּҷ� �ؾ� �Ѵ�.
// 5. ��� ������ ����(�տ� �ٴ� ������ ����)�� ���ƾ� �Ѵ�.
// 6. ���� ���� ���̰� ���� ���̰� �� ������ �۴ٸ�, ���ʿ������� ������ ������ ���̸� �����.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

int main()
{
	int r1, c1, r2, c2;

	std::cin >> r1 >> c1 >> r2 >> c2;

	int Height = r2 - r1 + 1;
	int Wight  = c2 - c1 + 1;

	std::vector<std::vector<int>> Board(Height, std::vector<int>(Wight, 0));

	for (int j = 0; j < Height; j++)
	{
		for (int i = 0; i < Wight; i++)
		{
			int x = c1 + i;
			int y = r1 + j;

			if (x >= 0 && y >= 0 && x == y)
			{
				int Temp = (x + 1) * 2 - 1;
				Board[j][i] = Temp * Temp;
				continue;
			}

			// 0,0 ���� ���ϴ밢�� �������� 1, 9, 25, 49 ���� �����Ƿ� �� ���ڸ� �������� ����.
			int Standard = (abs(x) > abs(y) ? (abs(x) ) * 2 - 1 : (abs(y) ) * 2 - 1);
			Standard *= Standard;
			Standard += 1;

			if (x - y >= 0)
			{
				// ���ڷ� �̵�
				int S = abs(x) > abs(y) ? abs(x) : abs(y);
				int MoveY = S - 1 - y;
				int MoveX = S - 1 - x;
				Board[j][i] = Standard + MoveX + MoveY + 1;
			}
			else
			{
				// ���� �̵�
				int S = abs(x) > abs(y) ? abs(x) : abs(y);
				int MoveY = S - 1 + S;
				int MoveX = S - 1 + S;

				// ���� �̵�
				MoveY += (y - (-S));
				MoveX += (x - (-S));
				Board[j][i] = Standard + MoveX + MoveY + 1;
			}

			//std::cout << Board[j][i] << " ";
		}
		//std::cout << std::endl;
	}

	std::vector<int> MaxElements;
	for (const auto& board : Board)
	{
		auto Max = std::max_element(board.begin(), board.end());
		MaxElements.emplace_back(*Max);
	}
	int Max = *std::max_element(MaxElements.begin(), MaxElements.end());
	int Digits = log10(Max) + 1;
	//std::cout << Digits << std::endl;

	for (const auto& board : Board)
	{
		for (const auto& b : board)
		{
			int BDigit = log10(b) + 1;

			std::string Text;
			// �տ� ����
			for (int i = 0; i < Digits - BDigit; i++)
			{
				Text += " ";
			}
			Text += std::to_string(b);

			std::cout << Text << " ";
		}
		std::cout << std::endl;
	}
}