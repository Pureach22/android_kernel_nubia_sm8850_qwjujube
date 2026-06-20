__int64 __fastcall trace_event_raw_event_sched_boost_bus_dcvs(__int64 a1, char a2, char a3, char a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // w8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12, v7, 12);
    if ( result )
    {
      v10 = sched_boost_type;
      *(_BYTE *)(result + 8) = a2 & 1;
      *(_BYTE *)(result + 10) = a3 & 1;
      *(_BYTE *)(result + 11) = a4 & 1;
      *(_BYTE *)(result + 9) = v10 == 4;
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
