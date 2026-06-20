__int64 __fastcall trace_event_raw_event_sched_pipeline_tasks(
        __int64 a1,
        int a2,
        int a3,
        __int64 a4,
        int a5,
        int a6,
        char a7,
        int a8,
        char a9)
{
  __int64 v12; // x8
  __int64 v17; // x9
  __int64 result; // x0
  _QWORD *v19; // x8
  __int64 v20; // x9
  __int64 v21; // x9
  int v22; // w9
  int v23; // w10
  __int64 v24; // x21
  _QWORD v26[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1;
  v26[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v26, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v12 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v26, v12, 104);
    if ( result )
    {
      v19 = &init_task;
      *(_DWORD *)(result + 8) = a3;
      *(_DWORD *)(result + 12) = a2;
      if ( (_UNKNOWN *)a4 != &vendor_data_pad )
        v19 = (_QWORD *)(a4 - 5184);
      v20 = v19[291];
      *(_QWORD *)(result + 16) = v19[290];
      *(_QWORD *)(result + 24) = v20;
      *(_DWORD *)(result + 32) = *((_DWORD *)v19 + 450);
      *(_DWORD *)(result + 36) = *(unsigned __int16 *)(a4 + 158);
      *(_DWORD *)(result + 40) = *(_DWORD *)(a4 + 32) / (unsigned int)walt_scale_demand_divisor;
      *(_DWORD *)(result + 44) = *(_DWORD *)(a4 + 364);
      v21 = pipeline_special_task;
      *(_DWORD *)(result + 48) = *(unsigned __int8 *)(a4 + 191);
      *(_DWORD *)(result + 52) = a5;
      if ( v21 )
        v22 = *(_DWORD *)(v21 + 1800);
      else
        v22 = -1;
      *(_DWORD *)(result + 56) = v22;
      v23 = sysctl_sched_pipeline_util_thres;
      *(_BYTE *)(result + 76) = a7 & 1;
      *(_DWORD *)(result + 60) = v23;
      *(_DWORD *)(result + 64) = a6;
      v24 = result;
      *(_DWORD *)(result + 68) = *(_DWORD *)(a4 + 436);
      *(_BYTE *)(result + 77) = *(_BYTE *)(a4 + 432);
      *(_DWORD *)(result + 72) = *(_DWORD *)(a4 + 440);
      ((void (__fastcall *)(__int64, __int64, __int64))pipeline_demand)(a4, result + 80, result + 88);
      *(_DWORD *)(v24 + 96) = a8;
      *(_BYTE *)(v24 + 100) = a9 & 1;
      result = trace_event_buffer_commit(v26);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
