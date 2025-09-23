// 1. 가장가까운 두점
// 2. 빙고
// 3. 네트워크 백본
// 4. 캐쉬 제작 (크기가 정해진 캐쉬메모리에서 Put, Get 명령어에 따라서 value 불러오기)
// 5. 가장 가까운 문자 찾기
// 6. 두개 뽑아서 영향력 강한거 (score[i]-score[j]) * (i-j)

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
	// i == i 대각
	int Temp1 = 5;
	// i + j == 5 대각
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