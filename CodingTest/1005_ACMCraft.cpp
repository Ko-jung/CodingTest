//https://www.acmicpc.net/problem/1005
// ���� 2012��!���� 2�Ⱓ ������ ���ε��� ��ٸ��� �� ���� 
// ACM Craft(Association of Construction Manager Craft)�� �߸ŵǾ���.
//
//�� ������ ���ݱ��� ���� ���ӵ���� �ٸ��� ACMũ����Ʈ�� 
// ���̳����� ���� ������ ���� �ǹ��� ���� ������ ������ ���� �ʴ�.
// ��, ù ��° ���Ӱ� �� ��° ������ �ǹ��� ���� ������ �ٸ� ���� �ִ�.
// �� ���ӽ��� �� �ǹ��� ���� ������ �־�����.
// ���� ��� �ǹ��� ���� �Ǽ��� �����Ͽ� �ϼ��� �� ������ Delay�� �����Ѵ�.
//
//
//
//
//
//���� ���ø� ����.
//
//�̹� ���ӿ����� ������ ���� �Ǽ� ���� ��Ģ�� �־�����. 
// 1�� �ǹ��� �Ǽ��� �Ϸ�ȴٸ� 2���� 3���� �Ǽ��� �����Ҽ� �ִ�.(���ÿ� ������ �����ϴ�)
// �׸��� 4�� �ǹ��� ���� ���ؼ��� 2���� 3�� �ǹ��� ��� �Ǽ� �Ϸ�Ǿ������ 4���ǹ��� �Ǽ��� �����Ҽ� �ִ�.
//
//���� 4���ǹ��� �Ǽ��� �Ϸ��ϱ� ���ؼ��� �켱 ó�� 1�� �ǹ��� �Ǽ��ϴµ� 10�ʰ� �ҿ�ȴ�.
// �׸��� 2�� �ǹ��� 3�� �ǹ��� ���ÿ� �Ǽ��ϱ� �����ϸ� 
// 2���� 1�ʵڿ� �Ǽ��� �Ϸ������ ���� 3�� �ǹ��� �Ϸ���� �ʾ����Ƿ� 4�� �ǹ��� �Ǽ��� �� ����.
// 3�� �ǹ��� �ϼ��ǰ� ���� �׶� 4�� �ǹ��� ������ �����Ƿ� 4�� �ǹ��� �ϼ��Ǳ������ �� 120�ʰ� �ҿ�ȴ�.
//
//���ΰ��̸� �ֹ����� ���ΰ��� ����Ʈ ����� �����ϱ� ���� �������б��� ACMũ����Ʈ ��ȸ�� �����ߴ�!
// �ֹ����� ȭ���� ��Ʈ�� �Ƿ��� ������ �ֱ� ������ ��� ��⿡�� Ư�� �ǹ��� ���´ٸ� ������ ���ӿ��� �̱� �� �ִ�.
// �׷��� �� ���Ӹ��� Ư���ǹ��� ���� ���� ������ �޶����Ƿ� �ֹ����� �����ϰ� �־���.
// �����̸� ���� Ư���ǹ��� ���� ���� ���� ������ �ɸ��� �ּҽð��� �˾Ƴ��� ���α׷��� �ۼ�������.


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

multimap<int, int> Sequence;
vector<int> DP;
vector<int> Time;

void DFS(int key)
{
	if (Sequence.find(key) == Sequence.end())
	{
		DP[key - 1] = Time[key - 1];
		return;
	}

	for (auto it = Sequence.lower_bound(key); it != Sequence.upper_bound(key); it++)
	{
		if (DP[it->second - 1] == -1)
		{
			DP[it->second - 1] = 0;
			DFS(it->second);
		}

		DP[key - 1] = max(DP[key - 1], DP[it->second - 1] + Time[key - 1]);
	}
}

int main()
{
	// �׽�Ʈ ���̽� ��
	int T;
	cin >> T;

	vector<int> Answer(T, 0);

	for (int TestCount = 0; TestCount < T; TestCount++)
	{
		Sequence.clear();
		DP.clear();
		Time.clear();

		// �ǹ� ����, �Ǽ����� ��Ģ
		int N, K;
		cin >> N >> K;

		// �Ǽ� �ҿ� �ð�
		Time.assign(N, 0);
		for (auto& t : Time) cin >> t;

		// �Ǽ� ���� �ڷ�. ��-���� pair
		for (int i = 0; i < K; i++)
		{
			pair<int, int> Temp;
			cin >> Temp.second >> Temp.first;

			Sequence.insert(Temp);
		}

		// ��ǥ �ǹ�
		int W;
		cin >> W;

		DP.assign(N, -1);

		DFS(W);
		Answer[TestCount] = DP[W - 1];

		//for (int i = 0; i < N; i++)
		//{
		//	
		//
		//	// // ���� ������ ����
		//	// if (i == W - 1) continue;
		//	// 
		//	// int MaxTime{ 0 };
		//	// for (auto it = Sequence.lower_bound(i + 1); it != Sequence.upper_bound(i + 1); it++)
		//	// {
		//	// 	int NewTime = Time[it->second - 1] + BuildTime[i];
		//	// 	BuildTime[it->second - 1] = max(BuildTime[it->second - 1], NewTime);
		//	// }
		//}

		//Answer[TestCount] = BuildTime[W - 1];
	}

	for (int i = 0; i < T - 1; i++)
	{
		cout << Answer[i] << endl;
	}
	cout << Answer[T - 1];
}