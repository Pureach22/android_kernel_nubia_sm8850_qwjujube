__int64 __fastcall perf_trace_fastrpc_context_complete(
        __int64 result,
        int a2,
        __int64 a3,
        int a4,
        __int64 a5,
        int a6,
        int a7)
{
  __int64 v7; // x30
  __int64 v8; // x26
  __int64 v15; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v17; // x9
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v8 = v7;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v15 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    result = perf_trace_buf_alloc(52, v20, &v19);
    if ( result )
    {
      v17 = (_QWORD *)v20[0];
      *(_QWORD *)(v20[0] + 232LL) = &vars0;
      v17[31] = &v18;
      v17[32] = v8;
      v17[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 40) = a6;
      *(_DWORD *)(result + 44) = a7;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
