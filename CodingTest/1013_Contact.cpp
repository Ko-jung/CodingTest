//https://www.notion.so/1b3a80bf7dba8032a748f20bd24b2bc8?pvs=4
// https://www.notion.so/C-11-Regex-1b3a80bf7dba80769711f197ca64a901?pvs=4
// 알고리즘을 위한 정규 표현식 공부

#include <iostream>
#include <string>
#include <vector>
#include <regex>

int main()
{
	int T;
	std::cin >> T;

	std::vector<std::string> Strings;
	for (int i = 0; i < T; i++)
	{
		std::string str;
		std::cin >> str;
		Strings.emplace_back(str);
	}

	std::regex re("(100+1+|01)+");
	for (const auto& str : Strings)
	{
		std::cout << (std::regex_match(str, re) ? "YES" : "NO") << std::endl;
	}
}