#include "stdafx.h"
#include "StringUtils.h"

// Метод возвращает количество вхождений искомой подстроки в переданный текст.
unsigned CStringUtils::Count(const std::string &text, const CSearchDFA &dfa)
{
	// TODO: реализовать метод
	(void)text;
	(void)dfa;
	throw std::runtime_error("not implemented");
}

// Метод определяет, содержится ли подстрока в тексте
bool CStringUtils::Contains(const std::string &text, const CSearchDFA &dfa)
{
	// TODO: реализовать метод
	(void)text;
	(void)dfa;
	throw std::runtime_error("not implemented");
}

// Метод находит все позиции вхождения подстроки в строку
// TODO: уточнить здесь, могут ли найденные вхождения пересекаться. Покрыть тестами.
std::vector<size_t> CStringUtils::FindAll(const std::string &text, const CSearchDFA &dfa)
{
	// TODO: реализовать метод
	(void)text;
	(void)dfa;
	throw std::runtime_error("not implemented");
}
