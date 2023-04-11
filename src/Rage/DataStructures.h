#pragma once

#include <Windows.h>

namespace Rage {

	template <typename T>
	class Array {

	private:
		T* pData;
		UINT16 uSize;
		UINT16 uCapacity;

		// TODO implement methods when needed

	public:
		const T* begin() const {
			return pData;
		}
		const T* end() const {
			return pData + uSize;
		}
		T& operator[](UINT16 uIndex) const {
			return pData[uIndex];
		}

	};

	template <typename T>
	using PArray = Array<T>*;

}
