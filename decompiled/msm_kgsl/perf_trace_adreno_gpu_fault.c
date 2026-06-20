__int64 __fastcall perf_trace_adreno_gpu_fault(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        int a8,
        __int64 a9,
        int a10,
        int a11)
{
  __int64 v11; // x30
  __int64 v12; // x27
  __int64 v14; // x19
  __int64 v20; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v22; // x9
  __int64 v23; // x5
  __int64 v24; // x2
  int v25; // w10
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  int v27; // [xsp+8h] [xbp-18h]
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v27 = a8;
  v12 = v11;
  v14 = result;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v20 = *(_QWORD *)(result + 104);
  v28 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v20) )
  {
    result = perf_trace_buf_alloc(68, v29, &v28);
    if ( result )
    {
      v22 = (_QWORD *)v29[0];
      *(_QWORD *)(v29[0] + 232LL) = &vars0;
      v22[31] = &v26;
      v23 = v29[0];
      v22[32] = v12;
      v22[33] = 5;
      v25 = v27;
      v24 = v28;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 40) = v25;
      *(_DWORD *)(result + 24) = a6;
      *(_QWORD *)(result + 32) = a7;
      *(_QWORD *)(result + 48) = a9;
      *(_DWORD *)(result + 56) = a10;
      *(_DWORD *)(result + 60) = a11;
      result = perf_trace_run_bpf_submit(result, 68, v24, v14, 1, v23, StatusReg + v20, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
