#include "stdafx.h"
#include "SearchDFA.h"
#include "PrefixFunction.h"

CSearchDFA::CSearchDFA()
{
}

CSearchDFA::~CSearchDFA()
{
}

//size_t GetBias(const char & symb, std::string const& str)
//{
//	size_t offset = str.size();
//	size_t symbPos = str.size();
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		if (str[i] == symb)
//		{
//			if (symbPos == str.size())
//			{
//				symbPos = i;
//				offset -= symbPos + 1;
//			}
//			else if (i - symbPos < offset)
//			{
//				offset = i - symbPos;
//			}
//		}
//	}
//	return offset;
//}

void CSearchDFA::Compile(const std::string &needle)
{
	m_needle = needle;
	auto tempAlph = GetSearchPrefixFunctions(needle);
	m_alphabet.push_back[-1];
	for (auto &it : tempAlph)
	{
		m_alphabet.push_back(it);
	}

	// TODO: ����������� "�������" ���������� �������� � �������������� �������-�������.
}

size_t CSearchDFA::Find(const std::string &text, size_t from) const
{
	auto needleTxt = text.substr(from);
	// TODO: ����������� ����� "��-��������".
	int x = 0;
	int y = 0;
	while (x < needleTxt.size()) {
		while (y > -1 && m_needle[y] != needleTxt[x])
		{
			y = m_alphabet[y];
		}
		x++;
		y++;
		if (y >= m_needle.size()) {
			return(x - y);
		}
		// ���������: ����� ������������ boost::string_ref, ����� �� ��������� ��������� �� ������.
		// ��� �������� �������������� ��������� ������ Search �� ����� ������.
	}
	return text.find(m_needle, from);
}
