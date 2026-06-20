__int64 __fastcall trace_event_raw_event_rdev_add_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        char a6,
        int *a7,
        char a8)
{
  __int64 v15; // x8
  __int64 result; // x0
  const char *v17; // x27
  __int64 v18; // x25
  size_t v19; // x0
  unsigned __int64 v20; // x2
  char v21; // w24
  __int64 v22; // x8
  int v23; // w9
  __int64 v24; // x0
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v15 & 0x2C0) != 0 && (v15 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v25);
  if ( !result )
    goto LABEL_14;
  v17 = *(const char **)(a2 + 504);
  v18 = result;
  if ( !v17 )
    v17 = *(const char **)(a2 + 392);
  v19 = strnlen(v17, 0x20u);
  if ( v19 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v19 == 32 )
      v20 = 32;
    else
      v20 = v19 + 1;
    if ( v20 < 0x21 )
    {
      v21 = a6 & 1;
      sized_strscpy(v18 + 8, v17);
      v22 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v18 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v18 + 48) = v22;
      *(_DWORD *)(v18 + 56) = *(_DWORD *)(a3 + 224);
      if ( a7 )
      {
        v23 = *a7;
        *(_WORD *)(v18 + 64) = *((_WORD *)a7 + 2);
        *(_DWORD *)(v18 + 60) = v23;
      }
      else
      {
        *(_WORD *)(v18 + 64) = 0;
        *(_DWORD *)(v18 + 60) = 0;
      }
      *(_DWORD *)(v18 + 68) = a4;
      *(_BYTE *)(v18 + 72) = a5;
      *(_BYTE *)(v18 + 73) = v21;
      *(_BYTE *)(v18 + 74) = a8;
      result = trace_event_buffer_commit(v25);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v24 = _fortify_panic(7, 32);
  return perf_trace_rdev_add_key(v24);
}
