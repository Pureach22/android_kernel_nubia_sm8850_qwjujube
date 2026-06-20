__int64 __fastcall perf_trace_adreno_gpu_vote_params(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        __int64 a12)
{
  __int64 v12; // x30
  __int64 v13; // x27
  __int64 v15; // x19
  __int64 v21; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v23; // x9
  __int64 v24; // x5
  __int64 v25; // x2
  int v26; // w10
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  int v28; // [xsp+8h] [xbp-18h]
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v28 = a8;
  v13 = v12;
  v15 = result;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  v21 = *(_QWORD *)(result + 104);
  v29 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v21) )
  {
    result = perf_trace_buf_alloc(60, v30, &v29);
    if ( result )
    {
      v23 = (_QWORD *)v30[0];
      *(_QWORD *)(v30[0] + 248LL) = &v27;
      v23[29] = &vars0;
      v24 = v30[0];
      v23[32] = v13;
      v23[33] = 5;
      v26 = v28;
      v25 = v29;
      *(_DWORD *)(result + 36) = a9;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 32) = v26;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 28) = a7;
      *(_DWORD *)(result + 40) = a10;
      *(_DWORD *)(result + 44) = a11;
      *(_QWORD *)(result + 48) = a12;
      result = perf_trace_run_bpf_submit(result, 60, v25, v15, 1, v24, StatusReg + v21, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
