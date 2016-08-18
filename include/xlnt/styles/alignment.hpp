// Copyright (c) 2014-2016 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file
#pragma once

#include <xlnt/xlnt_config.hpp>
#include <xlnt/utils/hash_combine.hpp>
#include <xlnt/styles/horizontal_alignment.hpp>
#include <xlnt/styles/vertical_alignment.hpp>
#include <xlnt/utils/hashable.hpp>
#include <xlnt/utils/optional.hpp>

namespace xlnt {

/// <summary>
/// Alignment options for use in cell formats.
/// </summary>
class XLNT_CLASS alignment : public hashable
{
public:
	optional<bool> shrink() const;

	alignment &shrink(bool shrink_to_fit);

    optional<bool> wrap() const;

	alignment &wrap(bool wrap_text);

	optional<int> indent() const;

	alignment &indent(int indent_size);

	optional<int> rotation() const;

	alignment &rotation(bool text_rotation);

    optional<horizontal_alignment> horizontal() const;

	alignment &horizontal(horizontal_alignment horizontal);

    optional<vertical_alignment> vertical() const;

    alignment &vertical(vertical_alignment vertical);

protected:
    std::string to_hash_string() const override;

private:
	optional<bool> shrink_to_fit_;
	optional<bool> wrap_text_;
	optional<int> indent_;
	optional<int> text_rotation_;
	optional<horizontal_alignment> horizontal_ = horizontal_alignment::general;
	optional<vertical_alignment> vertical_ = vertical_alignment::bottom;
};

} // namespace xlnt
