//���� ������ ������ �׻� ū ��ĩ�Ÿ����� ���� �־���.
// �� ������ ���� �������� ������ ���� ������ ���� ū ����� �ɾ���.
//
//���̰� N�� ���� �迭 A�� B�� �ִ�.������ ���� �Լ� S�� ��������.
//S = A[0] �� B[0] + ... + A[N - 1] �� B[N - 1]
//S�� ���� ���� �۰� ����� ���� A�� ���� ��迭����.
// ��, B�� �ִ� ���� ��迭�ϸ� �� �ȴ�.
//
//S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <queue>

int main()
{
	int N;
	//std::vector<int> A, B;

	std::priority_queue<int> A;
	std::priority_queue<int, std::vector<int>, std::greater<int>> B;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int Temp;
		std::cin >> Temp;
		A.push(Temp);
	}
	for (int i = 0; i < N; i++)
	{
		int Temp;
		std::cin >> Temp;
		B.push(Temp);
	}

	int Sum = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		a = A.top(); A.pop();
		b = B.top(); B.pop();

		Sum += (a * b);
	}

	std::cout << Sum;
}