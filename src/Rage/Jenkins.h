#pragma once

#include <Windows.h>

namespace Rage {

    typedef UINT32 JOAAT;

    inline consteval JOAAT CalcJenkinsOne(const std::span<const CHAR>& szData) {
        JOAAT uHash = 0;
        for (size_t i = 0; i < szData.size() - 1; ++i) {
            uHash += szData[i];
            uHash += uHash << 10;
            uHash ^= uHash >> 6;
        }
        uHash += uHash << 3;
        uHash ^= uHash >> 11;
        uHash += uHash << 15;
        return uHash;
    }

}

#define JENKINS_HASH(szData) Rage::CalcJenkinsOne(szData)
