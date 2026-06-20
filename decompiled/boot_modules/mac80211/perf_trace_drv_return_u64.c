__int64 __fastcall perf_trace_drv_return_u64(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  __int64 v11; // x21
  __int64 v12; // x8
  const char *v13; // x22
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x5
  __int64 v18; // x0
  __int64 v19; // x14
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(52, v22, &v21);
  if ( !result )
    goto LABEL_12;
  v10 = (_QWORD *)v22[0];
  v11 = result;
  *(_QWORD *)(v22[0] + 232LL) = &v23;
  v10[33] = 5;
  v10[31] = &v20;
  v10[32] = v4;
  v12 = *(_QWORD *)(a2 + 72);
  v13 = *(const char **)(v12 + 504);
  if ( !v13 )
    v13 = *(const char **)(v12 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v11 + 8, v13);
      v16 = v21;
      v17 = v22[0];
      *(_QWORD *)(v11 + 40) = a3;
      result = perf_trace_run_bpf_submit(v11, 52, v16, v6, 1, v17, StatusReg + v8, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7);
  if ( v19 )
    JUMPOUT(0xC54C8);
  return trace_event_raw_event_drv_set_wakeup(v18);
}
