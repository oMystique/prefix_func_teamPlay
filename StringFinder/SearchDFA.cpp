#include "stdafx.h"
#include "SearchDFA.h"

CSearchDFA::CSearchDFA()
{
}

CSearchDFA::~CSearchDFA()
{
}

void CSearchDFA::Compile(const std::string &needle)
{
	m_needle = needle;
	// TODO: реализовать "честную" компиляцию автомата с использованием префикс-функций.
}

size_t CSearchDFA::Find(const std::string &text, size_t from) const
{
	// TODO: реализовать метод "по-честному".

	// Подсказка: можно использовать boost::string_ref, чтобы не извлекать подстроку из текста.
	// Это позволит оптимизировать повторные вызовы Search на одной строке.
	
	return text.find(m_needle, from);
}
