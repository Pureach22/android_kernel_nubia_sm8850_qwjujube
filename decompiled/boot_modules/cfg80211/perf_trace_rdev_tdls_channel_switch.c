__int64 __fastcall perf_trace_rdev_tdls_channel_switch(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int *a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v13; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v15; // x9
  __int64 v16; // x21
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  __int64 v20; // x8
  int v21; // w9
  long double v22; // q0
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v13 = *(_QWORD *)(result + 104);
  v24 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v13) )
    goto LABEL_19;
  result = perf_trace_buf_alloc(100, v25, &v24);
  if ( !result )
    goto LABEL_19;
  v15 = (_QWORD *)v25[0];
  v16 = result;
  *(_QWORD *)(v25[0] + 232LL) = &v26;
  v15[33] = 5;
  v15[31] = &v23;
  v15[32] = v7;
  v17 = *(const char **)(a2 + 504);
  if ( !v17 )
    v17 = *(const char **)(a2 + 392);
  v18 = strnlen(v17, 0x20u);
  if ( v18 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v18 == 32 )
      v19 = 32;
    else
      v19 = v18 + 1;
    if ( v19 < 0x21 )
    {
      sized_strscpy(v16 + 8, v17);
      v20 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v16 + 48) = v20;
      *(_DWORD *)(v16 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 )
      {
        v21 = *a4;
        *(_WORD *)(v16 + 64) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v16 + 60) = v21;
        if ( !a6 )
          goto LABEL_17;
      }
      else
      {
        *(_WORD *)(v16 + 64) = 0;
        *(_DWORD *)(v16 + 60) = 0;
        if ( !a6 )
          goto LABEL_17;
      }
      if ( *(_QWORD *)a6 )
      {
        *(_DWORD *)(v16 + 68) = **(_DWORD **)a6;
        *(_DWORD *)(v16 + 72) = *(_DWORD *)(*(_QWORD *)a6 + 4LL);
        *(_DWORD *)(v16 + 76) = *(unsigned __int16 *)(*(_QWORD *)a6 + 8LL);
        *(_DWORD *)(v16 + 80) = *(_DWORD *)(a6 + 8);
        *(_DWORD *)(v16 + 84) = *(_DWORD *)(a6 + 12);
        *(_DWORD *)(v16 + 88) = *(unsigned __int16 *)(a6 + 28);
        *(_DWORD *)(v16 + 92) = *(_DWORD *)(a6 + 16);
        *(_WORD *)(v16 + 96) = *(_WORD *)(a6 + 30);
LABEL_18:
        result = perf_trace_run_bpf_submit(v16, 100, v24, v10, 1, v25[0], StatusReg + v13, 0);
LABEL_19:
        _ReadStatusReg(SP_EL0);
        return result;
      }
LABEL_17:
      *(_QWORD *)(v16 + 90) = 0;
      *(_QWORD *)(v16 + 84) = 0;
      *(_QWORD *)(v16 + 76) = 0;
      *(_QWORD *)(v16 + 68) = 0;
      goto LABEL_18;
    }
  }
  v22 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_tdls_cancel_channel_switch(v22);
}
