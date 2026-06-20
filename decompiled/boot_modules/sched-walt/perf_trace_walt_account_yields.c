__int64 __fastcall perf_trace_walt_account_yields(
        __int64 result,
        __int64 a2,
        __int64 a3,
        char a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v9; // x27
  __int64 v11; // x19
  __int64 v17; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v19; // x9
  __int64 v20; // x5
  __int64 v21; // x2
  int v22; // w8
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  int v24; // [xsp+8h] [xbp-18h]
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v24 = a8;
  v9 = v8;
  v11 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v17 = *(_QWORD *)(result + 104);
  v25 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    result = perf_trace_buf_alloc(52, v26, &v25);
    if ( result )
    {
      v19 = (_QWORD *)v26[0];
      *(_QWORD *)(v26[0] + 232LL) = &vars0;
      v19[31] = &v23;
      v20 = v26[0];
      v22 = v24;
      v21 = v25;
      v19[32] = v9;
      v19[33] = 5;
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_BYTE *)(result + 24) = a4;
      *(_DWORD *)(result + 28) = a5;
      *(_DWORD *)(result + 32) = a6;
      *(_DWORD *)(result + 36) = a7;
      *(_DWORD *)(result + 40) = v22;
      result = perf_trace_run_bpf_submit(result, 52, v21, v11, 1, v20, StatusReg + v17, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
