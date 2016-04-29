#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include <sstream>
#include "PrefixFunction.h"
#include <boost/algorithm/string.hpp>

using std::vector;
using std::string;

BOOST_AUTO_TEST_SUITE(StringUtils_class)

BOOST_AUTO_TEST_CASE(test)
{
	const std::string needle = "ax";
	const std::string text = "axdaxabxo!";
	CSearchDFA dfa;
	dfa.Compile(needle);
	BOOST_CHECK_EQUAL(dfa.Find(text), 0);
}

BOOST_AUTO_TEST_CASE(test2)
{
	const std::string needle = "ax";
	const std::string text = "axdaxabxo!";
	CSearchDFA dfa;
	dfa.Compile(needle);
	BOOST_CHECK_EQUAL(dfa.Find(text, 1), 3);
}

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
		std::vector<int> prefixFunctionsResult = { 0, 0, 0, 1, 2, 3, 0 };
		BOOST_REQUIRE_EQUAL(prefixFunctions.size(), prefixFunctionsResult.size());
		ChekValueVectors(prefixFunctions, prefixFunctionsResult);
	}
	BOOST_AUTO_TEST_CASE(can_return_vector_empty)
	{
		std::vector<int> prefixFunctions = GetSearchPrefixFunctions("abcabcd");
		std::vector<int> prefixFunctionsResult = { 0, 0, 0, 1, 2, 3, 0 };
		BOOST_REQUIRE_EQUAL(prefixFunctions.size(), prefixFunctionsResult.size());
		ChekValueVectors(prefixFunctions, prefixFunctionsResult);
	}

	BOOST_AUTO_TEST_CASE(func_returns_exception_if_string_size_more_1000_chars)
	{
		std::vector<int> prefixFunctions;
		std::string testStr = "В совреsменном русском языке слово „мир“ имеет два разных значения, „мир“ — антоним к слову „война“ и „мир“ — планета, община, общество, окружающий мир, место обитания (ср. „На миру и смерть красна“). До орфографической реформы 1917—1918 годов эти два понятия имели различное написание: в первом значении писалось „миръ“, во втором — „міръ“. Существует легенда, что Толстой якобы использовал в названии слово „міръ“ (Вселенная, общество). Однако все прижизненные издания романа Толстого выходили под названием „Война и миръ“, и сам он писал ljjjВ совреsменном русском языке слово „мир“ имеет два разных значения, „мир“ — антоним к слову „война“ и „мир“ — планета, община, общество, окружающий мир, место обитания (ср. „На миру и смерть красна“). До орфографической реформы 1917—1918 годов эти два понятия имели различное написание: в первом значении писалось „миръ“, во втором — „міръ“. Существует легенда, что Толстой якобы использовал в названии слово „міръ“ (Вселенная, общество). Однако все прижизненные издания романа Толстого выходили под названием „Война и миръ“, и сам он писал ljjj";
		BOOST_REQUIRE(testStr.size() > 1000);
		BOOST_CHECK_THROW(prefixFunctions = GetSearchPrefixFunctions(testStr), std::out_of_range);
	}
	
	BOOST_AUTO_TEST_CASE(can_returns_prefix_func_with_size_equal_1000_char)
	{
		std::string textString;
		for (int i = 0; i < 1000; ++i)
		{
			textString += "a";
		}

		std::vector<int> prefixFunctionsResult;
		for (int i = 0; i < 1000; ++i)
		{
			prefixFunctionsResult.push_back(i);
		}

		ChekValueVectors(GetSearchPrefixFunctions(textString), prefixFunctionsResult);
	}

	BOOST_AUTO_TEST_CASE(can_returns_position_substring)
	{
		CSearchDFA dfa;
		dfa.Compile("abc");
		size_t truePosition = 3;
		BOOST_CHECK_EQUAL(dfa.Find("abcabcabcabc", 3), truePosition);
	}

	BOOST_AUTO_TEST_SUITE_END()
