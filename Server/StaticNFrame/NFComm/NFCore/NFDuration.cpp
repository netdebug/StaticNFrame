// -------------------------------------------------------------------------
//    @FileName         :    NFDuration.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/05/26
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFDuration.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
const int64_t NFDuration::kNanosecond = 1LL;
const int64_t NFDuration::kMicrosecond = 1000;
const int64_t NFDuration::kMillisecond = 1000 * 1000;
const int64_t NFDuration::kSecond = 1000 * 1000 * 1000;
const int64_t NFDuration::kMinute = 60 * 1000 * 1000 * 1000;
const int64_t NFDuration::kHour = 60 * 60 * 1000 * 1000 * 1000;
#endif

NFDuration::NFDuration()
	: ns_(0)
{
}

NFDuration::NFDuration(const struct timeval& t)
	: ns_(t.tv_sec * kSecond + t.tv_usec * kMicrosecond)
{
}

NFDuration::NFDuration(int64_t nanoseconds)
	: ns_(nanoseconds)
{
}

NFDuration::NFDuration(int nanoseconds)
	: ns_(nanoseconds)
{
}

NFDuration::NFDuration(double seconds)
	: ns_((int64_t)(seconds * kSecond))
{
}

int64_t NFDuration::Nanoseconds() const
{
	return ns_;
}

double NFDuration::Seconds() const
{
	return double(ns_) / kSecond;
}

double NFDuration::Milliseconds() const
{
	return double(ns_) / kMillisecond;
}

double NFDuration::Microseconds() const
{
	return double(ns_) / kMicrosecond;
}

double NFDuration::Minutes() const
{
	return double(ns_) / kMinute;
}

double NFDuration::Hours() const
{
	return double(ns_) / kHour;
}

bool NFDuration::IsZero() const
{
	return ns_ == 0;
}

struct timeval NFDuration::TimeVal() const
{
	struct timeval t;
	To(&t);
	return t;
}

void NFDuration::To(struct timeval* t) const
{
	t->tv_sec = (long)(ns_ / kSecond);
	t->tv_usec = (long)(ns_ % kSecond) / (long)kMicrosecond;
}

bool NFDuration::operator<(const NFDuration& rhs) const
{
	return ns_ < rhs.ns_;
}

bool NFDuration::operator<=(const NFDuration& rhs) const
{
	return ns_ <= rhs.ns_;
}

bool NFDuration::operator>(const NFDuration& rhs) const
{
	return ns_ > rhs.ns_;
}

bool NFDuration::operator>=(const NFDuration& rhs) const
{
	return ns_ >= rhs.ns_;
}

bool NFDuration::operator==(const NFDuration& rhs) const
{
	return ns_ == rhs.ns_;
}

NFDuration NFDuration::operator+=(const NFDuration& rhs)
{
	ns_ += rhs.ns_;
	return *this;
}

NFDuration NFDuration::operator-=(const NFDuration& rhs)
{
	ns_ -= rhs.ns_;
	return *this;
}

NFDuration NFDuration::operator*=(int n)
{
	ns_ *= n;
	return *this;
}

NFDuration NFDuration::operator/=(int n)
{
	ns_ /= n;
	return *this;
}
