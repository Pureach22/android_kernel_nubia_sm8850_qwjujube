__int64 __fastcall perf_trace_venus_hfi_var(__int64 result, int a2, int a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x2
  __int64 v16; // x5
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v18 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(28, v19, &v18);
    if ( result )
    {
      v14 = (_QWORD *)v19[0];
      v15 = v18;
      *(_QWORD *)(v19[0] + 232LL) = &vars0;
      v16 = v19[0];
      v14[31] = &v17;
      v14[32] = v6;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      result = perf_trace_run_bpf_submit(result, 28, v15, v9, 1, v16, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
