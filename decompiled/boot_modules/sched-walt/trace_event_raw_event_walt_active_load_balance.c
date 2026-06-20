__int64 __fastcall trace_event_raw_event_walt_active_load_balance(__int64 a1, __int64 a2, int a3, int a4, __int64 a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  char v12; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14, v8, 24);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v12 = *(_BYTE *)(a5 + 189);
      *(_DWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 20) = a4;
      *(_BYTE *)(result + 12) = v12;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
