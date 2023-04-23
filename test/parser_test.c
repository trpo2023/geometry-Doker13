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

CTEST(TEST_first_bkt_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "1 1, 1)";
    int expectedresult = first_bkt_check(expectedword, expectedarg);
    int unexpectedresult = first_bkt_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_second_bkt_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1 1, 1";
    int expectedresult = second_bkt_check(expectedword, expectedarg);
    int unexpectedresult = second_bkt_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_arguments_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "( , )";
    int expectedresult = arguments_check(expectedword, expectedarg);
    int unexpectedresult = arguments_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_range_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1) ";
    char* unexpectedarg = "(1 1, 1)1ds23";
    int expectedresult = range_check(expectedword, expectedarg);
    int unexpectedresult = range_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_argument_field_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1 1dsf, 1)";
    int expectedresult = argument_field_check(expectedword, expectedarg);
    int unexpectedresult = argument_field_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_point_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1.1 11.1, 1..1)";
    int expectedresult = point_check(expectedword, expectedarg);
    int unexpectedresult = point_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_comma_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1, 1, 1)";
    int expectedresult = comma_check(expectedword, expectedarg);
    int unexpectedresult = comma_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}

CTEST(TEST_amount_of_arguments_check, arguments)
{
    char* expectedword = "circle";
    char* unexpectedword = "circle";
    char* expectedarg = "(1 1, 1)";
    char* unexpectedarg = "(1 1, 1 1)";
    int expectedresult = amount_of_arguments_check(expectedword, expectedarg);
    int unexpectedresult = amount_of_arguments_check(unexpectedword, unexpectedarg);
    ASSERT_EQUAL(1, expectedresult);
    ASSERT_EQUAL(0, unexpectedresult);
}
