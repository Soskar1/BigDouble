#pragma once

#include "BigInt.h"

namespace Big {
	class BigDouble {
	private:
		std::stringstream m_Buffer;
		std::string m_FractionalPart;

		BigInt m_IntegralPart;

		bool m_IsNegative = false;

		void SetBuffer(const std::string& buffer);

		std::string GetFractionalPart() const;

		bool CheckForZeros(int startIndex) const;

	public:
		BigDouble();

		BigDouble(const std::string& buffer);

		BigDouble operator+(const BigDouble& bigDouble) const;

		BigDouble operator-(const BigDouble& bigDouble) const;

		std::string ToString() const;
	};
}