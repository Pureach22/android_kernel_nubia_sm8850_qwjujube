__int64 __fastcall trace_event_raw_event_cfg80211_mgmt_tx_status(__int64 a1, unsigned __int64 a2, __int64 a3, char a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  int v9; // w9
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      v9 = 0;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v9 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v9;
      *(_QWORD *)(result + 16) = a3;
      *(_BYTE *)(result + 24) = a4 & 1;
      result = trace_event_buffer_commit(v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
