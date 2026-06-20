__int64 __fastcall perf_trace_cbo_dispatch_wait(__int64 result, const char *a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x22
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x5
  __int64 v18; // x0
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10) )
    goto LABEL_10;
  result = perf_trace_buf_alloc(68, v21, &v20);
  if ( !result )
    goto LABEL_10;
  v12 = (_QWORD *)v21[0];
  v13 = result;
  *(_QWORD *)(v21[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v19;
  v12[32] = v5;
  v14 = strnlen(a2, 0x30u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v14 == 48 )
      v15 = 48;
    else
      v15 = v14 + 1;
    if ( v15 < 0x31 )
    {
      sized_strscpy(v13 + 8, a2);
      v16 = v20;
      v17 = v21[0];
      *(_DWORD *)(v13 + 56) = a3;
      *(_DWORD *)(v13 + 60) = a4;
      result = perf_trace_run_bpf_submit(v13, 68, v16, v8, 1, v17, StatusReg + v10, 0);
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7, 48, v15);
  return trace_event_raw_event_cbo_dispatch_ret(v18);
}
