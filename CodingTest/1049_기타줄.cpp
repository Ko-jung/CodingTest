//Day Of Mourning�� ��Ÿ����Ʈ ���䰡 ����ϴ� ��Ÿ���� N���� ���� ��������.
// ���� ���ο� ���� ��ų� ��ü�ؾ� �Ѵ�.����� �ǵ����̸� ���� ���� ������ �Ѵ�
// 6�� ��Ű���� �� ���� �ְ�, 1�� �Ǵ� �� �̻��� ���� ������ �� ���� �ִ�.
//
//������ ��Ÿ���� ���� N�� ��Ÿ�� �귣�� M���� �־�����,
// ������ �귣�忡�� �Ĵ� ��Ÿ�� 6���� ����ִ� ��Ű���� ����,
// ������ �� ���� ������ �־��� ��,
// ��� N���� ��� ���� �ʿ��� ���� ���� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int M, N;
	std::cin >> N >> M;

	std::vector<int> PackageCost;
	std::vector<int> SoloCost;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		PackageCost.emplace_back(a);
		SoloCost.emplace_back(b);
	}

	int PackageMin = *std::min_element(PackageCost.begin(), PackageCost.end());
	int SoloMin = *std::min_element(SoloCost.begin(), SoloCost.end());

	int Cost = 0;
	int Share = N / 6;
	int Remainder = N % 6;
	if (PackageMin * Share < SoloMin * Share * 6)
	{
		Cost += (PackageMin * Share);
	}
	else
	{
		Cost += (SoloMin * Share * 6);
	}

	if (PackageMin < Remainder * SoloMin)
	{
		Cost += (PackageMin);
	}
	else
	{
		Cost += (Remainder * SoloMin);
	}

	std::cout << Cost << std::endl;
}