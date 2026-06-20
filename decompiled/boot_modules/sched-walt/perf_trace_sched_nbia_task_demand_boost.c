__int64 __fastcall perf_trace_sched_nbia_task_demand_boost(__int64 result, __int64 a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v11; // x9
  __int64 v12; // x8
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  int v14; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v9 = *(_QWORD *)(result + 104);
  v14 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    result = perf_trace_buf_alloc(36, v15, &v14);
    if ( result )
    {
      v11 = (_QWORD *)v15[0];
      *(_QWORD *)(v15[0] + 232LL) = &v16;
      v11[31] = &v13;
      v11[32] = v5;
      v11[33] = 5;
      v12 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v12;
      LODWORD(v12) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 32) = a4;
      *(_DWORD *)(result + 24) = v12;
      *(_DWORD *)(result + 28) = a3;
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
