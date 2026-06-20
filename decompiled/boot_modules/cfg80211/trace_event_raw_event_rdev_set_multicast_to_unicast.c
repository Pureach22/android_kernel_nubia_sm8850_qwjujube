__int64 __fastcall trace_event_raw_event_rdev_set_multicast_to_unicast(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x22
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  long double v14; // q0
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v15);
  if ( !result )
    goto LABEL_11;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 < 0x21 )
    {
      sized_strscpy(v10 + 8, v9);
      v13 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v10 + 48) = v13;
      LODWORD(v13) = *(_DWORD *)(a3 + 224);
      *(_BYTE *)(v10 + 60) = a4 & 1;
      *(_DWORD *)(v10 + 56) = v13;
      result = trace_event_buffer_commit(v15);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v14 = _fortify_panic(7, 32);
  return perf_trace_rdev_set_multicast_to_unicast(v14);
}
