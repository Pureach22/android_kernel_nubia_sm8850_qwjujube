__int64 __fastcall trace_event_raw_event_sde_perf_uidle_status(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  __int64 v15; // x8
  __int64 v20; // x9
  __int64 result; // x0
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v15 = a1;
  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(_QWORD *)(a1 + 72);
  memset(v23, 0, 48);
  if ( (v20 & 0x2C0) == 0
    || (v20 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v15 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v23, v15, 52);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 36) = a9;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 28) = a7;
      *(_DWORD *)(result + 32) = a8;
      *(_DWORD *)(result + 40) = a10;
      *(_DWORD *)(result + 44) = a11;
      *(_DWORD *)(result + 48) = a12;
      result = trace_event_buffer_commit(v23);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
