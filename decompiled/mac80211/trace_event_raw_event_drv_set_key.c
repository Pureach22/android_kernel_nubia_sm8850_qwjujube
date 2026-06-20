__int64 __fastcall trace_event_raw_event_drv_set_key(__int64 a1, __int64 a2, int a3, __int64 a4, int *a5, __int64 a6)
{
  __int64 v11; // x8
  int v12; // w25
  __int64 result; // x0
  __int64 v14; // x23
  __int64 v15; // x8
  const char *v16; // x24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  int v19; // w9
  int v20; // w8
  void *v21; // x24
  size_t v22; // x25
  int v23; // w9
  __int64 v24; // x0
  int v25; // w1
  int v26; // w16
  _QWORD v27[7]; // [xsp+8h] [xbp-38h] BYREF

  v27[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v27, 0, 48);
  if ( (v11 & 0x2C0) != 0 && (v11 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  v12 = strlen((const char *)(a4 + 1640)) + 1;
  result = trace_event_buffer_reserve(v27);
  if ( !result )
    goto LABEL_14;
  v14 = result;
  *(_DWORD *)(result + 60) = (v12 << 16) | 0x53;
  v15 = *(_QWORD *)(a2 + 72);
  v16 = *(const char **)(v15 + 504);
  if ( !v16 )
    v16 = *(const char **)(v15 + 392);
  v17 = strnlen(v16, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v14 + 8, v16);
      v19 = *(_DWORD *)(v14 + 60);
      v20 = *(_DWORD *)(a4 + 4720);
      *(_QWORD *)(v14 + 48) = a4;
      *(_DWORD *)(v14 + 40) = v20;
      v21 = (void *)(v14 + (unsigned __int16)v19);
      v22 = HIWORD(v19) - 1LL;
      *(_BYTE *)(v14 + 56) = *(_BYTE *)(a4 + 5848);
      memcpy(v21, (const void *)(a4 + 1640), v22);
      *((_BYTE *)v21 + v22) = 0;
      if ( a5 )
      {
        v23 = *a5;
        *(_WORD *)(v14 + 68) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v14 + 64) = v23;
      }
      else
      {
        *(_WORD *)(v14 + 68) = 0;
        *(_DWORD *)(v14 + 64) = 0;
      }
      *(_DWORD *)(v14 + 72) = a3;
      *(_DWORD *)(v14 + 76) = *(_DWORD *)(a6 + 8);
      *(_BYTE *)(v14 + 81) = *(_BYTE *)(a6 + 16);
      *(_BYTE *)(v14 + 82) = *(_BYTE *)(a6 + 15);
      *(_BYTE *)(v14 + 80) = *(_BYTE *)(a6 + 14);
      result = trace_event_buffer_commit(v27);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v24 = _fortify_panic(7);
  *(_DWORD *)(a6 + 208) = v25;
  *(_DWORD *)(a6 + 212) = v26;
  return perf_trace_drv_set_key(v24);
}
