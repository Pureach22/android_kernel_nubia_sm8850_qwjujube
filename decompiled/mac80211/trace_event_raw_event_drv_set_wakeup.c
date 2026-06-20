__int64 __fastcall trace_event_raw_event_drv_set_wakeup(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x21
  const char *v9; // x20
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x14
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v5 & 0x2C0) != 0 && (v5 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v14);
  if ( !result )
    goto LABEL_11;
  v7 = *(_QWORD *)(a2 + 72);
  v8 = result;
  v9 = *(const char **)(v7 + 504);
  if ( !v9 )
    v9 = *(const char **)(v7 + 392);
  v10 = strnlen(v9, 0x20u);
  if ( v10 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v10 == 32 )
      v11 = 32;
    else
      v11 = v10 + 1;
    if ( v11 < 0x21 )
    {
      sized_strscpy(v8 + 8, v9);
      *(_BYTE *)(v8 + 40) = a3 & 1;
      result = trace_event_buffer_commit(v14);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v12 = _fortify_panic(7);
  if ( v13 )
    JUMPOUT(0xC55E0);
  return perf_trace_drv_set_wakeup(v12);
}
