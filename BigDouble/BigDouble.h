#pragma once

#include "BigInt.h"

namespace Big {
	class BigDouble {
	private:
		std::stringstream m_Buffer;
		std::string m_FractionalPart;

		BigInt m_IntegralPart;

		void UpdateBuffer();

		std::string GetFractionalPart() const;

	public:
		BigDouble();

		BigDouble(const std::string& buffer);

		BigDouble operator+(const BigDouble& bigDouble) const;

		std::string ToString() const;
	};
}