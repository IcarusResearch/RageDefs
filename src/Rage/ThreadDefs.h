#pragma once

#include <Windows.h>

#include "Jenkins.h"

namespace Rage {

	typedef enum class ThreadState : UINT32 {
		RUNNING,
		IDLE,
		KILLED
	} ThreadState, *PThreadState;

	typedef struct ThreadContext {
		UINT32 uThreadId;
		JOAAT uScriptHash;
		ThreadState eThreadState;
		BYTE padding[0x9C];
	} ThreadContext, *PThreadContext;

	static_assert(sizeof(ThreadContext) == 0xA8, "Rage::ThreadContext has wrong size");

	typedef class Thread {

	protected:
		// A Rage thread has 5 virtual functions, probably one of them is a destructor
		virtual ~Thread() = default;
		virtual void func1() = 0;
		virtual void func2() = 0;
		virtual void func3() = 0;
		virtual void func4() = 0;

	public:
		// vtable pointer				// 0x00
		ThreadContext threadContext;	// 0x08
		BYTE padding[0x70];				// 0xB0

	} Thread, *PThread;

	static_assert(sizeof(Thread) == 0x120, "Rage::Thread has wrong size");

	typedef struct TLSContext {
		BYTE padding0[0xB8];			// 0x000
		PVOID pUnk0;					// 0x0B8
		BYTE padding1[0x788];			// 0x0C0
		PThread pRageThread;			// 0x848
		BOOL bScriptThreadActive;		// 0x850
	} TLSContext, *PTLSContext;

	static_assert(sizeof(TLSContext) == 0x858, "Rage::TLSContext has wrong size");

}
