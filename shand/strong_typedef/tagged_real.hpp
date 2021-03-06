#ifndef SHAND_TAGGED_REAL_INCLUDE
#define SHAND_TAGGED_REAL_INCLUDE

// strong typedef for floating point types.
//
// Copyright Akira Takahashi 2012
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <boost/type_traits/is_floating_point.hpp>
#include <boost/static_assert.hpp>
#include <boost/operators.hpp>
#include <boost/geometry/util/math.hpp>

namespace shand {

template <class FloatingPoint, class Tag>
class tagged_real :
        private boost::operators<tagged_real<FloatingPoint, Tag> > {

    BOOST_STATIC_ASSERT(boost::is_floating_point<FloatingPoint>::value);

    FloatingPoint value_;
public:
    typedef FloatingPoint value_type;

    tagged_real(FloatingPoint value = 0) : value_(value) {}

    FloatingPoint& get() { return value_; }
    const FloatingPoint& get() const { return value_; }

    // operators
    bool operator<(const tagged_real& x) const { return value_ < x.value_; }
    tagged_real& operator+=(const tagged_real& x) { value_ += x.value_; return *this; }
    tagged_real& operator-=(const tagged_real& x) { value_ -= x.value_; return *this; }
    tagged_real& operator*=(const tagged_real& x) { value_ *= x.value_; return *this; }
    tagged_real& operator/=(const tagged_real& x) { value_ /= x.value_; return *this; }

    bool equals(const tagged_real& x) const
    {
        return boost::geometry::math::equals(value_, x.value_);
    }
};

} // namespace shand

#endif

