#pragma once

#include <functional>
#include <utility>

#include "DataStructures.h"
#include "Jenkins.h"
#include "ThreadDefs.h"

namespace Rage {

	PTLSContext GetCurrentTLSContext();

	PThread FindScriptThread(JOAAT threadHash, PArray<PThread> pThreads);

	template <typename CB, typename... Params>
	inline VOID ExecuteOnScriptThread(PThread pThread, CB&& fnCallback, Params&&... params) {
		PTLSContext pTLSCtx = GetCurrentTLSContext();
		PThread pOldThread = pTLSCtx->pRageThread;
		BOOL bOldScriptThreadActive = pTLSCtx->bScriptThreadActive;
		pTLSCtx->pRageThread = pThread;
		pTLSCtx->bScriptThreadActive = TRUE;
		std::invoke(std::forward<CB>(fnCallback), std::forward<Params>(params)...);
		pTLSCtx->pRageThread = pOldThread;
		pTLSCtx->bScriptThreadActive = bOldScriptThreadActive;
	}

}
