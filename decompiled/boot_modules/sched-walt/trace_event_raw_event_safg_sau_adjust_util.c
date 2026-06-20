__int64 __fastcall trace_event_raw_event_safg_sau_adjust_util(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9)
{
  __int64 v12; // x8
  __int64 v17; // x9
  __int64 result; // x0
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1;
  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v12 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20, v12, 72);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_QWORD *)(result + 56) = a8;
      *(_DWORD *)(result + 64) = a9;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
