#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include <sstream>
#include "PrefixFunction.h"
#include <boost/algorithm/string.hpp>

using std::vector;
using std::string;

BOOST_AUTO_TEST_SUITE(StringUtils_class)
	BOOST_AUTO_TEST_CASE(can_check_if_contains)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		BOOST_CHECK(CStringUtils::Contains(text, dfa));
	}

	BOOST_AUTO_TEST_CASE(can_count_all_matches)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		unsigned count = CStringUtils::Count(text, dfa);
		BOOST_CHECK_EQUAL(count, 2);
	}

	BOOST_AUTO_TEST_CASE(can_find_all_matches)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		std::vector<size_t> matches = CStringUtils::FindAll(text, dfa);
		std::vector<size_t> expected = {0, 3};
		BOOST_CHECK(matches == expected);
		
	}
	void ChekValueVectors(std::vector<int> &prefixFunctions, std::vector<int> &result)
	{
		for (size_t i = 0; i < prefixFunctions.size(); ++i)
		{
			BOOST_REQUIRE_EQUAL(prefixFunctions[i], result[i]);
		}
	}

	BOOST_AUTO_TEST_CASE(can_return_vector_prefix_functions)
	{
		std::vector<int> prefixFunctions = GetSearchPrefixFunctions("abcabcd");
		std::vector<int> prefixFunctionsResault = { 0, 0, 0, 1, 2, 3, 0 };
		BOOST_REQUIRE_EQUAL(prefixFunctions.size(), prefixFunctionsResault.size());
		ChekValueVectors(prefixFunctions, prefixFunctionsResault);
	}
	BOOST_AUTO_TEST_CASE(can_return_vector_empty)
	{
		std::vector<int> prefixFunctions = GetSearchPrefixFunctions("abcabcd");
		std::vector<int> prefixFunctionsResault = { 0, 0, 0, 1, 2, 3, 0 };
		BOOST_REQUIRE_EQUAL(prefixFunctions.size(), prefixFunctionsResault.size());
		ChekValueVectors(prefixFunctions, prefixFunctionsResault);
	}
	BOOST_AUTO_TEST_SUITE_END()