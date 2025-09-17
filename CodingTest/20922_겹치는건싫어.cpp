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

	// ��ġ�°� ���� -> ���� ����
	// ��ġ�°� �ִ� -> ���� ����
	// �������� �����ؼ� ������
	int LogLength = N;
	int LogCount = 1;
	while (true)
	{
		std::map<int, int> Count;
		int Start = 0, End = 0;
		int OverlapCount = 0;
		int MinOverlapCount = 300'000;

		// ������ �����̵� �ʱ⼳��
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
		//	// ������ �ø��ų� ���ϸ�ŭ�� ũ��
		//	double LogValue = pow(0.5, LogCount++);
		//
		//	// ��ġ�°� ������ ������ ���δ�
		//	int Temp = LogLength;
		//	if (OverlapCount)
		//	{
		//		LogLength -= (int)(LogLength * LogValue);
		//	}
		//	// ��ġ�°� ������ ������ �ø���.
		//	else
		//	{
		//		LogLength += (int)(LogLength * LogValue);
		//
		//		// ������ ���� ������
		//		if (LogLength == Temp)
		//		{
		//			Ans = max(Ans, LogLength);
		//			break;
		//		}
		//	}
		//}

		// �������� ����
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