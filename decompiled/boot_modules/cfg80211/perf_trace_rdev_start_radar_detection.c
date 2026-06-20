__int64 __fastcall perf_trace_rdev_start_radar_detection(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6)
{
  __int64 v6; // x30
  __int64 v7; // x26
  __int64 v10; // x19
  __int64 v14; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v16; // x9
  __int64 v17; // x23
  const char *v18; // x26
  size_t v19; // x0
  unsigned __int64 v20; // x2
  __int64 v21; // x8
  __int64 v22; // x2
  __int64 v23; // x5
  long double v24; // q0
  __int64 v25; // x3
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v27 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v14)
    || (result = perf_trace_buf_alloc(100, v28, &v27)) == 0 )
  {
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v16 = (_QWORD *)v28[0];
  v17 = result;
  *(_QWORD *)(v28[0] + 232LL) = &vars0;
  v16[33] = 5;
  v16[31] = &v26;
  v16[32] = v7;
  v18 = *(const char **)(a2 + 504);
  if ( !v18 )
    v18 = *(const char **)(a2 + 392);
  v19 = strnlen(v18, 0x20u);
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
      sized_strscpy(v17 + 8, v18);
      v21 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v17 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v17 + 48) = v21;
      *(_DWORD *)(v17 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 && *(_QWORD *)a4 )
      {
        *(_DWORD *)(v17 + 60) = **(_DWORD **)a4;
        *(_DWORD *)(v17 + 64) = *(_DWORD *)(*(_QWORD *)a4 + 4LL);
        *(_DWORD *)(v17 + 68) = *(unsigned __int16 *)(*(_QWORD *)a4 + 8LL);
        *(_DWORD *)(v17 + 72) = *(_DWORD *)(a4 + 8);
        *(_DWORD *)(v17 + 76) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v17 + 80) = *(unsigned __int16 *)(a4 + 28);
        *(_DWORD *)(v17 + 84) = *(_DWORD *)(a4 + 16);
        *(_WORD *)(v17 + 88) = *(_WORD *)(a4 + 30);
      }
      else
      {
        *(_QWORD *)(v17 + 82) = 0;
        *(_QWORD *)(v17 + 76) = 0;
        *(_QWORD *)(v17 + 68) = 0;
        *(_QWORD *)(v17 + 60) = 0;
      }
      v22 = v27;
      v23 = v28[0];
      *(_DWORD *)(v17 + 92) = a5;
      *(_DWORD *)(v17 + 96) = a6;
      result = perf_trace_run_bpf_submit(v17, 100, v22, v10, 1, v23, StatusReg + v14, 0);
      goto LABEL_16;
    }
  }
  v24 = _fortify_panic(7, 32);
  if ( (v25 & 0x200000000000000LL) == 0 )
    JUMPOUT(0xA03C8);
  return trace_event_raw_event_rdev_set_mcast_rate(v24);
}
