//https://www.acmicpc.net/problem/10448
//삼각수 Tn(n ≥ 1)는[그림]에서와 같이 기하학적으로 일정한 모양의 규칙을 갖는 점들의 모음으로 표현될 수 있다.
//
//
//
//[그림]
//
//자연수 n에 대해 n ≥ 1의 삼각수 Tn는 명백한 공식이 있다.
//
//Tn = 1 + 2 + 3 + ... + n = n(n + 1) / 2
//
//1796년, 가우스는 모든 자연수가 최대 3개의 삼각수의 합으로 표현될 수 있다고 증명하였다.예를 들어,
//	4 = T1 + T2
//	5 = T1 + T1 + T2
//	6 = T2 + T2 or 6 = T3
//	10 = T1 + T2 + T3 or 10 = T4
// 
//이 결과는 증명을 기념하기 위해 그의 다이어리에 “Eureka!num = Δ + Δ + Δ” 라고 적은것에서 유레카 이론으로 알려졌다.
// 꿍은 몇몇 자연수가 정확히 3개의 삼각수의 합으로 표현될 수 있는지 궁금해졌다.
// 위의 예시에서, 5와 10은 정확히 3개의 삼각수의 합으로 표현될 수 있지만 4와 6은 그렇지 않다.
//
//자연수가 주어졌을 때, 그 정수가 정확히 3개의 삼각수의 합으로 표현될 수 있는지 없는지를 판단해주는 프로그램을 만들어라.
// 단, 3개의 삼각수가 모두 달라야 할 필요는 없다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> Arr;

bool combinations_with_replacement(int n, int r, int index, int start, std::vector<int>& current, int Target) {
	if (index == r) {
		// 결과 출력
		if (Target == Arr[current[0]] + Arr[current[1]] + Arr[current[2]])
		{
			return true;
		}

		return false;
	}

	for (int i = start; i < n; ++i) {
		current[index] = i;
		if (combinations_with_replacement(n, r, index + 1, i, current, Target)) // 다음 인덱스, 중복을 허용하므로 i를 그대로 전달
			return true;
	}
	return false;
}

bool BF(int Target)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		for (int j = 0; j < Arr.size(); j++)
		{
			for (int k = 0; k < Arr.size(); k++)
			{
				if (Arr[i] + Arr[j] + Arr[k] == Target) {
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	int T;
	cin >> T;

	Arr.emplace_back(1);
	Arr.emplace_back(3);
	for (int i = 2; i < 1001; i++)
	{
		int a = Arr[i - 1] + i + 1;
		if (Arr[i - 1] + i + 1 > 1000) break;
		Arr.push_back(a);
	}

	// vector<bool> Temp(Arr.size(), false);
	// for (int i = 0; i < 3; i++) { Temp[i] = true; }

	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		bool IsFind{ false };
		//do {
		//	vector<int> SumArr;
		//	SumArr.reserve(3);
		//	for (int i = 0; i < Arr.size(); i++)
		//	{
		//		if (Temp[i])
		//			SumArr.emplace_back(Arr[i]);
		//	}
		//
		//	if (N == accumulate(SumArr.begin(), SumArr.end(), 0))
		//	{
		//		IsFind = true;
		//		break;
		//	}
		//} while (prev_permutation(Temp.begin(), Temp.end()));

		//vector<int> current(3);
		//while (true)
		//{
		//	if (combinations_with_replacement(Arr.size(), 3, 0, 0, current, N))
		//	{
		//		IsFind = true;
		//		break;
		//	}
		//}

		if (BF(N))
			cout << "1" << endl;
		else
			cout << "0" << endl;

		//if (IsFind) cout << "1" << endl;
		//else cout << "0" << endl;
	}
}