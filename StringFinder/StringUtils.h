#pragma once

class CSearchDFA;

class CStringUtils
{
public:
	CStringUtils() = delete;

	static unsigned Count(const std::string &text, const CSearchDFA &dfa);
	static bool Contains(const std::string &text, const CSearchDFA &dfa);
	static std::vector<size_t> FindAll(const std::string &text, const CSearchDFA &dfa);
};

