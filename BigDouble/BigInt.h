#pragma once

#include <string>
#include <sstream>
#include <algorithm>

namespace Big {
	class BigInt {
	private:
		std::stringstream m_Buffer;

		void SetBuffer(const std::string& newBuffer);
	public:
		BigInt();

		BigInt(const std::string& buffer);

		BigInt operator+(const BigInt& bigInt) const;

		BigInt operator+(bool& memory) const;

		BigInt operator-(const BigInt& bigInt) const;

		BigInt operator-(bool& memory) const;

		bool operator<(const BigInt& bigInt) const;

		std::string ToString() const;
	};
}