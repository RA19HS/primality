#include "number.h"
#include <numeric>
#include <functional>
#include <string>
#include <cassert>

Number::Number(size_t number) {
	n.resize(max_length);
	for (int i = 0; number; ++i, number >>= 1)
		n[i] = number & 1;
}

Number& Number::operator++() {
	++n[0];
	for (size_t i = 0; i + 1 < n.size(); ++i)
		if (n[i] == 2) {
			n[i] = 0;
			++n[i + 1];
		}
		else
			break;
	return *this;
}

Number Number::operator+(const Number &m) const {
	Number res;
	res.n = n + m.n;
	int carry = 0;
	for (size_t i = 0; i + 1 < res.n.size(); ++i) {
		carry = res.n[i];
		res.n[i] &= 1;
		carry -= res.n[i];
		res.n[i + 1] += (bool)carry;
	}
	assert(!carry);
	return res;
}

bool Number::operator==(const Number &m) const {
	return (n == m.n).min();
}

std::string Number::string() const {
	std::string result;
	for (int i = 0; i < length(); ++i)
		result = std::to_string(n[i]) + result;
	return result;
}

size_t Number::length() const {
	int i = n.size() - 1;
	for (; i + 1; --i)
		if (n[i])
			break;
	return std::max(1, ++i);
}
