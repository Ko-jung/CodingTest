//Day Of Mourning의 기타리스트 강토가 사용하는 기타에서 N개의 줄이 끊어졌다.
// 따라서 새로운 줄을 사거나 교체해야 한다.강토는 되도록이면 돈을 적게 쓰려고 한다
// 6줄 패키지를 살 수도 있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.
//
//끊어진 기타줄의 개수 N과 기타줄 브랜드 M개가 주어지고,
// 각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격,
// 낱개로 살 때의 가격이 주어질 때,
// 적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램을 작성하시오.

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