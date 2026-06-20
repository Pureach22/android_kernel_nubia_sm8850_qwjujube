__int64 __fastcall perf_trace_sde_perf_uidle_status_v1(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  __int64 v10; // x30
  __int64 v11; // x27
  __int64 v13; // x19
  __int64 v19; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v21; // x9
  __int64 v22; // x5
  __int64 v23; // x2
  int v24; // w10
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  int v26; // [xsp+8h] [xbp-18h]
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
    result = perf_trace_buf_alloc(44, v28, &v27);
    if ( result )
    {
      v21 = (_QWORD *)v28[0];
      *(_QWORD *)(v28[0] + 232LL) = &vars0;
      v21[31] = &v25;
      v22 = v28[0];
      v21[32] = v11;
      v21[33] = 5;
      v24 = v26;
      v23 = v27;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 28) = a7;
      *(_DWORD *)(result + 32) = v24;
      *(_DWORD *)(result + 36) = a9;
      *(_DWORD *)(result + 40) = a10;
      result = perf_trace_run_bpf_submit(result, 44, v23, v13, 1, v22, StatusReg + v19, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
