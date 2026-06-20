__int64 __fastcall trace_event_raw_event_key_handle(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        char a6,
        int *a7)
{
  __int64 v13; // x8
  __int64 result; // x0
  const char *v15; // x26
  __int64 v16; // x24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  char v19; // w23
  __int64 v20; // x8
  int v21; // w9
  __int64 v22; // x0
  int v23; // w11
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v13 & 0x2C0) != 0 && (v13 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v24);
  if ( !result )
    goto LABEL_14;
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
      v19 = a6 & 1;
      sized_strscpy(v16 + 8, v15);
      v20 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v16 + 48) = v20;
      *(_DWORD *)(v16 + 56) = *(_DWORD *)(a3 + 224);
      if ( a7 )
      {
        v21 = *a7;
        *(_WORD *)(v16 + 64) = *((_WORD *)a7 + 2);
        *(_DWORD *)(v16 + 60) = v21;
      }
      else
      {
        *(_WORD *)(v16 + 64) = 0;
        *(_DWORD *)(v16 + 60) = 0;
      }
      *(_DWORD *)(v16 + 68) = a4;
      *(_BYTE *)(v16 + 72) = a5;
      *(_BYTE *)(v16 + 73) = v19;
      result = trace_event_buffer_commit(v24);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v22 = _fortify_panic(7, 32);
  if ( !v23 )
    JUMPOUT(0x6934C);
  return perf_trace_key_handle(v22);
}
