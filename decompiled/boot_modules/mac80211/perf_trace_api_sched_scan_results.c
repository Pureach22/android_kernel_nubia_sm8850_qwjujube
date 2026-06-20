__int64 __fastcall perf_trace_api_sched_scan_results(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 v6; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v8; // x9
  __int64 v9; // x20
  __int64 v10; // x8
  const char *v11; // x21
  size_t v12; // x0
  unsigned __int64 v13; // x2
  __int64 v14; // x0
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v16; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v16 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v6) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(44, v17, &v16);
  if ( !result )
    goto LABEL_12;
  v8 = (_QWORD *)v17[0];
  v9 = result;
  *(_QWORD *)(v17[0] + 232LL) = &vars0;
  v8[33] = 5;
  v8[31] = &v15;
  v8[32] = v3;
  v10 = *(_QWORD *)(a2 + 72);
  v11 = *(const char **)(v10 + 504);
  if ( !v11 )
    v11 = *(const char **)(v10 + 392);
  v12 = strnlen(v11, 0x20u);
  if ( v12 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v12 == 32 )
      v13 = 32;
    else
      v13 = v12 + 1;
    if ( v13 < 0x21 )
    {
      sized_strscpy(v9 + 8, v11);
      result = perf_trace_run_bpf_submit(v9, 44, v16, v4, 1, v17[0], StatusReg + v6, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v14 = _fortify_panic(7);
  return trace_event_raw_event_api_sched_scan_stopped(v14);
}
