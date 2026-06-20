__int64 __fastcall perf_trace_sched_select_task_rt(__int64 result, __int64 a2, int a3, int a4, __int64 *a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x8
  __int64 v18; // x8
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(60, v23, &v22);
    if ( result )
    {
      v14 = (_QWORD *)v23[0];
      *(_QWORD *)(v23[0] + 232LL) = &vars0;
      v14[31] = &v21;
      v14[32] = v6;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v15 = *(_QWORD *)(a2 + 2320);
      v16 = *(_QWORD *)(a2 + 2328);
      *(_DWORD *)(result + 28) = a3;
      *(_DWORD *)(result + 32) = a4;
      *(_QWORD *)(result + 20) = v16;
      *(_QWORD *)(result + 12) = v15;
      v17 = &vendor_data_pad;
      if ( (_UNKNOWN *)a2 != &init_task )
        v17 = (_QWORD *)(a2 + 5184);
      *(_QWORD *)(result + 40) = v17[46];
      if ( a5 )
        v18 = *a5;
      else
        v18 = 0;
      v19 = v22;
      v20 = v23[0];
      *(_QWORD *)(result + 48) = v18;
      result = perf_trace_run_bpf_submit(result, 60, v19, v9, 1, v20, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
