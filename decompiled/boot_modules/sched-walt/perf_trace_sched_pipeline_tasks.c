__int64 __fastcall perf_trace_sched_pipeline_tasks(
        __int64 result,
        int a2,
        int a3,
        __int64 a4,
        int a5,
        int a6,
        char a7,
        int a8,
        char a9)
{
  __int64 v9; // x30
  __int64 v10; // x27
  __int64 v12; // x19
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v20; // x9
  _QWORD *v21; // x8
  __int64 v22; // x9
  __int64 v23; // x9
  int v24; // w9
  int v25; // w10
  __int64 v26; // x22
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  int v30; // [xsp+8h] [xbp-18h]
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v30 = a8;
  v10 = v9;
  v12 = result;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v18 = *(_QWORD *)(result + 104);
  v31 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    result = perf_trace_buf_alloc(108, v32, &v31);
    if ( result )
    {
      v20 = (_QWORD *)v32[0];
      *(_QWORD *)(v32[0] + 248LL) = &v29;
      v20[29] = &vars0;
      v21 = (_QWORD *)(a4 - 5184);
      v20[32] = v10;
      v20[33] = 5;
      *(_DWORD *)(result + 8) = a3;
      *(_DWORD *)(result + 12) = a2;
      if ( (_UNKNOWN *)a4 == &vendor_data_pad )
        v21 = &init_task;
      v22 = v21[291];
      *(_QWORD *)(result + 16) = v21[290];
      *(_QWORD *)(result + 24) = v22;
      *(_DWORD *)(result + 32) = *((_DWORD *)v21 + 450);
      *(_DWORD *)(result + 36) = *(unsigned __int16 *)(a4 + 158);
      *(_DWORD *)(result + 40) = *(_DWORD *)(a4 + 32) / (unsigned int)walt_scale_demand_divisor;
      *(_DWORD *)(result + 44) = *(_DWORD *)(a4 + 364);
      v23 = pipeline_special_task;
      *(_DWORD *)(result + 48) = *(unsigned __int8 *)(a4 + 191);
      *(_DWORD *)(result + 52) = a5;
      if ( v23 )
        v24 = *(_DWORD *)(v23 + 1800);
      else
        v24 = -1;
      *(_DWORD *)(result + 56) = v24;
      v25 = sysctl_sched_pipeline_util_thres;
      *(_BYTE *)(result + 76) = a7 & 1;
      *(_DWORD *)(result + 60) = v25;
      *(_DWORD *)(result + 64) = a6;
      v26 = result;
      *(_DWORD *)(result + 68) = *(_DWORD *)(a4 + 436);
      *(_BYTE *)(result + 77) = *(_BYTE *)(a4 + 432);
      *(_DWORD *)(result + 72) = *(_DWORD *)(a4 + 440);
      ((void (__fastcall *)(__int64, __int64, __int64))pipeline_demand)(a4, result + 80, result + 88);
      v27 = v31;
      v28 = v32[0];
      *(_DWORD *)(v26 + 96) = v30;
      *(_BYTE *)(v26 + 100) = a9 & 1;
      result = perf_trace_run_bpf_submit(v26, 108, v27, v12, 1, v28, StatusReg + v18, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
