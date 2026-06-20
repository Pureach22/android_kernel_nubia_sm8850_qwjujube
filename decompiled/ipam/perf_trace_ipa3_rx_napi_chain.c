_QWORD *__fastcall perf_trace_ipa3_rx_napi_chain(_QWORD *result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  _QWORD *v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x9
  __int64 v13; // x2
  __int64 v14; // x5
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v16; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v18; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v10 = result[13];
  v16 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( result[14] || *(_QWORD *)(StatusReg + v10) )
  {
    result = (_QWORD *)perf_trace_buf_alloc(36, v17, &v16);
    if ( result )
    {
      v12 = (_QWORD *)v17[0];
      v13 = v16;
      *(_QWORD *)(v17[0] + 232LL) = &v18;
      v14 = v17[0];
      v12[31] = &v15;
      v12[32] = v5;
      v12[33] = 5;
      result[1] = a2;
      result[2] = a3;
      result[3] = a4;
      result = (_QWORD *)perf_trace_run_bpf_submit(result, 36, v13, v8, 1, v14, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
