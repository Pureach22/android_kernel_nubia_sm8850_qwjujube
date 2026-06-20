__int64 __fastcall trace_event_raw_event_cfg80211_links_removed(__int64 a1, __int64 a2, __int16 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  _QWORD v8[7]; // [xsp+8h] [xbp-38h] BYREF

  v8[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v8, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v8);
    if ( result )
    {
      v7 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v7;
      LODWORD(v7) = *(_DWORD *)(a2 + 224);
      *(_WORD *)(result + 28) = a3;
      *(_DWORD *)(result + 24) = v7;
      result = trace_event_buffer_commit(v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
