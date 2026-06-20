__int64 __fastcall trace_event_raw_event_sched_find_best_target(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  __int64 v14; // x8
  __int64 v19; // x9
  __int64 result; // x0
  __int64 v21; // x8
  int v22; // w10
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v14 = a1;
  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v19 & 0x2C0) == 0
    || (v19 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v14 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v24, v14, 88);
    if ( result )
    {
      v21 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v21;
      LODWORD(v21) = *(_DWORD *)(a2 + 1800);
      *(_QWORD *)(result + 32) = a3;
      *(_DWORD *)(result + 40) = a4;
      *(_DWORD *)(result + 24) = v21;
      *(_QWORD *)(result + 48) = a5;
      *(_DWORD *)(result + 56) = a6;
      *(_DWORD *)(result + 60) = a7;
      *(_DWORD *)(result + 64) = a8;
      *(_DWORD *)(result + 68) = a9;
      v22 = *(_DWORD *)(a2 + 144);
      if ( v22 )
        LOBYTE(v22) = *(_BYTE *)(a2 + 273) == 0;
      *(_BYTE *)(result + 72) = v22;
      *(_DWORD *)(result + 76) = a10;
      *(_DWORD *)(result + 80) = a11;
      result = trace_event_buffer_commit(v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
