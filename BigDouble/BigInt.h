#pragma once

#include <string>
#include <sstream>
#include <algorithm>

namespace Big {
	class BigInt {
	private:
		std::stringstream m_IntegralBuffer;

		bool m_IsNegative = false;

		void SetBuffer(const std::string& newBuffer);

		bool GetIsNegative() const;

		void SetIsNegative(const bool& value);

		friend class BigDouble;
	public:
		BigInt();

		BigInt(const std::string& buffer);

		BigInt operator+(const BigInt& bigInt) const;

		BigInt operator+(bool& memory) const;

		BigInt operator-(const BigInt& bigInt) const;

		BigInt operator-(bool& memory) const;

		bool operator<(const BigInt& bigInt) const;

		bool operator==(const BigInt& bigInt) const;

		std::string ToString() const;
	};
}