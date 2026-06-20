__int64 __fastcall perf_trace_kgsl_mem_free(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x2
  __int64 v12; // x5
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v14; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v14 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v6) )
  {
    result = perf_trace_buf_alloc(60, v15, &v14);
    if ( result )
    {
      v8 = (_QWORD *)v15[0];
      *(_QWORD *)(v15[0] + 232LL) = &v16;
      v8[31] = &v13;
      v8[32] = v3;
      v8[33] = 5;
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(result + 16) = *(_QWORD *)(a2 + 48);
      *(_DWORD *)(result + 24) = (unsigned __int8)*(_DWORD *)(a2 + 80) >> 5;
      v9 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v9 )
        LODWORD(v9) = *(_DWORD *)(v9 + 112);
      *(_DWORD *)(result + 32) = v9;
      v10 = result;
      kgsl_get_memory_usage((char *)(result + 36), 0x10u, *(_QWORD *)(a2 + 80));
      v11 = v14;
      v12 = v15[0];
      *(_DWORD *)(v10 + 52) = *(_DWORD *)(a2 + 248);
      result = perf_trace_run_bpf_submit(v10, 60, v11, v4, 1, v12, StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
