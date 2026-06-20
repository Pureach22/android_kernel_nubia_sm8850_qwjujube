__int64 __fastcall trace_event_raw_event_walt_newidle_balance(
        __int64 a1,
        unsigned int a2,
        int a3,
        int a4,
        char a5,
        char a6,
        __int64 a7)
{
  __int64 v10; // x8
  __int64 v14; // x9
  __int64 result; // x0
  int v16; // w9
  __int64 v17; // x9
  int v18; // w8
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v10 = a1;
  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v14 & 0x2C0) != 0 && (v14 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    v10 = a1;
    if ( (result & 1) != 0 )
      goto LABEL_8;
  }
  result = trace_event_buffer_reserve(v20, v10, 64);
  if ( !result )
    goto LABEL_8;
  *(_DWORD *)(result + 8) = a2;
  *(_DWORD *)(result + 12) = a3;
  *(_DWORD *)(result + 16) = a4;
  if ( a2 < 0x20 )
  {
    *(_DWORD *)(result + 20) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 4);
    *(_DWORD *)(result + 24) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 2640);
    v16 = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 3504);
    *(_BYTE *)(result + 32) = a5 & 1;
    *(_DWORD *)(result + 28) = v16;
    v17 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 3976);
    *(_BYTE *)(result + 48) = a6 & 1;
    *(_QWORD *)(result + 40) = v17;
    *(_DWORD *)(result + 52) = *(unsigned __int8 *)(*(_QWORD *)((char *)&runqueues
                                                              + *((_QWORD *)&_per_cpu_offset + a2)
                                                              + 3528)
                                                  + 40LL);
    if ( a7 )
      v18 = *(_DWORD *)(a7 + 1800);
    else
      v18 = -1;
    *(_DWORD *)(result + 56) = v18;
    result = trace_event_buffer_commit(v20);
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return perf_trace_walt_newidle_balance();
}
