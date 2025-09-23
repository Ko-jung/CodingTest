// 1. ���尡��� ����
// 2. ����
// 3. ��Ʈ��ũ �麻
// 4. ĳ�� ���� (ũ�Ⱑ ������ ĳ���޸𸮿��� Put, Get ��ɾ ���� value �ҷ�����)
// 5. ���� ����� ���� ã��
// 6. �ΰ� �̾Ƽ� ����� ���Ѱ� (score[i]-score[j]) * (i-j)

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void Print(const vector<vector<int>>& Board)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << Board[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@" << endl;
}

int main()
{
	//vector<vector<int>> Board(5, vector<int>(5, 0));
	map<int, pair<int,int>> NumPos;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int Temp;
			cin >> Temp;
			//Board[i][j] = Temp;

			NumPos.emplace(Temp, pair<int, int>{j, i});
		}
	}

	vector<int> Call(25);
	for (auto& c : Call)
		cin >> c;

	int Count = 0;
	vector<int> CountX(5, 5);
	vector<int> CountY(5, 5);
	int Bingo = 0;
	// i == i �밢
	int Temp1 = 5;
	// i + j == 5 �밢
	int Temp2 = 5;
	while (Bingo < 3)
	{
		++Count;
		auto [X, Y] = NumPos[Call[Count - 1]];
		//Board[Y][X] = 0;
		//cout << X << ", " << Y << endl;
		if (--CountX[Y] == 0)
			Bingo++;
		if(--CountY[X] == 0)
			Bingo++;
		if (X == Y && --Temp1 == 0)
			Bingo++;
		if(X + Y == 4 && --Temp2 == 0)
			Bingo++;
		//Print(Board);
	}
	cout << Count;
}