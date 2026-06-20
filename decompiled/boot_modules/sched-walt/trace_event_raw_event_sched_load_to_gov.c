__int64 __fastcall trace_event_raw_event_sched_load_to_gov(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        __int64 a6,
        unsigned __int64 a7,
        int a8,
        char a9,
        int a10,
        _QWORD *a11,
        int a12)
{
  __int64 v15; // x8
  __int64 v20; // x9
  __int64 result; // x0
  __int64 v22; // x12
  int v23; // w12
  unsigned __int64 v24; // x13
  __int64 v25; // x9
  _QWORD v27[7]; // [xsp+8h] [xbp-38h] BYREF

  v15 = a1;
  v27[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(_QWORD *)(a1 + 72);
  memset(v27, 0, 48);
  if ( (v20 & 0x2C0) == 0
    || (v20 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v15 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v27, v15, 128);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 3632);
      *(_DWORD *)(result + 12) = a8;
      v22 = a11[14];
      if ( v22 )
        v23 = *(_DWORD *)(v22 + 1800);
      else
        v23 = -1;
      *(_DWORD *)(result + 16) = v23;
      v24 = (unsigned int)walt_scale_demand_divisor;
      *(_QWORD *)(result + 24) = a3;
      *(_DWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a4;
      *(_QWORD *)(result + 48) = a11[19];
      *(_QWORD *)(result + 56) = a11[23];
      *(_QWORD *)(result + 64) = a11[21];
      *(_QWORD *)(result + 72) = a11[25];
      v25 = a11[6];
      *(_QWORD *)(result + 88) = a6;
      *(_QWORD *)(result + 96) = a7;
      *(_BYTE *)(result + 104) = a9 & 1;
      *(_QWORD *)(result + 80) = v25;
      *(_DWORD *)(result + 108) = a10;
      *(_DWORD *)(result + 112) = a12;
      *(_QWORD *)(result + 120) = a7 / v24;
      result = trace_event_buffer_commit(v27);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
