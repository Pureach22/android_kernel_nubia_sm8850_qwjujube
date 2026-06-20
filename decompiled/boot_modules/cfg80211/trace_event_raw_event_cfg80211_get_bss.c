void __fastcall trace_event_raw_event_cfg80211_get_bss(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int *a4,
        const void *a5,
        size_t a6,
        int a7,
        int a8)
{
  int v8; // w18
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x25
  const char *v19; // x27
  size_t v20; // x0
  unsigned __int64 v21; // x2
  int v22; // w9
  long double v23; // q0
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v16 & 0x2C0) != 0 && (v16 & 0x100) == 0 && (_trace_trigger_soft_disabled(a1) & 1) != 0 )
    goto LABEL_16;
  v17 = trace_event_buffer_reserve(v24);
  if ( !v17 )
    goto LABEL_16;
  v18 = v17;
  *(_DWORD *)(v17 + 56) = ((_DWORD)a6 << 16) | 0x44;
  v19 = *(const char **)(a2 + 504);
  if ( !v19 )
    v19 = *(const char **)(a2 + 392);
  v20 = strnlen(v19, 0x20u);
  if ( v20 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v20 == 32 )
      v21 = 32;
    else
      v21 = v20 + 1;
    if ( v21 < 0x21 )
    {
      sized_strscpy(v18 + 8, v19);
      if ( a3 )
      {
        *(_DWORD *)(v18 + 40) = *(_DWORD *)a3;
        *(_DWORD *)(v18 + 44) = *(_DWORD *)(a3 + 4);
        *(_WORD *)(v18 + 48) = *(_WORD *)(a3 + 8);
        if ( a4 )
        {
LABEL_12:
          v22 = *a4;
          *(_WORD *)(v18 + 54) = *((_WORD *)a4 + 2);
          *(_DWORD *)(v18 + 50) = v22;
LABEL_15:
          memcpy((void *)(v18 + *(unsigned __int16 *)(v18 + 56)), a5, a6);
          *(_DWORD *)(v18 + 60) = a7;
          *(_DWORD *)(v18 + 64) = a8;
          trace_event_buffer_commit(v24);
LABEL_16:
          _ReadStatusReg(SP_EL0);
          return;
        }
      }
      else
      {
        *(_QWORD *)(v18 + 40) = 0;
        *(_WORD *)(v18 + 48) = 0;
        if ( a4 )
          goto LABEL_12;
      }
      *(_WORD *)(v18 + 54) = 0;
      *(_DWORD *)(v18 + 50) = 0;
      goto LABEL_15;
    }
  }
  v23 = _fortify_panic(7, 32);
  if ( (v8 & 0x4000000) != 0 )
    perf_trace_cfg80211_get_bss(v23);
}
