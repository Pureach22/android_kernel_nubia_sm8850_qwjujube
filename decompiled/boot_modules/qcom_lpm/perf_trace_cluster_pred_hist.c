__int64 __fastcall perf_trace_cluster_pred_hist(__int64 result, int a2, __int64 a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v13; // x9
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  int v15; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v11 = *(_QWORD *)(result + 104);
  v15 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    result = perf_trace_buf_alloc(36, v16, &v15);
    if ( result )
    {
      v13 = (_QWORD *)v16[0];
      *(_QWORD *)(v16[0] + 232LL) = &vars0;
      v13[31] = &v14;
      v13[32] = v6;
      v13[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 28) = a5;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
