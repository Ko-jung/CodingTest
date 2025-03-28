//N×M크기의 직사각형이 있다.
// 각 칸에는 한 자리 숫자가 적혀 있다.
// 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오.
// 
// 이때, 정사각형은 행 또는 열에 평행해야 한다.

#include <iostream>
#include <vector>
#include <string>

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

}