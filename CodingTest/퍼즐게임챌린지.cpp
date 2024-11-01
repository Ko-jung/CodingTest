//����� ������� n���� ������ ���� �ð� ���� Ǯ��� �ϴ� ���� ������ �ϰ� �ֽ��ϴ�.
// �� ������ ���̵��� �ҿ� �ð��� ������ �ֽ��ϴ�.
// ����� ���õ��� ���� ������ Ǯ �� Ʋ���� Ƚ���� �ٲ�� �˴ϴ�.
// ���� ������ ���̵��� diff, ���� ������ �ҿ� �ð��� time_cur, ���� ������ �ҿ� �ð��� time_prev,
// ����� ���õ��� level�̶� �ϸ�, ������ ������ ���� ����˴ϴ�.
//		diff �� level�̸� ������ Ʋ���� �ʰ� time_cur��ŭ�� �ð��� ����Ͽ� �ذ��մϴ�.
//		diff > level�̸�, ������ �� diff - level�� Ʋ���ϴ�.������ Ʋ�� ������,
//		 time_cur��ŭ�� �ð��� ����ϸ�, �߰��� time_prev��ŭ�� �ð��� ����� ���� ������ �ٽ� Ǯ�� �;� �մϴ�.
//		 ���� ������ �ٽ� Ǯ ���� ���� ������ ���̵��� ������� Ʋ���� �ʽ��ϴ�.
//		 diff - level�� Ʋ�� ���Ŀ� �ٽ� ������ Ǯ�� time_cur��ŭ�� �ð��� ����Ͽ� ������ �ذ��մϴ�.
// 
//���� ��� diff = 3, time_cur = 2, time_prev = 4�� ���, level�� ���� ������ Ǫ�µ� �ɸ��� �ð��� ������ �����ϴ�.
//		level = 1�̸�, ������ 3 - 1 = 2�� Ʋ���ϴ�.
//		 �� �� Ʋ�� ������ 2 + 4 = 6�� �ð��� ����ϰ�, �ٽ� ������ Ǫ�� �� 2�� �ð��� ����ϹǷ�
//		 �� 6 �� 2 + 2 = 14�� �ð��� ����ϰ� �˴ϴ�.
//		level = 2�̸�, ������ 3 - 2 = 1�� Ʋ���Ƿ�, 6 + 2 = 8�� �ð��� ����ϰ� �˴ϴ�.
//		level �� 3�̸� ������ Ʋ���� ������, 2�� �ð��� ����ϰ� �˴ϴ�.
// 
//���� ���ӿ��� ��ü ���� �ð� limit�� ������ �ֽ��ϴ�.
// ���� �ð� ���� ������ ��� �ذ��ϱ� ���� ���õ��� �ּڰ��� ���Ϸ��� �մϴ�.
// ���̵�, �ҿ� �ð��� ��� ���� ������, ���õ��� ���� �������� �մϴ�.
//
//������ ���̵��� ������� ���� 1���� ���� �迭 diffs, ������ �ҿ� �ð��� ������� ���� 1���� ���� �迭 times,
// ��ü ���� �ð� limit�� �Ű������� �־����ϴ�.���� �ð� ���� ������ ��� �ذ��ϱ� ���� ���õ��� �ּڰ��� ������ return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long GetTime(int level, const vector<int>& diffs, const vector<int>& times)
{
	long long CurrentTime{ 0 };
	for (int i = 0; i < diffs.size(); i++)
	{
		if (level - diffs[i] >= 0)
		{
			CurrentTime += times[i];
		}
		else
		{
			CurrentTime += (times[i] + (diffs[i] - level) * (times[i] + times[i - 1]));
		}
	}
	return CurrentTime;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
	int answer = numeric_limits<int>::max();

	// diffs�� �̿��Ͽ� �信 ���� ����� level Ž��

	//int MaxLevel{ numeric_limits<int>::max() }, MinLevel{1};
	//for (int i = 0; i < diffs.size(); i++)
	//{
	//	long long CurrentTime = GetTime(diffs[i], diffs, times);
	//	if (CurrentTime <= limit)
	//	{
	//		MaxLevel = min(MaxLevel, diffs[i]);
	//	}
	//	else
	//	{
	//		MinLevel = max(MinLevel, diffs[i]);
	//	}
	//}

	int MaxLevel{ 200'000 }, MinLevel{1};
	// ���� Ž��
	while (MaxLevel >= MinLevel)
	{
		int level = (MaxLevel + MinLevel) / 2;
		long long CurrentTime = GetTime(level, diffs, times);

		if (CurrentTime <= limit)
		{
			MaxLevel = level - 1;
			answer = min(level, answer);
		}
		else
		{
			MinLevel = level + 1;
		}
	}
	//for (int level = MinLevel; level <= MaxLevel; level++)
	//{
	//	long long CurrentTime = GetTime(level, diffs, times);
	//	if (CurrentTime <= limit)
	//	{
	//		answer = level;
	//		break;
	//	}
	//}

	return answer;
}

int main()
{
	cout << solution({ 1,5,3 }, { 2,4,7 }, 30) << endl;
	cout << solution({ 1,4,4,2 }, { 6,3,8,2 }, 59) << endl;
	cout << solution({ 1,328,467,209,54 }, { 2,7,1,4,3 }, 1723) << endl;
	cout << solution({ 1,99999,100000,99995 }, { 9999,9001,9999,9001 }, 3456789012) << endl;
	cout << solution({ 1,1,3 }, { 1,1,3 }, 50) << endl;
}