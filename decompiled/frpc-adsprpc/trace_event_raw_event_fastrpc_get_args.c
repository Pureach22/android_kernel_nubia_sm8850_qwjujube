__int64 __fastcall trace_event_raw_event_fastrpc_get_args(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13, v8, 32);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 28) = a5;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
