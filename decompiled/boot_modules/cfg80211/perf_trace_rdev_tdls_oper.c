__int64 __fastcall perf_trace_rdev_tdls_oper(__int64 result, __int64 a2, __int64 a3, int *a4, int a5)
{
  __int64 v5; // x30
  double v6; // d10
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v13; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v15; // x9
  __int64 v16; // x23
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  __int64 v20; // x8
  int v21; // w9
  __int64 v22; // x2
  __int64 v23; // x5
  long double v24; // q0
  double v25; // d5
  double v26; // d18
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v30; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v10 = result;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v13 = *(_QWORD *)(result + 104);
  v28 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v13) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(76, v29, &v28);
  if ( !result )
    goto LABEL_15;
  v15 = (_QWORD *)v29[0];
  v16 = result;
  *(_QWORD *)(v29[0] + 232LL) = &v30;
  v15[33] = 5;
  v15[31] = &v27;
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
      }
      else
      {
        *(_WORD *)(v16 + 64) = 0;
        *(_DWORD *)(v16 + 60) = 0;
      }
      v22 = v28;
      v23 = v29[0];
      *(_DWORD *)(v16 + 68) = a5;
      result = perf_trace_run_bpf_submit(v16, 76, v22, v10, 1, v23, StatusReg + v13, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v24 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_pmksa(v24, v6 + v25 * v26);
}
