// Copyright (c) 2011, Hauke Strasdat
// Copyright (c) 2012, Steven Lovegrove
// Copyright (c) 2021, farm-ng, inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "sophus/image/image_size.h"

namespace sophus {

bool ImageSize::contains(const Eigen::Vector2i& obs, int border) const {
  return obs.x() >= border && obs.x() < this->width - border &&
         obs.y() >= border && obs.y() < this->height - border;
}

bool ImageSize::contains(const Eigen::Vector2d& obs, double border) const {
  return obs.x() >= -0.5 + border && obs.x() <= this->width - 0.5 - border &&
         obs.y() >= -0.5 + border && obs.y() <= this->height - 0.5 - border;
}

bool ImageSize::contains(const Eigen::Vector2f& obs, float border) const {
  return obs.x() >= -0.5f + border && obs.x() <= this->width - 0.5f - border &&
         obs.y() >= -0.5f + border && obs.y() <= this->height - 0.5f - border;
}
ImageSize half(ImageSize image_size) {
  return ImageSize((image_size.width + 1) / 2, (image_size.height + 1) / 2);
}

bool operator==(const ImageSize& lhs, const ImageSize& rhs) {
  return lhs.width == rhs.width && lhs.height == rhs.height;
}
bool operator<(const ImageSize& lhs, const ImageSize& rhs) {
  return std::make_pair(lhs.width, lhs.height) <
         std::make_pair(rhs.width, rhs.height);
}

std::ostream& operator<<(std::ostream& os, const ImageSize& image_size) {
  os << "[" << image_size.width << " x " << image_size.height << "]";
  return os;
}

bool operator==(const ImageShape& lhs, const ImageShape& rhs) {
  return lhs.imageSize() == rhs.imageSize() &&
         lhs.pitchBytes() == rhs.pitchBytes();
}

std::ostream& operator<<(std::ostream& os, const ImageShape& shape) {
  os << "[" << shape.imageSize() << ", pitch: " << shape.pitchBytes() << "]";
  return os;
}

}  // namespace sophus