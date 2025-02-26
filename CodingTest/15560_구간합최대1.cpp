/*
문제
	길이 N의 수열 K1, K2, ..., KN과 상수 U, V가 주어진다.
	Q개의 쿼리가 주어지며, 그 종류는 두 가지가 있다.
		1. A, B가 주어지면, max(U × (Ki + Ki + 1 + ... + Kj) + V × (j - i)) (A ≤ i ≤ j ≤ B) 의 값을 구한다.
		2. A, B가 주어지면, KA의 값을 B으로 바꾼다.

	https://www.notion.so/1a5a80bf7dba80df90d8e4ceef15bffb?pvs=4 참고하기
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

void Print(std::vector<int>& SegmentTree)
{
	for (int i = 0; i < SegmentTree.size(); i++)
	{
		std::cout << SegmentTree[i] << " ";
	}
	std::cout << '\n';
}

int main()
{
	int N, Q, U, V;
	std::cin >> N >> Q >> U >> V;

	std::vector<int> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		K.push_back(temp);
	}

	for (int Query = 0; Query < Q; Query++)
	{
		int C, A, B;
		std::cin >> C >> A >> B;

		//트리 생성
		std::vector<int> SegmentTree;
		{
			// 트리 크기
			int Pow = 1;
			while (Pow < N)
			{
				Pow *= 2;
			}
			SegmentTree.assign(Pow * 2, 0);

			// 샘플 데이터 트리의 중간부터 저장
			for (int i = 0; i < N; i++)
			{
				SegmentTree[SegmentTree.size() / 2 + i] = K[i];
			}

			// 부모 노드 채우기
			for (int i = SegmentTree.size() - 1; i >= 0; i--)
			{
				SegmentTree[i / 2] += SegmentTree[i];
			}

			//Print(SegmentTree);
		}

		if (C == 0)
		{
			//Print(SegmentTree);
			
			// 1번 쿼리
			int Max{ 0 };
			for (int Right = B - 1; Right >= 0; --Right)
			{
				for (int Left = A - 1; Left < Right; Left++)
				{
					int S = Left;
					int E = Right;
					// 구간 합
					int SegSum = 0;

					std::vector<int> NodeNum;
					int Start = S + SegmentTree.size() / 2;
					int End = E + SegmentTree.size() / 2;
					while (true)
					{
						// 부모 노드로 이동
						int NextStart = (Start + 1) / 2;
						int NextEnd = (End - 1) / 2;

						if (NextStart >= NextEnd)
						{
							NodeNum.push_back(Start);
							NodeNum.push_back(End);
							break;
						}
						else
						{
							if (Start % 2 == 1) NodeNum.push_back(Start);	// 노드 선택
							if (End % 2 == 0) NodeNum.push_back(End);		// 노드 선택


							Start = NextStart;
							End = NextEnd;
						}
					}
					for (auto& p : NodeNum)
					{
						SegSum += SegmentTree[p];
					}

					int Sum = U * SegSum + V * (E - S);

					//std::cout << "Done! S: " << S << ", E: " << E << ", Sum: " << Sum << std::endl;

					if (Sum > Max)
						Max = Sum;
					else
						break;
				}
			}
			std::cout << Max << std::endl;
		}
		else
		{
			// 2번 쿼리
			--A;
			int Diff = B - K[A];
			K[A] = B;
			int index = A + SegmentTree.size() / 2;

			while (index != 0)
			{
				SegmentTree[index] += Diff;
				index /= 2;
			}

			//Print(SegmentTree);
		}
	}
}