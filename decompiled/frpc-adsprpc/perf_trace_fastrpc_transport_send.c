__int64 __fastcall perf_trace_fastrpc_transport_send(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x26
  __int64 v16; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v18; // x9
  __int64 v19; // x8
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v20 = a8;
  v9 = v8;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    result = perf_trace_buf_alloc(60, v22, &v21);
    if ( result )
    {
      v18 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &vars0;
      v18[31] = &v20;
      v19 = v20;
      v18[32] = v9;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      *(_QWORD *)(result + 40) = a7;
      *(_QWORD *)(result + 48) = v19;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
