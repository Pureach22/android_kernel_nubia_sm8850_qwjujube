__int64 __fastcall perf_trace_kgsl_mem_map(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v14; // x2
  __int64 v15; // x5
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(60, v18, &v17);
    if ( result )
    {
      v10 = (_QWORD *)v18[0];
      *(_QWORD *)(v18[0] + 232LL) = &vars0;
      v10[31] = &v16;
      v10[32] = v4;
      v10[33] = 5;
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      v11 = *(_QWORD *)(a2 + 48);
      *(_DWORD *)(result + 24) = a3;
      *(_QWORD *)(result + 16) = v11;
      *(_DWORD *)(result + 28) = (unsigned __int8)*(_DWORD *)(a2 + 80) >> 5;
      v12 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v12 )
        LODWORD(v12) = *(_DWORD *)(v12 + 112);
      *(_DWORD *)(result + 32) = v12;
      v13 = result;
      kgsl_get_memory_usage((char *)(result + 36), 0x10u, *(_QWORD *)(a2 + 80));
      v14 = v17;
      v15 = v18[0];
      *(_DWORD *)(v13 + 52) = *(_DWORD *)(a2 + 248);
      result = perf_trace_run_bpf_submit(v13, 60, v14, v6, 1, v15, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
