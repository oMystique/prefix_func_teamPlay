#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include <boost/utility/string_ref.hpp>
#include < iostream>
// ����� ���������� ���������� ��������� ������� ��������� � ���������� �����.
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

// ����� ����������, ���������� �� ��������� � ������
bool CStringUtils::Contains(const std::string &text, const CSearchDFA &dfa)
{
	auto i = dfa.Find(text, 0);
	return (i < text.size());

}

// ����� ������� ��� ������� ��������� ��������� � ������
// TODO: �������� �����, ����� �� ��������� ��������� ������������. ������� �������.
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

//// TODO: ����������� �����
//(void)text;
//(void)dfa;
//throw std::runtime_error("not implemented");
