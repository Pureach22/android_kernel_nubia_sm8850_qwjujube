__int64 __fastcall perf_trace_process_invoke_req_wait(__int64 result, const char *a2, int a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  _DWORD *v15; // x23
  size_t v16; // x0
  unsigned __int64 v17; // x2
  __int64 v18; // x2
  __int64 v19; // x5
  __int64 v20; // x0
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_10;
  result = perf_trace_buf_alloc(68, v23, &v22);
  if ( !result )
    goto LABEL_10;
  v14 = (_QWORD *)v23[0];
  v15 = (_DWORD *)result;
  *(_QWORD *)(v23[0] + 232LL) = &v24;
  v14[33] = 5;
  v14[31] = &v21;
  v14[32] = v6;
  v16 = strnlen(a2, 0x30u);
  if ( v16 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v16 == 48 )
      v17 = 48;
    else
      v17 = v16 + 1;
    if ( v17 < 0x31 )
    {
      sized_strscpy(v15 + 2, a2);
      v18 = v22;
      v19 = v23[0];
      v15[14] = a3;
      v15[15] = a4;
      v15[16] = a5;
      result = perf_trace_run_bpf_submit(v15, 68, v18, v9, 1, v19, StatusReg + v12, 0);
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v20 = _fortify_panic(7, 48, v17);
  return trace_event_raw_event_process_invoke_req_ret(v20);
}
