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
#include <deque>
#include <numeric>
#include <algorithm>

int main()
{
	int M, N;
	std::cin >> N >> M;

	std::deque<int> Arr(N);
	std::iota(Arr.begin(), Arr.end(), 1);

	std::vector<int> Target;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;

		Target.push_back(temp);
	}

	int Count = 0;

	for (const auto& target : Target)
	{
		//if (Arr.front() == target || Arr.back() == target)
		//{
		//	Arr.front() == target ? Arr.pop_front() : Arr.pop_back();
		//	continue;
		//}
		int TargetIndex = std::distance(Arr.begin(), std::find(Arr.begin(), Arr.end(), target));

		if (TargetIndex > (Arr.size() / 2))
		{
			while (Arr.front() != target)
			{
				int Back = Arr.back();
				Arr.pop_back();
				Arr.push_front(Back);
				Count++;
			}
			Arr.pop_front();
		}
		else
		{
			while (Arr.front() != target)
			{
				int Front = Arr.front();
				Arr.pop_front();
				Arr.push_back(Front);
				Count++;
			}
			Arr.pop_front();
		}
	}

	std::cout << Count << std::endl;
}