__int64 __fastcall perf_trace_mem_object_release(__int64 result, const char *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  __int64 v11; // x21
  size_t v12; // x0
  unsigned __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x5
  __int64 v16; // x0
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v20; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v18 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8) )
    goto LABEL_10;
  result = perf_trace_buf_alloc(68, v19, &v18);
  if ( !result )
    goto LABEL_10;
  v10 = (_QWORD *)v19[0];
  v11 = result;
  *(_QWORD *)(v19[0] + 232LL) = &v20;
  v10[33] = 5;
  v10[31] = &v17;
  v10[32] = v4;
  v12 = strnlen(a2, 0x30u);
  if ( v12 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v12 == 48 )
      v13 = 48;
    else
      v13 = v12 + 1;
    if ( v13 < 0x31 )
    {
      sized_strscpy(v11 + 8, a2);
      v14 = v18;
      v15 = v19[0];
      *(_QWORD *)(v11 + 56) = a3;
      result = perf_trace_run_bpf_submit(v11, 68, v14, v6, 1, v15, StatusReg + v8, 0);
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v16 = _fortify_panic(7, 48, v13);
  return trace_event_raw_event_cbo_dispatch_handle(v16);
}
