#include <stdbool.h>

#include "acutest.h"
#include "../src/sort.h"

#define SORT(phrase, alphabet) (sort_lexicographically(phrase, alphabet))
#define CHECK(phrase, alphabet) (check_lexicographical_order(phrase, alphabet))

#define STANDARD 	"abcdefghijklmnopqrstuvwxyz"
#define REVERSE		"zyxwvutsrqponmlkjihgfedcba"
#define QWERTY		"qwertyuiopasdfghjklzxcvbnm"

void test_empty_phrase(void)
{
	bool result;

	char phrase[] = "";
	SORT(phrase, STANDARD);
	result = CHECK(phrase, STANDARD);
	TEST_CHECK(result == true);
}

void test_one_char_phrase(void)
{
	bool result;

	char phrase1[] = "a";
	SORT(phrase1, STANDARD);
	result = CHECK(phrase1, STANDARD);
	TEST_CHECK(result == true);

	char phrase2[] = "A";
	SORT(phrase2, STANDARD);
	result = CHECK(phrase2, STANDARD);
	TEST_CHECK(result == true);

	char phrase3[] = "z";
	SORT(phrase3, REVERSE);
	result = CHECK(phrase3, REVERSE);
	TEST_CHECK(result == true);

	char phrase4[] = "Z";
	SORT(phrase4, QWERTY);
	result = CHECK(phrase4, QWERTY);
	TEST_CHECK(result == true);
}

void test_two_char_phrase_no_capital(void)
{
	bool result;

	char phrase1[] = "aa";
	SORT(phrase1, STANDARD);
	result = CHECK(phrase1, STANDARD);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"aa\"");
	TEST_MSG("Your output: \"%s\"", phrase1);

	char phrase2[] = "cg";
	SORT(phrase2, QWERTY);
	result = CHECK(phrase2, QWERTY);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"gc\"");
	TEST_MSG("Your output: \"%s\"", phrase2);

	char phrase3[] = "dv";
	SORT(phrase3, REVERSE);
	result = CHECK(phrase3, REVERSE);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"vd\"");
	TEST_MSG("Your output: \"%s\"", phrase3);
}

void test_two_char_phrase_capital(void)
{
	bool result;

	char phrase1[] = "aA";
	SORT(phrase1, STANDARD);
	result = CHECK(phrase1, STANDARD);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"Aa\"");
	TEST_MSG("Your output: \"%s\"", phrase1);

	char phrase2[] = "ba";
	SORT(phrase2, STANDARD);
	result = CHECK(phrase2, STANDARD);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"ab\"");
	TEST_MSG("Your output: \"%s\"", phrase2);

	char phrase3[] = "ms";
	SORT(phrase3, QWERTY);
	result = CHECK(phrase3, QWERTY);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"sm\"");
	TEST_MSG("Your output: \"%s\"", phrase3);

	char phrase4[] = "Lm";
	SORT(phrase4, REVERSE);
	result = CHECK(phrase4, REVERSE);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"mL\"");
	TEST_MSG("Your output: \"%s\"", phrase4);
}

void test_many_char_phrase(void)
{
	bool result;

	char phrase1[] = "HelloWorld";
	SORT(phrase1, STANDARD);
	result = CHECK(phrase1, STANDARD);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"deHllloorW\"");
	TEST_MSG("Your output: \"%s\"", phrase1);

	char phrase2[] = "poiuytrewq";
	SORT(phrase2, QWERTY);
	result = CHECK(phrase2, QWERTY);
	TEST_CHECK(result == true);
	TEST_MSG("Expected: \"qwertyuiop\"");
	TEST_MSG("Your output: \"%s\"", phrase2);
}

TEST_LIST = {
	{"empty_phrase", test_empty_phrase},
	{"one_char_phrase", test_one_char_phrase},
	{"two_char_phrase_no_capital", test_two_char_phrase_no_capital},
	{"two_char_phrase_capital", test_two_char_phrase_capital},
	{"many_char_phrase", test_many_char_phrase},
	{NULL, NULL}
};
