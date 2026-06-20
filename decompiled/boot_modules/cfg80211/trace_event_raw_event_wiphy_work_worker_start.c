__int64 __fastcall trace_event_raw_event_wiphy_work_worker_start(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  const char *v5; // x21
  __int64 v6; // x20
  size_t v7; // x0
  unsigned __int64 v8; // x2
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9);
    if ( result )
    {
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
          result = trace_event_buffer_commit(v9);
          goto LABEL_11;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x8DE90);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
