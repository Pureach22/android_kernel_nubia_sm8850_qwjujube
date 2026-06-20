__int64 __fastcall trace_event_raw_event_sched_ravg_window_change(__int64 a1, int a2, int a3, __int64 a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 result; // x0
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11, v7, 24);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_QWORD *)(result + 16) = a4;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
