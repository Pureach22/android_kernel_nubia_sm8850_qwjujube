__int64 __fastcall perf_trace_cluster_enter(__int64 result, int a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v11; // x9
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v15; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v9 = *(_QWORD *)(result + 104);
  v13 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    result = perf_trace_buf_alloc(20, v14, &v13);
    if ( result )
    {
      v11 = (_QWORD *)v14[0];
      *(_QWORD *)(v14[0] + 232LL) = &v15;
      v11[31] = &v12;
      v11[32] = v5;
      v11[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
