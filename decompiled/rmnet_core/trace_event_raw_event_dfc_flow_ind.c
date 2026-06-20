__int64 __fastcall trace_event_raw_event_dfc_flow_ind(
        __int64 a1,
        int a2,
        int a3,
        char a4,
        char a5,
        int a6,
        __int16 a7,
        char a8,
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
    result = trace_event_buffer_reserve(v20, v12, 32);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_BYTE *)(result + 16) = a4;
      *(_BYTE *)(result + 17) = a5;
      *(_DWORD *)(result + 20) = a6;
      *(_WORD *)(result + 24) = a7;
      *(_BYTE *)(result + 26) = a8;
      *(_DWORD *)(result + 28) = a9;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
