__int64 __fastcall trace_event_raw_event_cfg80211_report_obss_beacon(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x23
  __int64 v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15);
    if ( result )
    {
      v11 = *(const char **)(a2 + 504);
      v12 = result;
      if ( !v11 )
        v11 = *(const char **)(a2 + 392);
      v13 = strnlen(v11, 0x20u);
      if ( v13 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v13 == 32 )
          v14 = 32;
        else
          v14 = v13 + 1;
        if ( v14 < 0x21 )
        {
          sized_strscpy(v12 + 8, v11);
          *(_DWORD *)(v12 + 40) = a5;
          *(_DWORD *)(v12 + 44) = a6;
          result = trace_event_buffer_commit(v15);
          goto LABEL_11;
        }
      }
      _fortify_panic(7, 32);
      _fortify_panic(2, -1);
      _fortify_panic(7, 32);
      JUMPOUT(0x9EBC4);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
