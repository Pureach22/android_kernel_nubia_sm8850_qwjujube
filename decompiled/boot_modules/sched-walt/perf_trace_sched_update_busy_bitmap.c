__int64 __fastcall perf_trace_sched_update_busy_bitmap(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        __int64 a7,
        __int64 a8,
        int a9)
{
  __int64 v9; // x30
  __int64 v10; // x27
  __int64 v12; // x19
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v20; // x9
  __int64 v21; // x2
  __int64 v22; // x5
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v25 = a8;
  v10 = v9;
  v12 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v18 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    result = perf_trace_buf_alloc(100, v27, &v26);
    if ( result )
    {
      v20 = (_QWORD *)v27[0];
      v21 = v26;
      *(_QWORD *)(v27[0] + 232LL) = &vars0;
      v20[31] = &v25;
      v22 = v27[0];
      v20[32] = v10;
      v20[33] = 5;
      v23 = v25;
      v24 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v24;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      LODWORD(v24) = *(_DWORD *)(a2 + 144);
      *(_QWORD *)(result + 32) = a7;
      *(_DWORD *)(result + 28) = v24;
      *(_QWORD *)(result + 40) = *(_QWORD *)(a4 + 8);
      *(_DWORD *)(result + 48) = *(_DWORD *)(a3 + 3632);
      *(_DWORD *)(result + 52) = *(_DWORD *)(a4 + 364);
      *(_DWORD *)(result + 56) = a6;
      *(_DWORD *)(result + 60) = *(unsigned __int16 *)(a4 + 388);
      LODWORD(v24) = *(_DWORD *)(a4 + 392);
      *(_QWORD *)(result + 72) = v23;
      *(_DWORD *)(result + 80) = a9;
      *(_DWORD *)(result + 64) = v24;
      *(_QWORD *)(result + 88) = *(_QWORD *)(a5 + 656);
      result = perf_trace_run_bpf_submit(result, 100, v21, v12, 1, v22, StatusReg + v18, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
