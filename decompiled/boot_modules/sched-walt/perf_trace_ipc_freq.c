__int64 __fastcall perf_trace_ipc_freq(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7,
        int a8,
        __int64 a9)
{
  __int64 v9; // x30
  __int64 v10; // x27
  __int64 v12; // x19
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v20; // x9
  __int64 v21; // x5
  __int64 v22; // x2
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  int v24; // [xsp+8h] [xbp-18h]
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v24 = a8;
  v10 = v9;
  v12 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v18 = *(_QWORD *)(result + 104);
  v25 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    result = perf_trace_buf_alloc(60, v26, &v25);
    if ( result )
    {
      v20 = (_QWORD *)v26[0];
      *(_QWORD *)(v26[0] + 232LL) = &vars0;
      v20[31] = &v23;
      v21 = v26[0];
      v20[32] = v10;
      v20[33] = 5;
      LODWORD(v20) = v24;
      v22 = v25;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_QWORD *)(result + 24) = a6;
      *(_QWORD *)(result + 32) = a7;
      *(_DWORD *)(result + 40) = (_DWORD)v20;
      *(_QWORD *)(result + 48) = a9;
      result = perf_trace_run_bpf_submit(result, 60, v22, v12, 1, v21, StatusReg + v18, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
