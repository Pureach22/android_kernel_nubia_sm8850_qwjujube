__int64 __fastcall trace_event_raw_event_core_ctl_sbt(__int64 a1, __int64 *a2, char a3, char a4, int a5, int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x8
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v16, v9, 28);
    if ( result )
    {
      v14 = *a2;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 8) = v14;
      *(_DWORD *)(result + 12) = a3 & 1;
      *(_DWORD *)(result + 16) = a4 & 1;
      *(_DWORD *)(result + 20) = a5;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
