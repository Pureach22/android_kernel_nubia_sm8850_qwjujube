__int64 __fastcall perf_trace_sde_perf_calc_crtc(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
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
  __int64 v23; // x9
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
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
    result = perf_trace_buf_alloc(76, v26, &v25);
    if ( result )
    {
      v20 = (_QWORD *)v26[0];
      v21 = v25;
      *(_QWORD *)(v26[0] + 232LL) = &vars0;
      v20[31] = &v24;
      v22 = v26[0];
      v20[32] = v10;
      v20[33] = 5;
      v23 = v24;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_QWORD *)(result + 56) = v23;
      *(_DWORD *)(result + 64) = a9;
      result = perf_trace_run_bpf_submit(result, 76, v21, v12, 1, v22, StatusReg + v18, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
