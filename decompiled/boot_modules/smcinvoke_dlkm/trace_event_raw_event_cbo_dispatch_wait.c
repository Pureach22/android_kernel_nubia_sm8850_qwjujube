__int64 __fastcall trace_event_raw_event_cbo_dispatch_wait(__int64 a1, const char *a2, int a3, int a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x22
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x0
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_9;
  }
  result = trace_event_buffer_reserve(v13);
  if ( !result )
    goto LABEL_9;
  v9 = result;
  v10 = strnlen(a2, 0x30u);
  if ( v10 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v10 == 48 )
      v11 = 48;
    else
      v11 = v10 + 1;
    if ( v11 < 0x31 )
    {
      sized_strscpy(v9 + 8, a2);
      *(_DWORD *)(v9 + 56) = a3;
      *(_DWORD *)(v9 + 60) = a4;
      result = trace_event_buffer_commit(v13);
LABEL_9:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v12 = _fortify_panic(7, 48, v11);
  return perf_trace_cbo_dispatch_wait(v12);
}
