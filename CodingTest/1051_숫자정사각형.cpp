//N��Mũ���� ���簢���� �ִ�.
// �� ĭ���� �� �ڸ� ���ڰ� ���� �ִ�.
// �� ���簢������ �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã�� ���α׷��� �ۼ��Ͻÿ�.
// 
// �̶�, ���簢���� �� �Ǵ� ���� �����ؾ� �Ѵ�.

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