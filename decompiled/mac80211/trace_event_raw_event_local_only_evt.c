__int64 __fastcall trace_event_raw_event_local_only_evt(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  const char *v7; // x19
  size_t v8; // x0
  unsigned __int64 v9; // x2
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      v5 = *(_QWORD *)(a2 + 72);
      v6 = result;
      v7 = *(const char **)(v5 + 504);
      if ( !v7 )
        v7 = *(const char **)(v5 + 392);
      v8 = strnlen(v7, 0x20u);
      if ( v8 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v8 == 32 )
          v9 = 32;
        else
          v9 = v8 + 1;
        if ( v9 < 0x21 )
        {
          sized_strscpy(v6 + 8, v7);
          result = trace_event_buffer_commit(v10);
          goto LABEL_11;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x894D0);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
