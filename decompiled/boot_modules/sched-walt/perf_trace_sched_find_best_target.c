__int64 __fastcall perf_trace_sched_find_best_target(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  __int64 v11; // x30
  __int64 v12; // x27
  __int64 v14; // x19
  __int64 v20; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v22; // x9
  __int64 v23; // x8
  int v24; // w10
  __int64 v25; // x2
  __int64 v26; // x5
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  int v28; // [xsp+8h] [xbp-18h]
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v28 = a8;
  v12 = v11;
  v14 = result;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  v20 = *(_QWORD *)(result + 104);
  v29 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v20) )
  {
    result = perf_trace_buf_alloc(92, v30, &v29);
    if ( result )
    {
      v22 = (_QWORD *)v30[0];
      *(_QWORD *)(v30[0] + 232LL) = &vars0;
      v22[31] = &v27;
      v22[32] = v12;
      v22[33] = 5;
      v23 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v23;
      LODWORD(v23) = *(_DWORD *)(a2 + 1800);
      *(_QWORD *)(result + 32) = a3;
      *(_DWORD *)(result + 40) = a4;
      *(_DWORD *)(result + 24) = v23;
      LODWORD(v23) = v28;
      *(_QWORD *)(result + 48) = a5;
      *(_DWORD *)(result + 56) = a6;
      *(_DWORD *)(result + 60) = a7;
      *(_DWORD *)(result + 64) = v23;
      *(_DWORD *)(result + 68) = a9;
      v24 = *(_DWORD *)(a2 + 144);
      if ( v24 )
        LOBYTE(v24) = *(_BYTE *)(a2 + 273) == 0;
      v25 = v29;
      v26 = v30[0];
      *(_BYTE *)(result + 72) = v24;
      *(_DWORD *)(result + 76) = a10;
      *(_DWORD *)(result + 80) = a11;
      result = perf_trace_run_bpf_submit(result, 92, v25, v14, 1, v26, StatusReg + v20, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
