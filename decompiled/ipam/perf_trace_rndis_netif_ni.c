_QWORD *__fastcall perf_trace_rndis_netif_ni(_QWORD *result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  _QWORD *v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  __int64 v9; // x2
  __int64 v10; // x5
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v12; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v14; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v6 = result[13];
  v12 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( result[14] || *(_QWORD *)(StatusReg + v6) )
  {
    result = (_QWORD *)perf_trace_buf_alloc(20, v13, &v12);
    if ( result )
    {
      v8 = (_QWORD *)v13[0];
      v9 = v12;
      *(_QWORD *)(v13[0] + 232LL) = &v14;
      v10 = v13[0];
      v8[31] = &v11;
      v8[32] = v3;
      v8[33] = 5;
      result[1] = a2;
      result = (_QWORD *)perf_trace_run_bpf_submit(result, 20, v9, v4, 1, v10, StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
