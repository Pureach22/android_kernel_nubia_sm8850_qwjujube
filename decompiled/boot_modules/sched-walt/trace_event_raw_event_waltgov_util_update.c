__int64 __fastcall trace_event_raw_event_waltgov_util_update(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9,
        int a10,
        char a11)
{
  __int64 v14; // x8
  __int64 v19; // x9
  __int64 result; // x0
  _QWORD v22[7]; // [xsp+8h] [xbp-38h] BYREF

  v14 = a1;
  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v19 & 0x2C0) == 0
    || (v19 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v14 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v22, v14, 72);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 56) = a8;
      *(_DWORD *)(result + 60) = a9;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_DWORD *)(result + 64) = a10;
      *(_BYTE *)(result + 68) = a11 & 1;
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
