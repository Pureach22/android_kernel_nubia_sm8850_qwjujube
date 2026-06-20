__int64 __fastcall perf_trace_sched_nbia_task_sched_switch(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v7; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v9; // x9
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v7 = *(_QWORD *)(result + 104);
  v13 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    result = perf_trace_buf_alloc(76, v14, &v13);
    if ( result )
    {
      v9 = (_QWORD *)v14[0];
      *(_QWORD *)(v14[0] + 232LL) = &vars0;
      v9[31] = &v12;
      v9[32] = v4;
      v9[33] = 5;
      v10 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v10;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      *(_QWORD *)(result + 32) = **(_QWORD **)(a2 + 1376);
      v11 = *(_QWORD *)(a3 + 2328);
      *(_QWORD *)(result + 40) = *(_QWORD *)(a3 + 2320);
      *(_QWORD *)(result + 48) = v11;
      *(_DWORD *)(result + 56) = *(_DWORD *)(a3 + 1800);
      *(_QWORD *)(result + 64) = **(_QWORD **)(a3 + 1376);
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
