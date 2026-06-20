__int64 __fastcall perf_trace_core_ctl_notif_data(__int64 result, int a2, int a3, _QWORD *a4, _QWORD *a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x2
  __int64 v16; // x5
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(52, v21, &v20);
    if ( result )
    {
      v14 = (_QWORD *)v21[0];
      v15 = v20;
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v14[31] = &v19;
      v16 = v21[0];
      v14[32] = v6;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      v17 = a4[1];
      *(_QWORD *)(result + 16) = *a4;
      *(_QWORD *)(result + 24) = v17;
      v18 = a5[1];
      *(_QWORD *)(result + 32) = *a5;
      *(_QWORD *)(result + 40) = v18;
      result = perf_trace_run_bpf_submit(result, 52, v15, v9, 1, v16, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
