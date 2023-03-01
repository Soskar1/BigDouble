#pragma once

#include <string>
#include <sstream>

namespace Big {
	class BigInt {
	private:
		std::stringstream m_Buffer;

		void UpdateBuffer(const std::string& newBuffer);
	public:
		BigInt();

		BigInt(const std::string& buffer);

		BigInt operator+(const BigInt& bigInt) const;

		BigInt operator+(bool& memory) const;

		std::string ToString() const;
	};
}