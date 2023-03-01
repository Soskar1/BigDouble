#pragma once

#include <string>
#include <sstream>

namespace Big {
	class BigInt {
	private:
		std::stringstream m_Buffer;

		bool m_Memory;

		const int ASCII_INT_DIFFERENCE = 48;

		void Addition(const BigInt& bigInt);
	public:
		BigInt(std::string buffer);

		BigInt operator+(const BigInt& bigInt) const;

		std::string ToString() const;
	};
}