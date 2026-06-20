_QWORD *__fastcall perf_trace_cache_alloc_bw_ratio(
        _QWORD *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v13; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v15; // x9
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v13 = result[13];
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( result[14] || *(_QWORD *)(StatusReg + v13) )
  {
    result = (_QWORD *)perf_trace_buf_alloc(52, v18, &v17);
    if ( result )
    {
      v15 = (_QWORD *)v18[0];
      *(_QWORD *)(v18[0] + 232LL) = &v19;
      v15[31] = &v16;
      v15[32] = v7;
      v15[33] = 5;
      result[1] = a2;
      result[2] = a3;
      result[3] = a4;
      result[4] = a5;
      result[5] = a6;
      result = (_QWORD *)perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
