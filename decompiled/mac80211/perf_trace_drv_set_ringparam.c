__int64 __fastcall perf_trace_drv_set_ringparam(__int64 result, __int64 a2, int a3, int a4)
{
  __int64 v4; // x30
  int v5; // s13
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v13; // x9
  __int64 v14; // x22
  __int64 v15; // x8
  const char *v16; // x23
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // x0
  int v22; // s0
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v9 = result;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v11 = *(_QWORD *)(result + 104);
  v24 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(52, v25, &v24);
  if ( !result )
    goto LABEL_12;
  v13 = (_QWORD *)v25[0];
  v14 = result;
  *(_QWORD *)(v25[0] + 232LL) = &vars0;
  v13[33] = 5;
  v13[31] = &v23;
  v13[32] = v6;
  v15 = *(_QWORD *)(a2 + 72);
  v16 = *(const char **)(v15 + 504);
  if ( !v16 )
    v16 = *(const char **)(v15 + 392);
  v17 = strnlen(v16, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v14 + 8, v16);
      v19 = v24;
      v20 = v25[0];
      *(_DWORD *)(v14 + 40) = a3;
      *(_DWORD *)(v14 + 44) = a4;
      result = perf_trace_run_bpf_submit(v14, 52, v19, v9, 1, v20, StatusReg + v11, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v21 = _fortify_panic(7);
  *(_DWORD *)(v6 + 136) = v22;
  *(_DWORD *)(v6 + 140) = v5;
  return trace_event_raw_event_drv_get_ringparam(v21);
}
