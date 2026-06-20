__int64 __fastcall trace_event_raw_event_cfg80211_tx_mlme_mgmt(__int64 a1, __int64 a2, const void *a3, int a4, char a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x21
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13);
    if ( result )
    {
      *(_DWORD *)(result + 28) = (a4 << 16) | 0x24;
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      LODWORD(v11) = *(_DWORD *)(a2 + 224);
      v12 = result;
      *(_DWORD *)(result + 24) = v11;
      memcpy((void *)(result + 36), a3, a4);
      *(_DWORD *)(v12 + 32) = a5 & 1;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
