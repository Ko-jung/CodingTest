//지민이는 항구에서 일한다.
// 그리고 화물을 배에 실어야 한다.
// 모든 화물은 박스에 안에 넣어져 있다.
// 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다.
// 모든 크레인은 동시에 움직인다.
//
//각 크레인은 무게 제한이 있다.
// 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다.
// 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 프로그램을 작성하시오.

// 밑에 생각한 로직

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> Crane(N);
	for (auto& C : Crane)
	{
		cin >> C;
	}
	sort(Crane.begin(), Crane.end(), std::greater());

	int M;
	cin >> M;

	vector<int> Box(M);
	for (auto& B : Box)
	{
		cin >> B;
	}
	sort(Box.begin(), Box.end(), std::greater());

	if (Box[0] > Crane[0])
	{
		cout << "-1";
		return 0;
	}

	int ProcessedBox{ 0 };
	int LoopCount{ 0 };
	while (ProcessedBox < M)
	{
		int i = 0;
		for (auto& C : Crane)
		{
			for (; i < M; ++i)
			{
				if (Box[i] == -1) continue;
				if (C >= Box[i])
				{
					++ProcessedBox;
					Box[i] = -1;
					break;
				}
			}
		}
		LoopCount++;
	}

	cout << LoopCount;
}


























// 1. 크레인 무게제한과 박스의 무게 내림차순정렬
// 2. 제일 높은게 크레인의 최대 무게제한보다 크면 -1 리턴
// 3. 크레인 맨 앞에서 부터 들수있는 박스 선택해 처리
// 4. 반복