__int64 __fastcall trace_event_raw_event_fastrpc_context_interrupt(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v9, 40);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
