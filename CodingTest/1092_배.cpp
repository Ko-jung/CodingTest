//�����̴� �ױ����� ���Ѵ�.
// �׸��� ȭ���� �迡 �Ǿ�� �Ѵ�.
// ��� ȭ���� �ڽ��� �ȿ� �־��� �ִ�.
// �ױ����� ũ������ N�� �ְ�, 1�п� �ڽ��� �ϳ��� �迡 ���� �� �ִ�.
// ��� ũ������ ���ÿ� �����δ�.
//
//�� ũ������ ���� ������ �ִ�.
// �� ���� ���Ѻ��� ���ſ� �ڽ��� ũ�������� ������ �� ����.
// ��� �ڽ��� ��� �ű�µ� ��� �ð��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �ؿ� ������ ����

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


























// 1. ũ���� �������Ѱ� �ڽ��� ���� ������������
// 2. ���� ������ ũ������ �ִ� �������Ѻ��� ũ�� -1 ����
// 3. ũ���� �� �տ��� ���� ����ִ� �ڽ� ������ ó��
// 4. �ݺ�