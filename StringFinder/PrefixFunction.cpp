#include "stdafx.h"
#include "PrefixFunction.h"

std::vector<int> GetSearchPrefixFunctions(const std::string &needle)
{
	if (needle.size() > 1000)
	{
		throw std::out_of_range("Input string size should be less than 1000 chars.");
	}

	std::vector<int> result(needle.size(), 0);

	if (needle.size() != 0)
	{

		for (size_t i = 1; i < needle.size(); ++i)
		{

			size_t j = result[i - 1];

			while (j > 0 && needle[i] != needle[j])
			{
				j = result[j - 1];
			}

			if (needle[i] == needle[j])
			{
				++j;
			}

			result[i] = j;
		}
	}

	return result;
}

