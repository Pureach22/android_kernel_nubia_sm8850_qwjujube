__int64 __fastcall trace_event_raw_event_cfg80211_rx_mgmt(__int64 a1, unsigned __int64 a2, _DWORD *a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  int v7; // w8
  _QWORD v8[7]; // [xsp+8h] [xbp-38h] BYREF

  v8[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v8, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v8);
    if ( result )
    {
      v7 = 0;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v7 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v7;
      *(_DWORD *)(result + 12) = *a3;
      *(_DWORD *)(result + 16) = a3[1];
      result = trace_event_buffer_commit(v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
