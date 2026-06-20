__int64 __fastcall perf_trace_rdev_scan(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 v6; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v8; // x9
  __int64 v9; // x20
  const char *v10; // x22
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v15; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v15 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v6) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(44, v16, &v15);
  if ( !result )
    goto LABEL_12;
  v8 = (_QWORD *)v16[0];
  v9 = result;
  *(_QWORD *)(v16[0] + 232LL) = &vars0;
  v8[33] = 5;
  v8[31] = &v14;
  v8[32] = v3;
  v10 = *(const char **)(a2 + 504);
  if ( !v10 )
    v10 = *(const char **)(a2 + 392);
  v11 = strnlen(v10, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 < 0x21 )
    {
      sized_strscpy(v9 + 8, v10);
      result = perf_trace_run_bpf_submit(v9, 44, v15, v4, 1, v16[0], StatusReg + v6, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v13 = _fortify_panic(7, 32);
  return trace_event_raw_event_wiphy_only_evt(v13, MEMORY[0x3563C]);
}
