/*
 * Copyright (C) 2018 The Android Open Source Project
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

#ifndef IMAGE_IMAGEOPS_H
#define IMAGE_IMAGEOPS_H

#include <image/LinearImage.h>

#include <initializer_list>

namespace image {

// Concatenates images horizontally to create a filmstrip atlas, similar to numpy's hstack.
LinearImage hstack(std::initializer_list<LinearImage> images);
LinearImage hstack(LinearImage const* img, size_t count);

// Concatenates images vertically to create a filmstrip atlas, similar to numpy's vstack.
LinearImage vstack(std::initializer_list<LinearImage> images);
LinearImage vstack(LinearImage const* img, size_t count);

// Transforms normals (components live in [-1,+1]) into colors (components live in [0,+1]).
LinearImage vectorsToColors(const LinearImage& image);

// Constructs a multi-channel image by copying data from a sequence of single-channel images.
LinearImage combineChannels(std::initializer_list<LinearImage> images);
LinearImage combineChannels(LinearImage const* img, size_t count);

// Generates a new image with rows & columns swapped.
LinearImage transpose(const LinearImage& image);

// Extracts pixels by specifying a crop window where (0,0) is the top-left corner of the image.
// The boundary is specified as Left Top Right Bottom.
LinearImage cropRegion(const LinearImage& image, uint32_t l, uint32_t t, uint32_t r, uint32_t b);

} // namespace image

#endif /* IMAGE_LINEARIMAGE_H */
