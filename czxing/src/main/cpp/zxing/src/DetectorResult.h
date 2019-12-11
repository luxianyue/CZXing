#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "ResultPoint.h"
#include "BitMatrix.h"

#include <vector>

namespace ZXing {

/**
* <p>Encapsulates the result of detecting a barcode in an image. This includes the raw
* matrix of black/white pixels corresponding to the barcode, and possibly points of interest
* in the image, like the location of finder patterns or corners of the barcode in the image.</p>
*
* @author Sean Owen
*/
class DetectorResult
{
	BitMatrix _bits;
	std::vector<ResultPoint> _points;

	DetectorResult(const DetectorResult&) = delete;
	DetectorResult& operator=(const DetectorResult&) = delete;

public:
	DetectorResult() = default;
	DetectorResult(DetectorResult&&) = default;
	DetectorResult& operator=(DetectorResult&&) = default;

	DetectorResult(std::vector<ResultPoint>&& points)
			: _points(std::move(points))
	{}

	DetectorResult(BitMatrix&& bits, std::vector<ResultPoint>&& points)
		: _bits(std::move(bits)), _points(std::move(points))
	{}

	const BitMatrix& bits() const { return _bits; }
	const std::vector<ResultPoint>& points() const { return _points; }

	bool isValid() const { return !_bits.empty(); }
};

} // ZXing
