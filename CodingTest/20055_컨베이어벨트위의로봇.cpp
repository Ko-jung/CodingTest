#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void Print(const vector<pair<int, bool>>& Conveyors, int N, int RotateCount)
{
	cout << "======Start======" << endl;
	int UpperIndex = ((2 * N - 1) - (RotateCount % (2 * N)));
	int LowerIndex = (N - (RotateCount % (2 * N)) - 1);
	for (int i = 0; i < N; i++)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);

		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.first << ", ";
	}
	cout << endl;
	for (int i = 2 * N - 1; i >= N; --i)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);
		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.first << ", ";
	}
	cout << endl << boolalpha;
	for (int i = 0; i < N; i++)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);

		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.second << ", ";
	}
	cout << endl;
	for (int i = 2 * N - 1; i >= N; --i)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);
		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.second << ", ";
	}
	cout << endl;
	cout << "======End======" << endl;
}

int main()
{
	// 20:38
	int N, K;
	cin >> N >> K;

	// 내구도, 로봇이 있는지
	vector<pair<int, bool>> Conveyors(N * 2, pair<int, bool>(0, false));
	for (auto& i : Conveyors)
		cin >> i.first;

	int LowK = 0;
	int RotateCount = 0;
	//Print(Conveyors, N, RotateCount);

	while (true)
	{
		// 1.	벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		// 0, 1, 2, 3
		// 3. 0, 1, 2
		// 2, 3, 0, 1
		int UpperIndex = ((2 * N - 1) - (RotateCount % (2 * N)));
		int LowerIndex = (N - (RotateCount % (2 * N)) - 2);
		LowerIndex < 0 ? LowerIndex += 2 * N : LowerIndex;
		if (Conveyors[LowerIndex].second)
			Conveyors[LowerIndex].second = false;
		//cout << UpperIndex << ", " << LowerIndex << endl;
		// 2.	가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.만약 이동할 수 없다면 가만히 있는다.
		//		1.	로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
		for (int i = (N - 1) - 1; i >= 0; --i)
		{
			int Prev = (UpperIndex + i) % (2 * N);
			int Index= (UpperIndex + i + 1) % (2 * N);
			//cout << Prev << "//" << Index << endl;

			// Prev에 로봇이 있으면서, Index에 없으면서, Index 내구도가 0보다 클때
			if (Conveyors[Prev].second && !Conveyors[Index].second && Conveyors[Index].first)
			{
				Conveyors[Prev].second = !Conveyors[Prev].second;
				Conveyors[Index].second = !Conveyors[Index].second;
				if (--Conveyors[Index].first == 0)
					LowK++;
				if(Index == LowerIndex)
					Conveyors[Index].second = false;
			}
		}
		// 3.	올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if (Conveyors[UpperIndex].first)
		{
			assert(Conveyors[UpperIndex].second != true);

			Conveyors[UpperIndex].second = true;
			if (--Conveyors[UpperIndex].first == 0)
				LowK++;
		}
		// 4.	내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.그렇지 않다면 1번으로 돌아간다.
		if (LowK >= K)
			break;
		RotateCount++;
		//Print(Conveyors, N, RotateCount);
	}

	cout << RotateCount + 1;
}

// 0 1 2
// 5 4 3
// 5 0 1
// 4 3 2
