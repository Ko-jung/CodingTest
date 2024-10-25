// https://www.acmicpc.net/problem/1011
//���̴� � ����, ���� ���� �ٸ� �༺������ �η����� ��ư� �� �ִ� �̷��� ������ �Ͼ���.
// �׸��� �װ� ������� ���� ���� ���� ���� �� 23���� ���� ����, 
// ���� �ֿ��� ASNA ���� ����簡 �Ǿ� ���ο� ���迡 ���� ���� ���� ������ ������ ��ٸ��� �ִ�.
//
//�װ� ž���ϰ� �� ���ּ��� Alpha Centauri��� ���ο� �η��� �����ڸ��� ��ô�ϱ� ���� ��Ը� ��Ȱ ���� �ý����� ž���ϰ� �ֱ� ������, 
// �� ũ��� ������ ��û�� ������ �ֽű������ �� �����Ͽ� ������ �����̵� ��ġ�� ž���Ͽ���.
// ������ �� �����̵� ��ġ�� �̵� �Ÿ��� �ް��ϰ� �ø� ��� ��迡 �ɰ��� ������ �߻��ϴ� ������ �־, 
// ���� �۵��ñ⿡ k������ �̵��Ͽ��� ���� k - 1, k Ȥ�� k + 1 ���⸸�� �ٽ� �̵��� �� �ִ�.
// ���� ���, �� ��ġ�� ó�� �۵���ų ��� - 1, 0, 1 ������ �̷л� �̵��� �� ������ 
// ��ǻ� ���� Ȥ�� 0 �Ÿ���ŭ�� �̵��� �ǹ̰� �����Ƿ� 1 ������ �̵��� �� ������, 
// �� �������� 0, 1, 2 ������ �̵��� �� �ִ� ���̴�. 
// (���⼭ �ٽ� 2������ �̵��Ѵٸ� ���� �ñ⿣ 1, 2, 3 ������ �̵��� �� �ִ�.)
//
//
//
//������� �����̵� ��ġ �۵����� ������ �Ҹ� ũ�ٴ� ���� �� �˰� �ֱ� ������ 
// x�������� y������ ���� �ּ����� �۵� Ƚ���� �̵��Ϸ� �Ѵ�.
// ������ y������ �����ؼ��� ���� �̵���ġ�� �������� ���Ͽ� y������ �����ϱ� �ٷ� ������ �̵��Ÿ��� �ݵ�� 1�������� �Ϸ� �Ѵ�.
//
//������� ���� x�������� ��Ȯ�� y�������� �̵��ϴµ� �ʿ��� ���� �̵� ��ġ �۵� Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��϶�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position
{
	int pos;
	int prevmove;
	int count;
};

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		pair<int, int> Pos;
		cin >> Pos.first >> Pos.second;

		// BFS�� ���� ť
		queue< Position> BFS;
		BFS.push({ Pos.first + 1, 1, 1});

		// DP�� ���� vector
		vector<int> DP(Pos.second + 1, -1);

		int Ans;

		while (!BFS.empty())
		{
			int NowPos = BFS.front().pos;
			int PrevMove = BFS.front().prevmove;
			int Count = BFS.front().count;
			BFS.pop();

			if (DP[NowPos] == -1)
			{
				DP[NowPos] = Count;

				if (PrevMove <= 0) continue;
				if (NowPos == Pos.second - 1) { Ans = Count; break; }

				for (int i = -1; i <= 1; i++)
				{
					if(NowPos + PrevMove + i <= Pos.second && DP[NowPos + PrevMove + i] == -1)
						BFS.push({ NowPos + PrevMove + i, PrevMove + i, Count + 1 });
				}
			}
			else
			{
				DP[NowPos] = min(DP[NowPos], Count);
			}
		}

		cout << Ans + 1 << endl;
	}
}