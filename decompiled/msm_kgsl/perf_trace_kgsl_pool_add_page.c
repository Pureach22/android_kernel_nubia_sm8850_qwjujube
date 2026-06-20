__int64 __fastcall perf_trace_kgsl_pool_add_page(__int64 result, int a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x2
  __int64 v12; // x5
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v14; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v14 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(20, v15, &v14);
    if ( result )
    {
      v10 = (_QWORD *)v15[0];
      v11 = v14;
      *(_QWORD *)(v15[0] + 232LL) = &vars0;
      v12 = v15[0];
      v10[31] = &v13;
      v10[32] = v4;
      v10[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      result = perf_trace_run_bpf_submit(result, 20, v11, v6, 1, v12, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
