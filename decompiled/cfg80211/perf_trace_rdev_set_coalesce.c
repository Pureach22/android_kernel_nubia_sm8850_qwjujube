__int64 __fastcall perf_trace_rdev_set_coalesce(__int64 result, __int64 a2, int *a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  __int64 v11; // x21
  const char *v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w8
  __int64 v16; // x2
  __int64 v17; // x5
  long double v18; // q0
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v22; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(44, v21, &v20);
  if ( !result )
    goto LABEL_15;
  v10 = (_QWORD *)v21[0];
  v11 = result;
  *(_QWORD *)(v21[0] + 232LL) = &v22;
  v10[33] = 5;
  v10[31] = &v19;
  v10[32] = v4;
  v12 = *(const char **)(a2 + 504);
  if ( !v12 )
    v12 = *(const char **)(a2 + 392);
  v13 = strnlen(v12, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v11 + 8, v12);
      if ( a3 )
        v15 = *a3;
      else
        v15 = 0;
      v16 = v20;
      v17 = v21[0];
      *(_DWORD *)(v11 + 40) = v15;
      result = perf_trace_run_bpf_submit(v11, 44, v16, v6, 1, v17, StatusReg + v8, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_set_multicast_to_unicast(v18);
}
