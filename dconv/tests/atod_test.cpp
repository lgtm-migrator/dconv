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
#include <dconv/atod.hpp>

// libraries.
#include <gtest/gtest.h>

/**
 * @brief atod test.
 */
TEST (dconv, atod)
{
    double value;

    ASSERT_NE (dconv::atod ("0.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.0);

    ASSERT_NE (dconv::atod ("-0.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -0.0);

    ASSERT_NE (dconv::atod ("1.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.0);

    ASSERT_NE (dconv::atod ("-1.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1.0);

    ASSERT_NE (dconv::atod ("1.5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.5);

    ASSERT_NE (dconv::atod ("-1.5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1.5);

    ASSERT_NE (dconv::atod ("3.1416", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 3.1416);

    ASSERT_NE (dconv::atod ("1E10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1E10);

    ASSERT_NE (dconv::atod ("1e10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1e10);

    ASSERT_NE (dconv::atod ("1E+10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1E+10);

    ASSERT_NE (dconv::atod ("1E-10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1E-10);

    ASSERT_NE (dconv::atod ("-1E10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1E10);

    ASSERT_NE (dconv::atod ("-1e10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1e10);

    ASSERT_NE (dconv::atod ("-1E+10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1E+10);

    ASSERT_NE (dconv::atod ("-1E-10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1E-10);

    ASSERT_NE (dconv::atod ("1.234E+10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.234E+10);

    ASSERT_NE (dconv::atod ("1.234E-10", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.234E-10);

    ASSERT_NE (dconv::atod ("1.79769e+308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.79769e+308);

    //ASSERT_NE (dconv::atod ("2.22507e-308", value), nullptr);
    //EXPECT_DOUBLE_EQ (value, 2.22507e-308);

    ASSERT_NE (dconv::atod ("-1.79769e+308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -1.79769e+308);

    //ASSERT_NE (dconv::atod ("-2.22507e-308", value), nullptr);
    //EXPECT_DOUBLE_EQ (value, -2.22507e-308);

    ASSERT_NE (dconv::atod ("-4.9406564584124654e-324", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -4.9406564584124654e-324);

    ASSERT_NE (dconv::atod ("2.2250738585072009e-308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 2.2250738585072009e-308);

    ASSERT_NE (dconv::atod ("2.2250738585072014e-308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 2.2250738585072014e-308);

    ASSERT_NE (dconv::atod ("1.7976931348623157e+308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.7976931348623157e+308);

    ASSERT_NE (dconv::atod ("1e-10000", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.0);

    ASSERT_NE (dconv::atod ("18446744073709551616", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 18446744073709551616.0);

    ASSERT_NE (dconv::atod ("-9223372036854775809", value), nullptr);
    EXPECT_DOUBLE_EQ (value, -9223372036854775809.0);

    ASSERT_NE (dconv::atod ("0.9868011474609375", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.9868011474609375);

    ASSERT_NE (dconv::atod ("123e34", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 123e34);

    ASSERT_NE (dconv::atod ("45913141877270640000.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 45913141877270640000.0);

    ASSERT_NE (dconv::atod ("2.2250738585072011e-308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 2.2250738585072011e-308);

    ASSERT_NE (dconv::atod ("1e-214748363", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.0);

    ASSERT_NE (dconv::atod ("1e-214748364", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.0);

    ASSERT_NE (dconv::atod ("0.017976931348623157e+310", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.7976931348623157e+308);

    ASSERT_NE (dconv::atod ("2.2250738585072012e-308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 2.2250738585072014e-308);

    ASSERT_NE (dconv::atod ("0.999999999999999944488848768742172978818416595458984375", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.0);

    ASSERT_NE (dconv::atod ("0.999999999999999944488848768742172978818416595458984374", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 0.99999999999999989);

    ASSERT_NE (dconv::atod ("0.999999999999999944488848768742172978818416595458984376", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.0);

    ASSERT_NE (dconv::atod ("1.00000000000000011102230246251565404236316680908203125", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.0);

    ASSERT_NE (dconv::atod ("1.00000000000000011102230246251565404236316680908203124", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.0);

    ASSERT_NE (dconv::atod ("1.00000000000000011102230246251565404236316680908203126", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1.00000000000000022);

    ASSERT_NE (dconv::atod ("72057594037927928.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 72057594037927928.0);

    ASSERT_NE (dconv::atod ("72057594037927936.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 72057594037927936.0);

    ASSERT_NE (dconv::atod ("72057594037927932.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 72057594037927936.0);

    ASSERT_NE (dconv::atod ("7205759403792793199999e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 72057594037927928.0);

    ASSERT_NE (dconv::atod ("7205759403792793200001e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 72057594037927936.0);

    ASSERT_NE (dconv::atod ("9223372036854774784.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 9223372036854774784.0);

    ASSERT_NE (dconv::atod ("9223372036854775808.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 9223372036854775808.0);

    ASSERT_NE (dconv::atod ("9223372036854775296.0", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 9223372036854775808.0);

    ASSERT_NE (dconv::atod ("922337203685477529599999e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 9223372036854774784.0);

    ASSERT_NE (dconv::atod ("922337203685477529600001e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 9223372036854775808.0);

    ASSERT_NE (dconv::atod ("10141204801825834086073718800384", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 10141204801825834086073718800384.0);

    ASSERT_NE (dconv::atod ("10141204801825835211973625643008", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 10141204801825835211973625643008.0);

    ASSERT_NE (dconv::atod ("10141204801825834649023672221696", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 10141204801825835211973625643008.0);

    ASSERT_NE (dconv::atod ("1014120480182583464902367222169599999e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 10141204801825834086073718800384.0);

    ASSERT_NE (dconv::atod ("1014120480182583464902367222169600001e-5", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 10141204801825835211973625643008.0);

    ASSERT_NE (dconv::atod ("5708990770823838890407843763683279797179383808", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 5708990770823838890407843763683279797179383808.0);

    ASSERT_NE (dconv::atod ("5708990770823839524233143877797980545530986496", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 5708990770823839524233143877797980545530986496.0);

    ASSERT_NE (dconv::atod ("5708990770823839207320493820740630171355185152", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 5708990770823839524233143877797980545530986496.0);

    ASSERT_NE (dconv::atod ("5708990770823839207320493820740630171355185151999e-3", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 5708990770823838890407843763683279797179383808.0);

    ASSERT_NE (dconv::atod ("5708990770823839207320493820740630171355185152001e-3", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 5708990770823839524233143877797980545530986496.0);

    ASSERT_NE (dconv::atod ("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
                            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
                            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
                            "0000000000", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 1E308);

    ASSERT_NE (dconv::atod ("2.22507385850720113605740979670913197593481954635164564802342610972482222202107694551652952390813508"
                            "79141491589130396211068700864386945946455276572074078206217433799881410632673292535522868813721490129"
                            "81122451451889849057222307285255133155755015914397476397983411801999323962548289017107081850690630666"
                            "65599493827577257201576306269066333264756530000924588831643303777979186961204949739037782970490505108"
                            "06099407302629371289589500035837999672072543043602840788957717961509455167482434710307026091446215722"
                            "89880258182545180325707018860872113128079512233426288368622321503775666622503982534335974568884423900"
                            "26549819838548794829220689472168983109969836584681402285424333066033985088644580400103493397042756718"
                            "6443383770486037861622771738545623065874679014086723327636718751234567890123456789012345678901e-308", value), nullptr);
    EXPECT_DOUBLE_EQ (value, 2.2250738585072014e-308);
}

/**
 * @brief main function.
 */
int main (int argc, char **argv)
{
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
