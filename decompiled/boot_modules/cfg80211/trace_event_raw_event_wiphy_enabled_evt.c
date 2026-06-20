__int64 __fastcall trace_event_raw_event_wiphy_enabled_evt(__int64 a1, __int64 a2, char a3)
{
  char v3; // w28
  __int64 v6; // x8
  __int64 result; // x0
  const char *v8; // x22
  __int64 v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x0
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v6 & 0x2C0) != 0 && (v6 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v13);
  if ( !result )
    goto LABEL_11;
  v8 = *(const char **)(a2 + 504);
  v9 = result;
  if ( !v8 )
    v8 = *(const char **)(a2 + 392);
  v10 = strnlen(v8, 0x20u);
  if ( v10 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v10 == 32 )
      v11 = 32;
    else
      v11 = v10 + 1;
    if ( v11 < 0x21 )
    {
      sized_strscpy(v9 + 8, v8);
      *(_BYTE *)(v9 + 40) = a3 & 1;
      result = trace_event_buffer_commit(v13);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v12 = _fortify_panic(7, 32);
  if ( (v3 & 8) != 0 )
    JUMPOUT(0x9447C);
  return perf_trace_wiphy_enabled_evt(v12);
}
