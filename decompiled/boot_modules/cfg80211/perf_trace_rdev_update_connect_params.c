__int64 __fastcall perf_trace_rdev_update_connect_params(__int64 result, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v13; // x9
  __int64 v14; // x22
  const char *v15; // x24
  size_t v16; // x0
  unsigned __int64 v17; // x2
  __int64 v18; // x8
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // x0
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v11 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(68, v24, &v23);
  if ( !result )
    goto LABEL_12;
  v13 = (_QWORD *)v24[0];
  v14 = result;
  *(_QWORD *)(v24[0] + 232LL) = &vars0;
  v13[33] = 5;
  v13[31] = &v22;
  v13[32] = v6;
  v15 = *(const char **)(a2 + 504);
  if ( !v15 )
    v15 = *(const char **)(a2 + 392);
  v16 = strnlen(v15, 0x20u);
  if ( v16 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v16 == 32 )
      v17 = 32;
    else
      v17 = v16 + 1;
    if ( v17 < 0x21 )
    {
      sized_strscpy(v14 + 8, v15);
      v18 = *(_QWORD *)(a3 + 304);
      v19 = v23;
      v20 = v24[0];
      *(_QWORD *)(v14 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v14 + 48) = v18;
      *(_DWORD *)(v14 + 56) = *(_DWORD *)(a3 + 224);
      *(_DWORD *)(v14 + 60) = a5;
      result = perf_trace_run_bpf_submit(v14, 68, v19, v9, 1, v20, StatusReg + v11, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v21 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_set_cqm_rssi_config(v21);
}
