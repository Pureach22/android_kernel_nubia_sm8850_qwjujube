__int64 __fastcall trace_event_raw_event_rdev_set_default_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        char a6,
        char a7)
{
  __int64 v13; // x8
  __int64 result; // x0
  const char *v15; // x26
  __int64 v16; // x24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x0
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v13 & 0x2C0) != 0 && (v13 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v21);
  if ( !result )
    goto LABEL_11;
  v15 = *(const char **)(a2 + 504);
  v16 = result;
  if ( !v15 )
    v15 = *(const char **)(a2 + 392);
  v17 = strnlen(v15, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v16 + 8, v15);
      v19 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v16 + 48) = v19;
      LODWORD(v19) = *(_DWORD *)(a3 + 224);
      *(_BYTE *)(v16 + 64) = a5;
      *(_BYTE *)(v16 + 65) = a6 & 1;
      *(_DWORD *)(v16 + 56) = v19;
      *(_DWORD *)(v16 + 60) = a4;
      *(_BYTE *)(v16 + 66) = a7 & 1;
      result = trace_event_buffer_commit(v21);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v20 = _fortify_panic(7, 32);
  return perf_trace_rdev_set_default_key(v20);
}
