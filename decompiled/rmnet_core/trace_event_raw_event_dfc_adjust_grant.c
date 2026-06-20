__int64 __fastcall trace_event_raw_event_dfc_adjust_grant(__int64 a1, char a2, char a3, int a4, int a5, int a6, int a7)
{
  __int64 v10; // x8
  __int64 v14; // x9
  __int64 result; // x0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v10 = a1;
  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v14 & 0x2C0) == 0
    || (v14 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v10 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17, v10, 28);
    if ( result )
    {
      *(_BYTE *)(result + 8) = a2;
      *(_BYTE *)(result + 9) = a3;
      *(_DWORD *)(result + 12) = a4;
      *(_DWORD *)(result + 16) = a5;
      *(_DWORD *)(result + 20) = a6;
      *(_DWORD *)(result + 24) = a7;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
