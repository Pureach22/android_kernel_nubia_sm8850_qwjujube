__int64 __fastcall trace_event_raw_event_sde_perf_crtc_update(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9,
        char a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v16; // x8
  __int64 v21; // x9
  __int64 result; // x0
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v16 = a1;
  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v21 & 0x2C0) == 0
    || (v21 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v16 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v24, v16, 88);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 64) = a9;
      *(_BYTE *)(result + 68) = a10 & 1;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_QWORD *)(result + 56) = a8;
      *(_DWORD *)(result + 72) = a11;
      *(_DWORD *)(result + 76) = a12;
      *(_DWORD *)(result + 80) = a13;
      result = trace_event_buffer_commit(v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
