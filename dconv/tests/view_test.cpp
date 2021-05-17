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
#include <dconv/view.hpp>
 
// Libraries.
#include <gtest/gtest.h>

using dconv::View;

/**
 * @brief Test data.
 */
TEST (View, data)
{
    View view ("hello world");
    ASSERT_NE (view.data (), nullptr);
    ASSERT_EQ (*view.data (), 'h');
}

/**
 * @brief Test size.
 */
TEST (View, size)
{
    View view ("hello world");
    ASSERT_EQ (view.size (), 11);
}

/**
 * @brief Test peek.
 */
TEST (View, peek)
{
    View view ("hello world");
    ASSERT_EQ (view.size (), 11);
    ASSERT_EQ (view.peek (), 'h');
    ASSERT_EQ (view.size (), 11);
    ASSERT_EQ (view.peek (), 'h');
}

/**
 * @brief Test get.
 */
TEST (View, get)
{
    View view ("hello world");
    ASSERT_EQ (view.size (), 11);
    ASSERT_EQ (view.get (), 'h');
    ASSERT_EQ (view.size (), 10);
    ASSERT_EQ (view.peek (), 'e');
}

/**
 * @brief Test get.
 */
TEST (View, getIf)
{
    View view ("hello world");
    ASSERT_EQ (view.size (), 11);
    ASSERT_FALSE (view.getIf ('x'));
    ASSERT_EQ (view.size (), 11);
    ASSERT_TRUE (view.getIf ('h'));
    ASSERT_EQ (view.size (), 10);
    ASSERT_EQ (view.peek (), 'e');
}

/**
 * @brief main function.
 */
int main (int argc, char **argv)
{
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
