#include <intrin.h>
#include "stdcore.h"

#define TICK_FUNC_CLOCKS 20

extern "C"
{
    void begin_tick(U64 *tick)
    {
        *tick = __rdtsc();
    }

    void end_tick(U64 *tick)
    {
        *tick -= __rdtsc() - TICK_FUNC_CLOCKS;
    }

    XCORE_API U32 __regcall(1) fstrlen(CC8 *str)
    {
        return strlen(str);
    }

    XCORE_API U32 __regcall(1) _bsf(U32 value)
    {
        U32 index = 0;
        _BitScanForward(&index, value);
        return index;
    }
}
