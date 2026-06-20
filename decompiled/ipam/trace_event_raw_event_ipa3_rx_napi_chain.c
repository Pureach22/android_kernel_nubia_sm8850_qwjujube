__int64 __fastcall trace_event_raw_event_ipa3_rx_napi_chain(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
