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

#ifndef __DCONV_VIEW_HPP__
#define __DCONV_VIEW_HPP__

// C++.
#include <string>

// C.
#include <cstring>
#include <cstddef>

namespace dconv
{
    /**
     * @brief view.
     */
    class View
    {
    public:
        using ValueType     = char;
        using ConstPointer  = const ValueType*;
        using SizeType      = size_t;

        /**
         * @brief default constructor.
         * @param s pointer to a character array.
         * @param count number of characters in the sequence.
         */
        constexpr View (ConstPointer s, SizeType count)
        : _ptr (s),
          _len (count)
        {
        }

        /**
         * @brief default constructor.
         * @param s pointer to a character array.
         */
        constexpr View (ConstPointer s)
        : _ptr (s),
          _len (strlen (s))
        {
        }

        /**
         * @brief default constructor.
         * @param first pointer to the first character of the sequence.
         * @param last pointer to the last character of the sequence.
         */
        constexpr View (ConstPointer first, ConstPointer last)
        : _ptr (first),
          _len (last - first)
        {
        }

        /**
         * @brief copy constructor.
         * @param other object to copy.
         */
        constexpr View (const View& other) noexcept = default;

        /**
         * @brief copy assignment.
         * @param other object to copy.
         * @return a reference of the current object.
         */
        constexpr View& operator= (const View& other) noexcept = default;

        /**
         * @brief destroy instance.
         */
        virtual ~View () = default;

        /**
         * @brief returns a pointer to the first character of a view.
         * @return a pointer to the first character of a view.
         */
        constexpr ConstPointer data () const noexcept
        {
            return _ptr;
        }

        /**
         * @brief returns the number of characters in the view.
         * @return the number of characters in the view.
         */
        constexpr SizeType size () const noexcept
        {
            return _len;
        }

        /**
         * @brief get character without extracting it.
         * @return extracted character.
         */
        constexpr int peek () const noexcept
        {
            if (_len)
            {
                return *_ptr;
            }
            return std::char_traits <char>::eof ();
        }

        /**
         * @brief extracts character.
         * @return extracted character.
         */
        constexpr int get () noexcept
        {
            if (_len)
            {
                --_len;
                return *_ptr++;
            }
            return std::char_traits <char>::eof ();
        }

        /**
         * @brief extracts expected character.
         * @param expected expected character.
         * @return true if extracted, false otherwise.
         */
        constexpr bool getIf (char expected) noexcept
        {
            if (*_ptr == expected)
            {
                ++_ptr;
                --_len;
                return true;
            }
            return false;
        }

    protected:
        /// view start pointer.
        ConstPointer _ptr;

        /// view size.
        SizeType _len;
    };
}

#endif
