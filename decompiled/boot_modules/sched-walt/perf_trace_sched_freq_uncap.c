__int64 __fastcall perf_trace_sched_freq_uncap(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        char a8)
{
  __int64 v8; // x30
  __int64 v9; // x26
  __int64 v11; // x19
  __int64 v17; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v19; // x9
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // x9
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v23 = a7;
  v9 = v8;
  v11 = result;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v17 = *(_QWORD *)(result + 104);
  v24 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    result = perf_trace_buf_alloc(52, v25, &v24);
    if ( result )
    {
      v19 = (_QWORD *)v25[0];
      v20 = v24;
      *(_QWORD *)(v25[0] + 232LL) = &vars0;
      v19[31] = &v23;
      v21 = v25[0];
      v19[32] = v9;
      v19[33] = 5;
      v22 = v23;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_QWORD *)(result + 32) = v22;
      *(_DWORD *)(result + 40) = 1LL << a8;
      result = perf_trace_run_bpf_submit(result, 52, v20, v11, 1, v21, StatusReg + v17, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
