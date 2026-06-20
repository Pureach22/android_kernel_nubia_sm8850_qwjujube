__int64 __fastcall trace_event_raw_event_adreno_gpu_fault(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        int a8,
        __int64 a9,
        int a10,
        int a11)
{
  __int64 v18; // x9
  __int64 result; // x0
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v18 & 0x2C0) == 0 || (v18 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_QWORD *)(result + 32) = a7;
      *(_DWORD *)(result + 40) = a8;
      *(_QWORD *)(result + 48) = a9;
      *(_DWORD *)(result + 56) = a10;
      *(_DWORD *)(result + 60) = a11;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
