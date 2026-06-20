__int64 __fastcall trace_event_raw_event_wiphy_only_evt(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  const char *v5; // x21
  __int64 v6; // x20
  size_t v7; // x0
  unsigned __int64 v8; // x2
  __int64 v9; // x0
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v3 & 0x2C0) != 0 && (v3 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v10);
  if ( !result )
    goto LABEL_11;
  v5 = *(const char **)(a2 + 504);
  v6 = result;
  if ( !v5 )
    v5 = *(const char **)(a2 + 392);
  v7 = strnlen(v5, 0x20u);
  if ( v7 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v7 == 32 )
      v8 = 32;
    else
      v8 = v7 + 1;
    if ( v8 < 0x21 )
    {
      sized_strscpy(v6 + 8, v5);
      result = trace_event_buffer_commit(v10);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v9 = _fortify_panic(7, 32);
  return perf_trace_wiphy_only_evt(v9, MEMORY[0x35748]);
}
