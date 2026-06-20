__int64 __fastcall trace_event_raw_event_drv_start_ap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  int v8; // w23
  int v9; // w24
  __int64 result; // x0
  __int64 v11; // x21
  __int64 v12; // x8
  const char *v13; // x22
  size_t v14; // x0
  unsigned __int64 v15; // x2
  int v16; // w9
  int v17; // w8
  void *v18; // x22
  size_t v19; // x23
  __int64 v20; // x0
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  v8 = strlen((const char *)(a3 + 1640));
  v9 = *(_DWORD *)(a3 + 4792);
  result = trace_event_buffer_reserve(v21);
  if ( !result )
    goto LABEL_11;
  v11 = result;
  *(_DWORD *)(result + 60) = ((v8 + 1) << 16) | 0x4D;
  *(_DWORD *)(result + 72) = (v8 + 78) | (v9 << 16);
  v12 = *(_QWORD *)(a2 + 72);
  v13 = *(const char **)(v12 + 504);
  if ( !v13 )
    v13 = *(const char **)(v12 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v11 + 8, v13);
      v16 = *(_DWORD *)(v11 + 60);
      v17 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v11 + 48) = a3;
      *(_DWORD *)(v11 + 40) = v17;
      v18 = (void *)(v11 + (unsigned __int16)v16);
      v19 = HIWORD(v16) - 1LL;
      *(_BYTE *)(v11 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v18, (const void *)(a3 + 1640), v19);
      *((_BYTE *)v18 + v19) = 0;
      *(_DWORD *)(v11 + 64) = *(_DWORD *)(a4 + 24);
      *(_BYTE *)(v11 + 68) = *(_BYTE *)(a4 + 49);
      *(_WORD *)(v11 + 70) = *(_WORD *)(a4 + 50);
      *(_BYTE *)(v11 + 76) = *(_BYTE *)(a4 + 225);
      memcpy((void *)(v11 + *(unsigned __int16 *)(v11 + 72)), (const void *)(a3 + 4760), *(_QWORD *)(a3 + 4792));
      result = trace_event_buffer_commit(v21);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v20 = _fortify_panic(7);
  return perf_trace_drv_start_ap(v20);
}
