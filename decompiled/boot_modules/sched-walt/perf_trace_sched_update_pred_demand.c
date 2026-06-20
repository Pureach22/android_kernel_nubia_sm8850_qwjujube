__int64 __fastcall perf_trace_sched_update_pred_demand(
        __int64 result,
        __int64 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x27
  __int64 v16; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v18; // x9
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  int v22; // [xsp+8h] [xbp-18h]
  int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v22 = a7;
  v9 = v8;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    result = perf_trace_buf_alloc(68, v24, &v23);
    if ( result )
    {
      v18 = (_QWORD *)v24[0];
      *(_QWORD *)(v24[0] + 232LL) = &vars0;
      v18[31] = &v21;
      v18[32] = v9;
      v18[33] = 5;
      v19 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v19;
      LODWORD(v19) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 28) = a3;
      *(_DWORD *)(result + 32) = a4;
      *(_DWORD *)(result + 24) = v19;
      v20 = *(_QWORD *)(a8 + 140);
      *(_QWORD *)(result + 44) = *(_QWORD *)(a8 + 148);
      *(_QWORD *)(result + 36) = v20;
      *(_DWORD *)(result + 52) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 56) = a5;
      LODWORD(v19) = v22;
      *(_DWORD *)(result + 60) = a6;
      *(_DWORD *)(result + 64) = v19;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
