#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include <boost/utility/string_ref.hpp>
#include < iostream>
// Метод возвращает количество вхождений искомой подстроки в переданный текст.
unsigned CStringUtils::Count(const std::string &text, const CSearchDFA &dfa)
{
	size_t shift = 0;
	unsigned count = 0;
	for (;;) {
		shift = dfa.Find(text, shift);
		if (shift == std::string::npos)
		{
			break;
		}
		++count;
		++shift;
	};
	return count;
}

// Метод определяет, содержится ли подстрока в тексте
bool CStringUtils::Contains(const std::string &text, const CSearchDFA &dfa)
{
	auto i = dfa.Find(text, 0);
	return (i < text.size());

}

// Метод находит все позиции вхождения подстроки в строку
// TODO: уточнить здесь, могут ли найденные вхождения пересекаться. Покрыть тестами.
std::vector<size_t> CStringUtils::FindAll(const std::string &text, const CSearchDFA &dfa)
{
	std::vector<size_t> positions;
	size_t shift = 0;
	for (;;) {
		shift = dfa.Find(text, shift);
		if (shift == std::string::npos)
		{
			break;
		}
		positions.push_back(shift);
		++shift;
	};
	return positions;
}

//// TODO: реализовать метод
//(void)text;
//(void)dfa;
//throw std::runtime_error("not implemented");
