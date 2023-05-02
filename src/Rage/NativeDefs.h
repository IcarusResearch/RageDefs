#pragma once

#include <Windows.h>

namespace Rage {

	typedef struct Vec3F {
		alignas(0x08) FLOAT x;
		alignas(0x08) FLOAT y;
		alignas(0x08) FLOAT z;
	} Vec3F, *PVec3F;

	typedef struct alignas(0x10) Vec3FA {
		FLOAT x;
		FLOAT y;
		FLOAT z;
	} Vec3FA, *PVec3FA;

	typedef struct NativeCallContext {
		PVOID pReturnValue;					// 0x00
		UINT32 uParamCount;					// 0x08
		PVOID pParams;						// 0x10
		UINT32 uDataCount;					// 0x18
		PVec3F vecsOut[0x04];				// 0x20
		Vec3FA vecsIn[0x04];				// 0x40
		BYTE padding[0x60];					// 0x80
	} NativeCallContext, *PNativeCallContext;

	typedef INT64 NATIVEHASH;

	using NativeHandler = VOID(*)(PNativeCallContext);
	using GetNativeHandler = NativeHandler(*)(PVOID, NATIVEHASH);
	using FixVectors = VOID(*)(PNativeCallContext);

	#define NATIVE_CALL __forceinline

}
