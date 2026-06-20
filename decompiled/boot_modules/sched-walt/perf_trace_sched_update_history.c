__int64 __fastcall perf_trace_sched_update_history(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        __int16 a9)
{
  __int64 v9; // x30
  __int64 v10; // x27
  __int64 v12; // x19
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x22
  _QWORD *v20; // x9
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v30 = a7;
  v10 = v9;
  v12 = result;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v18 = *(_QWORD *)(result + 104);
  v31 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    result = perf_trace_buf_alloc(116, v32, &v31);
    if ( result )
    {
      v20 = (_QWORD *)v32[0];
      *(_QWORD *)(v32[0] + 232LL) = &vars0;
      v20[31] = &v30;
      v20[32] = v10;
      v20[33] = 5;
      v21 = *(_QWORD *)(a3 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a3 + 2320);
      *(_QWORD *)(result + 16) = v21;
      LODWORD(v21) = *(_DWORD *)(a3 + 1800);
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      *(_DWORD *)(result + 24) = v21;
      *(_DWORD *)(result + 28) = a4;
      *(_DWORD *)(result + 40) = *(_DWORD *)(a8 + 28);
      *(_DWORD *)(result + 44) = *(_DWORD *)(a8 + 32);
      *(_DWORD *)(result + 48) = *(unsigned __int16 *)(a8 + 160);
      v22 = *(_QWORD *)(a8 + 44);
      v23 = *(_QWORD *)(a8 + 36);
      *(_DWORD *)(result + 68) = *(_DWORD *)(a8 + 52);
      *(_QWORD *)(result + 60) = v22;
      *(_QWORD *)(result + 52) = v23;
      v24 = *(_QWORD *)(a8 + 56);
      *(_WORD *)(result + 80) = *(_WORD *)(a8 + 64);
      v25 = v30;
      *(_QWORD *)(result + 72) = v24;
      *(_DWORD *)(result + 84) = *(_DWORD *)(v25 + 24);
      LODWORD(v25) = *(_DWORD *)(a2 + 3632);
      *(_WORD *)(result + 92) = a9;
      *(_DWORD *)(result + 88) = v25;
      LOBYTE(v25) = *(_BYTE *)(a8 + 384);
      v26 = result;
      *(_BYTE *)(result + 94) = v25;
      *(_QWORD *)(result + 96) = uclamp_eff_value(a3, 0);
      v27 = uclamp_eff_value(a3, 1);
      v28 = v31;
      v29 = v32[0];
      *(_QWORD *)(v26 + 104) = v27;
      result = perf_trace_run_bpf_submit(v26, 116, v28, v12, 1, v29, StatusReg + v18, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
