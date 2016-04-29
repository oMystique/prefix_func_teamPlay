#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include <boost/utility/string_ref.hpp>

// Метод возвращает количество вхождений искомой подстроки в переданный текст.
unsigned CStringUtils::Count(const std::string &text, const CSearchDFA &dfa)
{
	size_t shift = 0;
	size_t count = 0;
	do
	{
		shift = dfa.Find(text, shift);
		if (shift < text.size())
		{
			count++;
		}
	} while (shift < text.size());
	
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
	do
	{
		shift = dfa.Find(text, shift);
		if (shift < text.size())
		{
			positions.push_back(shift);
		}
	} while (shift < text.size());
	return positions;
}

//// TODO: реализовать метод
//(void)text;
//(void)dfa;
//throw std::runtime_error("not implemented");
