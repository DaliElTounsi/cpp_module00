#include <cctype>
#include <iostream>

std::string toUpper(const std::string &str)
{
	std::string result = str;
	for (size_t i = 0; i < result.size(); i++)
		result[i] = std::toupper(result[i]);
	return (result);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
		std::cout << toUpper(av[i]);
	std::cout << std::endl;
	return 0;
}
