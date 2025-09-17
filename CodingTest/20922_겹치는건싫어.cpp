#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	std::vector<int> Nums(N, 0);
	for (auto& num : Nums)
		cin >> num;

	int Ans = 0;

	// 겹치는게 없다 -> 범위 증가
	// 겹치는게 있다 -> 범위 감소
	// 절반절반 점프해서 가보자
	int LogLength = N;
	int LogCount = 1;
	while (true)
	{
		std::map<int, int> Count;
		int Start = 0, End = 0;
		int OverlapCount = 0;
		int MinOverlapCount = 300'000;

		// 윈도우 슬라이드 초기설정
		for (End = 0; End < LogLength; End++)
		{
			if (++Count[Nums[End]] == K + 1)
				OverlapCount++;
		}
		MinOverlapCount = min(MinOverlapCount, OverlapCount);
		--End;
		for (Start = 0; End < N; Start++, End++)
		{
			if (Start != 0)
			{
				if (--Count[Nums[Start - 1]] == K)
					OverlapCount--;
				if (++Count[Nums[End]] == K + 1)
					OverlapCount++;
			}

			MinOverlapCount = min(MinOverlapCount, OverlapCount);

			//for (int i = 0; i <= 9; i++)
			//{
			//	cout << Count[i] << ", ";
			//}
			//cout << " MinOverlapCount: " << MinOverlapCount << endl;
		}
		//{
		//	// 9, 4, 2, 1 *1/2
		//	// 9, 9 - (9*0.5) = 4, 
		//	// 9, 4, 2, 3
		//	// 범위를 늘리거나 줄일만큼의 크기
		//	double LogValue = pow(0.5, LogCount++);
		//
		//	// 겹치는게 있으니 범위를 줄인다
		//	int Temp = LogLength;
		//	if (OverlapCount)
		//	{
		//		LogLength -= (int)(LogLength * LogValue);
		//	}
		//	// 겹치는게 없으니 범위를 늘린다.
		//	else
		//	{
		//		LogLength += (int)(LogLength * LogValue);
		//
		//		// 변함이 없다 끝내자
		//		if (LogLength == Temp)
		//		{
		//			Ans = max(Ans, LogLength);
		//			break;
		//		}
		//	}
		//}

		// 선형으로 감소
		if (MinOverlapCount)
			--LogLength;
		else
		{
			Ans = LogLength;
			break;
		}
	}
	cout << Ans;
}