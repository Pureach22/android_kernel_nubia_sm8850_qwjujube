__int64 __fastcall perf_trace_kgsl_mem_sync_cache(__int64 result, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  __int64 v15; // x23
  __int64 v16; // x8
  int v17; // w8
  __int64 v18; // x2
  __int64 v19; // x5
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(68, v22, &v21);
    if ( result )
    {
      v14 = (_QWORD *)v22[0];
      v15 = result;
      *(_QWORD *)(v22[0] + 232LL) = &v23;
      v14[33] = 5;
      v14[31] = &v20;
      v14[32] = v6;
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      kgsl_get_memory_usage((char *)(result + 16), 0x10u, *(_QWORD *)(a2 + 80));
      v16 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v16 )
        LODWORD(v16) = *(_DWORD *)(v16 + 112);
      *(_DWORD *)(v15 + 32) = v16;
      v17 = *(_DWORD *)(a2 + 248);
      *(_QWORD *)(v15 + 48) = a3;
      *(_DWORD *)(v15 + 36) = v17;
      *(_DWORD *)(v15 + 40) = a5;
      if ( !a4 )
        a4 = *(_QWORD *)(a2 + 48);
      v18 = v21;
      v19 = v22[0];
      *(_QWORD *)(v15 + 56) = a4;
      result = perf_trace_run_bpf_submit(v15, 68, v18, v9, 1, v19, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
