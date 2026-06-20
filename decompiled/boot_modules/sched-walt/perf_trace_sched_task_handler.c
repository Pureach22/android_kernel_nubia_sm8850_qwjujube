__int64 __fastcall perf_trace_sched_task_handler(
        __int64 result,
        __int64 a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x30
  __int64 v11; // x27
  __int64 v13; // x19
  __int64 v19; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v21; // x9
  __int64 v22; // x2
  __int64 v23; // x5
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v26 = a8;
  v11 = v10;
  v13 = result;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v19 = *(_QWORD *)(result + 104);
  v27 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v19) )
  {
    result = perf_trace_buf_alloc(92, v28, &v27);
    if ( result )
    {
      v21 = (_QWORD *)v28[0];
      v22 = v27;
      *(_QWORD *)(v28[0] + 232LL) = &vars0;
      v21[31] = &v26;
      v23 = v28[0];
      v21[32] = v11;
      v21[33] = 5;
      v24 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v24;
      v25 = v26;
      LODWORD(v24) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 32) = a4;
      *(_QWORD *)(result + 56) = a7;
      *(_QWORD *)(result + 64) = v25;
      *(_DWORD *)(result + 24) = v24;
      *(_QWORD *)(result + 40) = a5;
      *(_QWORD *)(result + 48) = a6;
      *(_DWORD *)(result + 28) = a3;
      *(_QWORD *)(result + 72) = a9;
      *(_QWORD *)(result + 80) = a10;
      result = perf_trace_run_bpf_submit(result, 92, v22, v13, 1, v23, StatusReg + v19, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
