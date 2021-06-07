/**
 * MIT License
 *
 * Copyright (c) 2021 Mathieu Rabine
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// dconv.
#include <dconv/dtoa.hpp>

// libraries.
#include <gtest/gtest.h>

/**
 * @brief dtoa test.
 */
TEST (dconv, dtoa)
{
    char dbl [25];

    char* end = dconv::dtoa (dbl, std::numeric_limits <double>::quiet_NaN ());
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "NaN");

    end = dconv::dtoa (dbl, std::numeric_limits <double>::infinity ());
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "Inf");

    end = dconv::dtoa (dbl, -std::numeric_limits <double>::infinity ());
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-Inf");

    end = dconv::dtoa (dbl, 0.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.0");

    end = dconv::dtoa (dbl, -0.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-0.0");

    end = dconv::dtoa (dbl, 0.1);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.1");

    end = dconv::dtoa (dbl, 0.12);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.12");

    end = dconv::dtoa (dbl, 0.123);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.123");

    end = dconv::dtoa (dbl, 0.1234);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.1234");

    end = dconv::dtoa (dbl, 1.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.0");

    end = dconv::dtoa (dbl, 1.1234);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.1234");

    end = dconv::dtoa (dbl, 1.5);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.5");

    end = dconv::dtoa (dbl, -1.5);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-1.5");

    end = dconv::dtoa (dbl, 3.1416);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "3.1416");

    end = dconv::dtoa (dbl, 1E10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "10000000000.0");

    end = dconv::dtoa (dbl, 1e10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "10000000000.0");

    end = dconv::dtoa (dbl, 1E+10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "10000000000.0");

    end = dconv::dtoa (dbl, 1E-10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1e-10");

    end = dconv::dtoa (dbl, -1E10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-10000000000.0");

    end = dconv::dtoa (dbl, -1e10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-10000000000.0");

    end = dconv::dtoa (dbl, -1E+10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-10000000000.0");

    end = dconv::dtoa (dbl, -1E-10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-1e-10");

    end = dconv::dtoa (dbl, 1.234E+10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "12340000000.0");

    end = dconv::dtoa (dbl, 1.234E-10);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.234e-10");

    end = dconv::dtoa (dbl, 1.79769e+308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.79769e308");

    end = dconv::dtoa (dbl, 2.22507e-308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "2.22507e-308");

    end = dconv::dtoa (dbl, -1.79769e+308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-1.79769e308");

    end = dconv::dtoa (dbl, -2.22507e-308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-2.22507e-308");

    end = dconv::dtoa (dbl, -4.9406564584124654e-324);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-5e-324");

    end = dconv::dtoa (dbl, 2.2250738585072009e-308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "2.225073858507201e-308");

    end = dconv::dtoa (dbl, 2.2250738585072014e-308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "2.2250738585072014e-308");

    end = dconv::dtoa (dbl, 1.7976931348623157e+308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.7976931348623157e308");

    end = dconv::dtoa (dbl, 18446744073709551616.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "18446744073709552000.0");

    end = dconv::dtoa (dbl, -9223372036854775809.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "-9223372036854776000.0");

    end = dconv::dtoa (dbl, 0.9868011474609375);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "0.9868011474609375");

    end = dconv::dtoa (dbl, 123e34);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.23e36");

    end = dconv::dtoa (dbl, 45913141877270640000.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "45913141877270640000.0");

    end = dconv::dtoa (dbl, 2.2250738585072011e-308);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "2.225073858507201e-308");

    end = dconv::dtoa (dbl, 72057594037927928.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "72057594037927930.0");

    end = dconv::dtoa (dbl, 72057594037927936.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "72057594037927940.0");

    end = dconv::dtoa (dbl, 72057594037927936.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "72057594037927940.0");

    end = dconv::dtoa (dbl, 9223372036854774784.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "9223372036854775000.0");

    end = dconv::dtoa (dbl, 9223372036854775808.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "9223372036854776000.0");

    end = dconv::dtoa (dbl, 10141204801825834086073718800384.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.0141204801825834e31");

    end = dconv::dtoa (dbl, 10141204801825835211973625643008.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "1.0141204801825835e31");

    end = dconv::dtoa (dbl, 5708990770823838890407843763683279797179383808.0);
    ASSERT_NE (end, nullptr);
    ASSERT_STREQ (dbl, "5.708990770823839e45");
}

/**
 * @brief main function.
 */
int main (int argc, char **argv)
{
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
