__int64 __fastcall trace_event_raw_event_walt_nohz_balance_kick(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 result; // x0
  _QWORD v7[7]; // [xsp+8h] [xbp-38h] BYREF

  v3 = a1;
  v7[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v7, 0, 48);
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v3 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v7, v3, 20);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2[908];
      *(_DWORD *)(result + 12) = a2[1];
      *(_DWORD *)(result + 16) = a2[133];
      result = trace_event_buffer_commit(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
