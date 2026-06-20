__int64 __fastcall perf_trace_fastrpc_perf_counters(
        __int64 result,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v13; // x30
  __int64 v14; // x27
  __int64 v21; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v23; // x9
  __int64 v24; // x10
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v25 = a8;
  v14 = v13;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v21 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v21) )
  {
    result = perf_trace_buf_alloc(100, v27, &v26);
    if ( result )
    {
      v23 = (_QWORD *)v27[0];
      *(_QWORD *)(v27[0] + 232LL) = &vars0;
      v23[31] = &v25;
      v23[32] = v14;
      v23[33] = 5;
      v24 = v25;
      *(_QWORD *)(result + 56) = a9;
      *(_QWORD *)(result + 48) = v24;
      *(_QWORD *)(result + 64) = a10;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_QWORD *)(result + 16) = a4;
      *(_QWORD *)(result + 24) = a5;
      *(_QWORD *)(result + 32) = a6;
      *(_QWORD *)(result + 40) = a7;
      *(_QWORD *)(result + 72) = a11;
      *(_QWORD *)(result + 80) = a12;
      *(_QWORD *)(result + 88) = a13;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
