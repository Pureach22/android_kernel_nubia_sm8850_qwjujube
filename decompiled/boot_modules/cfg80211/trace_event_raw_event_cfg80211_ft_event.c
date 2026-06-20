__int64 __fastcall trace_event_raw_event_cfg80211_ft_event(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // s8
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x24
  __int64 result; // x0
  __int64 v12; // x21
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  int *v17; // x8
  __int16 v18; // w9
  int v19; // w8
  long double v20; // q0
  __int64 v21; // x9
  int v22; // s2
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v23, 0, 48);
  if ( (v8 & 0x2C0) != 0 && (v8 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_16;
  }
  v9 = *(_QWORD *)(a4 + 8);
  v10 = *(_QWORD *)(a4 + 32);
  result = trace_event_buffer_reserve(v23);
  if ( !result )
    goto LABEL_16;
  v12 = result;
  *(_DWORD *)(result + 60) = ((_DWORD)v9 << 16) | 0x4C;
  *(_DWORD *)(result + 72) = (v9 + 76) | ((_DWORD)v10 << 16);
  v13 = *(const char **)(a2 + 504);
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v12 + 8, v13);
      v16 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v12 + 48) = v16;
      *(_DWORD *)(v12 + 56) = *(_DWORD *)(a3 + 224);
      if ( *(_QWORD *)a4 )
        memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 60)), *(const void **)a4, *(_QWORD *)(a4 + 8));
      v17 = *(int **)(a4 + 16);
      if ( v17 )
      {
        v18 = *((_WORD *)v17 + 2);
        v19 = *v17;
        *(_WORD *)(v12 + 68) = v18;
        *(_DWORD *)(v12 + 64) = v19;
        if ( !*(_QWORD *)(a4 + 24) )
        {
LABEL_15:
          result = trace_event_buffer_commit(v23);
LABEL_16:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      else
      {
        *(_WORD *)(v12 + 68) = 0;
        *(_DWORD *)(v12 + 64) = 0;
        if ( !*(_QWORD *)(a4 + 24) )
          goto LABEL_15;
      }
      memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 72)), *(const void **)(a4 + 24), *(_QWORD *)(a4 + 32));
      goto LABEL_15;
    }
  }
  v20 = _fortify_panic(7, 32);
  *(_DWORD *)(v21 + 184) = v4;
  *(_DWORD *)(v21 + 188) = v22;
  return perf_trace_cfg80211_ft_event(v20);
}
