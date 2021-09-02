#include <stdbool.h>

#include "acutest.h"
#include "../src/sort.h"

#define CHECK(phrase, alphabet) (check_lexicographical_order(phrase, alphabet))

#define STANDARD 	"abcdefghijklmnopqrstuvwxyz"
#define REVERSE		"zyxwvutsrqponmlkjihgfedcba"
#define QWERTY		"qwertyuiopasdfghjklzxcvbnm"

void test_empty_phrase(void)
{
	bool result;

	result = CHECK("", STANDARD);
	TEST_CHECK(result == true);
}

void test_one_char_phrase(void)
{
	bool result;

	result = CHECK("a", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("A", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("z", REVERSE);
	TEST_CHECK(result == true);
	result = CHECK("Z", QWERTY);
	TEST_CHECK(result == true);
}

void test_two_char_phrase_no_capital(void)
{
	bool result;

	result = CHECK("aa", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("ab", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("ba", STANDARD);
	TEST_CHECK(result == false);
	result = CHECK("za", REVERSE);
	TEST_CHECK(result == true);
	result = CHECK("sm", QWERTY);
	TEST_CHECK(result == true);
	result = CHECK("lo", REVERSE);
	TEST_CHECK(result == false);
}

void test_two_char_phrase_capital(void)
{
	bool result;

	result = CHECK("AB", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("Ab", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("Aa", STANDARD);
	TEST_CHECK(result == true);
	result = CHECK("aA", STANDARD);
	TEST_CHECK(result == false);
	result = CHECK("zH", REVERSE);
	TEST_CHECK(result == true);
	result = CHECK("QW", QWERTY);
	TEST_CHECK(result == true);
}

void test_many_char_phrase(void)
{
	bool result;

	result = CHECK("HelloWorld", STANDARD);
	TEST_CHECK(result == false);
	result = CHECK("asdfghjkl", QWERTY);
	TEST_CHECK(result == true);
	result = CHECK("MerryChristmas", REVERSE);
	TEST_CHECK(result == false);
}

TEST_LIST = {
	{"empty_phrase", test_empty_phrase},
	{"one_char_phrase", test_one_char_phrase},
	{"two_char_phrase_no_capital", test_two_char_phrase_no_capital},
	{"two_char_phrase_capital", test_two_char_phrase_capital},
	{"many_char_phrase", test_many_char_phrase},
	{NULL, NULL}
};
