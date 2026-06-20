__int64 __fastcall perf_trace_kgsl_mem_remove_bind_range(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x8
  __int64 v16; // x2
  __int64 v17; // x5
  int v18; // w8
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(44, v21, &v20);
    if ( result )
    {
      v14 = (_QWORD *)v21[0];
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v14[31] = &v19;
      v14[32] = v6;
      v14[33] = 5;
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32) + a3;
      v15 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v15 )
        LODWORD(v15) = *(_DWORD *)(v15 + 112);
      *(_DWORD *)(result + 20) = v15;
      v16 = v20;
      v17 = v21[0];
      *(_DWORD *)(result + 16) = *(_DWORD *)(a2 + 248);
      v18 = *(_DWORD *)(a4 + 248);
      *(_QWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 24) = v18;
      result = perf_trace_run_bpf_submit(result, 44, v16, v9, 1, v17, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
