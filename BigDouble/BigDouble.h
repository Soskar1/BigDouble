#pragma once

#include "BigInt.h"

namespace Big {
	class BigDouble{
	private:
		std::stringstream m_Buffer;
		std::string m_FractionalPart;

		BigInt m_IntegralPart;

		void UpdateBuffer();

		void SetFractionalBuffer(const std::string& buffer);

		std::string GetFractionalPart() const;

		bool IsNegative() const;

	public:
		BigDouble();

		BigDouble(const std::string& buffer);

		BigDouble operator+(const BigDouble& bigDouble) const;

		BigDouble operator-(const BigDouble& bigDouble) const;

		BigDouble operator*(const BigDouble& bigDouble) const;

		BigDouble operator-() const;

		BigDouble& operator--();

		BigDouble& operator++();

		BigDouble& operator+=(const BigDouble& bigDouble);

		bool operator<(const BigDouble& bigDouble) const;

		bool operator>(const BigDouble& bigDouble) const;

		bool operator<=(const BigDouble& bigDouble) const;

		bool operator>=(const BigDouble& bigDouble) const;

		bool operator==(const BigDouble& bigDouble) const;

		bool operator!=(const BigDouble& bigDouble) const;

		std::string ToString() const;
	};
}