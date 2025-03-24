// 지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다.지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.
//
// 지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.
//
// 첫 번째 원소를 뽑아낸다.이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
// 왼쪽으로 한 칸 이동시킨다.이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
// 오른쪽으로 한 칸 이동시킨다.이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak - 1이 된다.
// 큐에 처음에 포함되어 있던 수 N이 주어진다.그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다.
// (이 위치는 가장 처음 큐에서의 위치이다.)
// 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

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
			// 한 쪽 방향으로 탐색
			// 나온 값이 반 보다 크다면 반대에서 출발해야하므로 반을 빼야한다
			int Index = std::distance(Arr.begin(), std::find(Arr.begin(), Arr.end(), target));

			// |||큐현재인덱스||||타겟인덱스||||
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
			// |||타겟인덱스||||큐현재인덱스||||
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