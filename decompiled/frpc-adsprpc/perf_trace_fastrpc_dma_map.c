__int64 __fastcall perf_trace_fastrpc_dma_map(
        __int64 result,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v9; // x26
  __int64 v16; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v18; // x9
  int v19; // w8
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  int v21; // [xsp+8h] [xbp-18h]
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v21 = a8;
  v9 = v8;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    result = perf_trace_buf_alloc(52, v23, &v22);
    if ( result )
    {
      v18 = (_QWORD *)v23[0];
      *(_QWORD *)(v23[0] + 232LL) = &vars0;
      v18[31] = &v20;
      v19 = v21;
      v18[32] = v9;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_QWORD *)(result + 16) = a4;
      *(_QWORD *)(result + 24) = a5;
      *(_QWORD *)(result + 32) = a6;
      *(_DWORD *)(result + 40) = a7;
      *(_DWORD *)(result + 44) = v19;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
