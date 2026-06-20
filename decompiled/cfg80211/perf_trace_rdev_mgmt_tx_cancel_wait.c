__int64 __fastcall perf_trace_rdev_mgmt_tx_cancel_wait(__int64 result, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x22
  const char *v14; // x24
  size_t v15; // x0
  unsigned __int64 v16; // x2
  int v17; // w8
  __int64 v18; // x2
  __int64 v19; // x5
  __int64 v20; // x0
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10)
    || (result = perf_trace_buf_alloc(60, v23, &v22)) == 0 )
  {
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = (_QWORD *)v23[0];
  v13 = result;
  *(_QWORD *)(v23[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v21;
  v12[32] = v5;
  v14 = *(const char **)(a2 + 504);
  if ( !v14 )
    v14 = *(const char **)(a2 + 392);
  v15 = strnlen(v14, 0x20u);
  if ( v15 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v15 == 32 )
      v16 = 32;
    else
      v16 = v15 + 1;
    if ( v16 < 0x21 )
    {
      sized_strscpy(v13 + 8, v14);
      v17 = 0;
      if ( a3 )
      {
        if ( a3 <= 0xFFFFFFFFFFFFF000LL )
          v17 = *(_DWORD *)(a3 + 40);
      }
      v18 = v22;
      v19 = v23[0];
      *(_DWORD *)(v13 + 40) = v17;
      *(_QWORD *)(v13 + 48) = a4;
      result = perf_trace_run_bpf_submit(v13, 60, v18, v8, 1, v19, StatusReg + v10, 0);
      goto LABEL_15;
    }
  }
  v20 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_set_power_mgmt(v20);
}
