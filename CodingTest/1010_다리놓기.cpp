//����̴� �� ������ ������ �Ǿ���.
// �� ���ÿ��� ���ø� ���ʰ� �������� ������ ū ������ ����� ���� �帣�� �ִ�.
// ������ ����̴� �ٸ��� ��� �ùε��� ���� �ǳʴµ� ū ������ �ް� ������ �˰� �ٸ��� ����� ����Ͽ���.
// �� �ֺ����� �ٸ��� ���⿡ ������ ���� ����Ʈ��� �Ѵ�.
// ����̴� �� �ֺ��� ����� ������ �� ��� ���� ���ʿ��� N���� ����Ʈ�� �ְ� ���ʿ��� M���� ����Ʈ�� �ִٴ� ���� �˾Ҵ�. (N �� M)
//
//����̴� ������ ����Ʈ�� ������ ����Ʈ�� �ٸ��� �����Ϸ��� �Ѵ�. (�̶� �� ����Ʈ���� �ִ� �� ���� �ٸ��� ����� �� �ִ�.) 
// ����̴� �ٸ��� �ִ��� ���� �������� �ϱ� ������ ������ ����Ʈ ������ŭ(N��) �ٸ��� �������� �Ѵ�.
// �ٸ������� ���� ������ �� ���ٰ� �� �� �ٸ��� ���� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��϶�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int TC = 0; TC < T; TC++)
	{
		int N, M;
		cin >> N >> M;

		int Count{ 1 };
		int Temp{ 1 };
		// vector<int> Arr(M);
		// iota(Arr.begin(), Arr.end(), 0);
		// 
		// vector<bool> Temp(Arr.size(), false);
		// for (int i = 0; i < N; i++) { Temp[i] = true; }
		// do
		// {
		// 	//vector<int> Combination;
		// 	//Combination.reserve(N);
		// 	//for (int i = 0; i < Arr.size(); i++)
		// 	//{
		// 	//	if (Temp[i])
		// 	//		Combination.emplace_back(Arr[i]);
		// 	//}
		// 	//
		// 	//if (is_sorted(Combination.begin(), Combination.end()))
		// 		++Count;
		// 
		// } while (prev_permutation(Temp.begin(), Temp.end()));

		for (int i = M; i > M - N; --i)
		{
			Count *= i;
			Count /= Temp++;
		}

		cout << Count << endl;
	}
}