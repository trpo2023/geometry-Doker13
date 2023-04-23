#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/parser.h>

#include <ctest.h>

CTEST(TEST_word_check, circle)
{
    char* expectedword = "circle";
    char* unexpectedword = "circlte";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1 1, 1)";
    int expectedresult = word_check(expectedword, expectedarg);
    int unexpectedresult = word_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}
