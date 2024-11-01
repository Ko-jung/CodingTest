//당신은 순서대로 n개의 퍼즐을 제한 시간 내에 풀어야 하는 퍼즐 게임을 하고 있습니다.
// 각 퍼즐은 난이도와 소요 시간이 정해져 있습니다.
// 당신의 숙련도에 따라 퍼즐을 풀 때 틀리는 횟수가 바뀌게 됩니다.
// 현재 퍼즐의 난이도를 diff, 현재 퍼즐의 소요 시간을 time_cur, 이전 퍼즐의 소요 시간을 time_prev,
// 당신의 숙련도를 level이라 하면, 게임은 다음과 같이 진행됩니다.
//		diff ≤ level이면 퍼즐을 틀리지 않고 time_cur만큼의 시간을 사용하여 해결합니다.
//		diff > level이면, 퍼즐을 총 diff - level번 틀립니다.퍼즐을 틀릴 때마다,
//		 time_cur만큼의 시간을 사용하며, 추가로 time_prev만큼의 시간을 사용해 이전 퍼즐을 다시 풀고 와야 합니다.
//		 이전 퍼즐을 다시 풀 때는 이전 퍼즐의 난이도에 상관없이 틀리지 않습니다.
//		 diff - level번 틀린 이후에 다시 퍼즐을 풀면 time_cur만큼의 시간을 사용하여 퍼즐을 해결합니다.
// 
//예를 들어 diff = 3, time_cur = 2, time_prev = 4인 경우, level에 따라 퍼즐을 푸는데 걸리는 시간은 다음과 같습니다.
//		level = 1이면, 퍼즐을 3 - 1 = 2번 틀립니다.
//		 한 번 틀릴 때마다 2 + 4 = 6의 시간을 사용하고, 다시 퍼즐을 푸는 데 2의 시간을 사용하므로
//		 총 6 × 2 + 2 = 14의 시간을 사용하게 됩니다.
//		level = 2이면, 퍼즐을 3 - 2 = 1번 틀리므로, 6 + 2 = 8의 시간을 사용하게 됩니다.
//		level ≥ 3이면 퍼즐을 틀리지 않으며, 2의 시간을 사용하게 됩니다.
// 
//퍼즐 게임에는 전체 제한 시간 limit가 정해져 있습니다.
// 제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값을 구하려고 합니다.
// 난이도, 소요 시간은 모두 양의 정수며, 숙련도도 양의 정수여야 합니다.
//
//퍼즐의 난이도를 순서대로 담은 1차원 정수 배열 diffs, 퍼즐의 소요 시간을 순서대로 담은 1차원 정수 배열 times,
// 전체 제한 시간 limit이 매개변수로 주어집니다.제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값을 정수로 return 하도록 solution 함수를 완성해 주세요.

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

	// diffs를 이용하여 답에 제일 비슷한 level 탐색

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
	// 이진 탐색
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