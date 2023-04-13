#include "ThreadUtils.h"

#include <intrin.h>

Rage::PTLSContext Rage::GetCurrentTLSContext() {
	return *reinterpret_cast<TLSContext**>(__readgsqword(0x58));
}

Rage::PThread Rage::FindScriptThread(JOAAT threadHash, PArray<PThread> pThreads) {
	for (PThread pThread : *pThreads) {
		if (pThread && pThread->threadContext.uThreadId && pThread->threadContext.uScriptHash == threadHash) {
			return pThread;
		}
	}
	return nullptr;
}
