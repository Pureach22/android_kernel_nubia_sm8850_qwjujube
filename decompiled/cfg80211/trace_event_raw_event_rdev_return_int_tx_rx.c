__int64 __fastcall trace_event_raw_event_rdev_return_int_tx_rx(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  _DWORD *v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w14
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v16);
  if ( !result )
    goto LABEL_11;
  v11 = *(const char **)(a2 + 504);
  v12 = (_DWORD *)result;
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
      sized_strscpy(v12 + 2, v11);
      v12[10] = a3;
      v12[11] = a4;
      v12[12] = a5;
      result = trace_event_buffer_commit(v16);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  _fortify_panic(7, 32);
  return perf_trace_rdev_return_int_tx_rx((unsigned int)(v15 - 10035200));
}
