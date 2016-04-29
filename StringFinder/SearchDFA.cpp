#include "stdafx.h"
#include "SearchDFA.h"
#include "PrefixFunction.h"
#include <iostream>
CSearchDFA::CSearchDFA()
{
}

CSearchDFA::~CSearchDFA()
{
}

void CSearchDFA::Compile(const std::string &needle)
{
	m_needle = needle;
	auto tempAlph = GetSearchPrefixFunctions(needle);
	m_alphabet.push_back(-1);
	for (auto &it : tempAlph)
	{
		m_alphabet.push_back(it);
	}

	// TODO: ����������� "�������" ���������� �������� � �������������� �������-�������.
}

size_t CSearchDFA::Find(const std::string &text, size_t from) const
{
	auto needleTxt = text.substr(from);
	size_t foundPos = std::string::npos;
	// TODO: ����������� ����� "��-��������".
	size_t x = 0;
	int y = 0;
	while (x < needleTxt.size())
	{
		while (y > -1 && m_needle[y] != needleTxt[x])
		{
			y = m_alphabet[y];
		}
		x++;
		y++;
		if (size_t(y) >= m_needle.size())
		{
			if (foundPos == std::string::npos)
			{
				foundPos = from + x - size_t(y);
			}
			break;
		}
		// ���������: ����� ������������ boost::string_ref, ����� �� ��������� ��������� �� ������.
		// ��� �������� �������������� ��������� ������ Search �� ����� ������.
	}
	return foundPos;
}
