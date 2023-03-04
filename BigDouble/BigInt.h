#pragma once

#include <string>
#include <sstream>
#include <algorithm>

namespace Big {
	class BigInt {
	private:
		std::stringstream m_IntegralBuffer;
		std::string m_IntegralString;

		bool m_IsNegative = false;

		void UpdateBuffer();

		void SetIntegralBuffer(const std::string& newBuffer);

		void SetIsNegative(const bool& value);

		friend class BigDouble;
	public:
		BigInt();

		BigInt(const std::string& buffer);

		BigInt operator+(const BigInt& bigInt) const;

		BigInt operator-(const BigInt& bigInt) const;

		BigInt operator*(const BigInt& bigInt) const;

		BigInt& operator--();

		BigInt& operator++();

		BigInt& operator+=(const BigInt& bigInt);

		BigInt& operator*=(const BigInt& bigInt);

		BigInt operator-() const;

		bool operator<(const BigInt& bigInt) const;

		bool operator>(const BigInt& bigInt) const;

		bool operator<=(const BigInt& bigInt) const;

		bool operator>=(const BigInt& bigInt) const;

		bool operator==(const BigInt& bigInt) const;

		bool operator!=(const BigInt& bigInt) const;

		std::string ToString() const;
	};
}