//크기가 무한인 정사각형 모눈종이가 있다.
// 모눈종이의 각 정사각형은 행과 열의 쌍으로 표현할 수 있다.
//
//이 모눈종이 전체를 양의 정수의 소용돌이 모양으로 채울 것이다.
// 일단 숫자 1을 0행 0열에 쓴다.그리고 나서 0행 1열에 숫자 2를 쓴다.
// 거기서 부터 소용돌이는 반시계 방향으로 시작된다.
// 다음 숫자는 다음과 같이 채우면 된다.
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
//이 문제는 위와 같이 채운 것을 예쁘게 출력하면 된다.
// r1, c1, r2, c2가 입력으로 주어진다.
// r1, c1은 가장 왼쪽 위 칸이고, r2, c2는 가장 오른쪽 아래 칸이다.
//
//예쁘게 출력한다는 것은 다음과 같이 출력하는 것이다.
// 1. 출력은 r1행부터 r2행까지 차례대로 출력한다.
// 2. 각 원소는 공백으로 구분한다.
// 3. 모든 행은 같은 길이를 가져야 한다.
// 4. 공백의 길이는 최소로 해야 한다.
// 5. 모든 숫자의 길이(앞에 붙는 공백을 포함)는 같아야 한다.
// 6. 만약 수의 길이가 가장 길이가 긴 수보다 작다면, 왼쪽에서부터 공백을 삽입해 길이를 맞춘다.

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

			// 0,0 기준 우하대각선 방향으로 1, 9, 25, 49 값이 나오므로 이 숫자를 기준으로 쓴다.
			int Standard = (abs(x) > abs(y) ? (abs(x) ) * 2 - 1 : (abs(y) ) * 2 - 1);
			Standard *= Standard;
			Standard += 1;

			if (x - y >= 0)
			{
				// ㄱ자로 이동
				int S = abs(x) > abs(y) ? abs(x) : abs(y);
				int MoveY = S - 1 - y;
				int MoveX = S - 1 - x;
				Board[j][i] = Standard + MoveX + MoveY + 1;
			}
			else
			{
				// ㄱ자 이동
				int S = abs(x) > abs(y) ? abs(x) : abs(y);
				int MoveY = S - 1 + S;
				int MoveX = S - 1 + S;

				// ㄴ자 이동
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
			// 앞에 공백
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