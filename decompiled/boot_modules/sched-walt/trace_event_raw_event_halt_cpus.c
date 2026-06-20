__int64 __fastcall trace_event_raw_event_halt_cpus(__int64 a1, __int64 *a2, __int64 a3, char a4, int a5, int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x1
  __int64 v15; // x8
  int v16; // w9
  int v17; // w10
  __int64 v18; // x23
  __int64 v19; // x0
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v21, v9, 32);
    if ( result )
    {
      v15 = *a2;
      v16 = _cpu_halt_mask[0];
      v17 = _cpu_partial_halt_mask[0];
      v18 = result;
      *(_DWORD *)(result + 8) = v15;
      *(_DWORD *)(result + 12) = v16;
      *(_DWORD *)(result + 16) = v17;
      v19 = sched_clock(result, v14);
      *(_BYTE *)(v18 + 24) = a4;
      *(_DWORD *)(v18 + 28) = a6;
      *(_BYTE *)(v18 + 25) = a5 >= 0;
      *(_DWORD *)(v18 + 20) = (v19 - a3) / 0x3E8uLL;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
