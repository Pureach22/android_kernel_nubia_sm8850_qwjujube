__int64 __fastcall trace_event_raw_event_cfg80211_bss_color_notify(__int64 a1, __int64 a2, int a3, char a4, __int64 a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      LODWORD(v11) = *(_DWORD *)(a2 + 224);
      *(_BYTE *)(result + 32) = a4;
      *(_QWORD *)(result + 40) = a5;
      *(_DWORD *)(result + 24) = v11;
      *(_DWORD *)(result + 28) = a3;
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
