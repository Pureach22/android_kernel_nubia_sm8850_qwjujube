__int64 __fastcall perf_trace_sde_cmd_release_bw(__int64 result, int a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v7; // x9
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v11; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v5 = *(_QWORD *)(result + 104);
  v9 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    result = perf_trace_buf_alloc(12, v10, &v9);
    if ( result )
    {
      v7 = (_QWORD *)v10[0];
      *(_QWORD *)(v10[0] + 232LL) = &v11;
      v7[31] = &v8;
      v7[32] = v3;
      v7[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
