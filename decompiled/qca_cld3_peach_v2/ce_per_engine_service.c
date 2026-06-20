__int64 __fastcall ce_per_engine_service(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  unsigned int v3; // w20
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x21
  _DWORD *v8; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x0
  __int64 v12; // x8

  if ( a2 >= 0xC )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v11 = _traceiter_dp_ce_tasklet_sched_latency(0);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v11);
    }
  }
  else
  {
    v3 = a2;
    v2 = a1;
    v4 = *(_QWORD *)(a1 + 8LL * a2 + 480);
    v5 = hif_target_sleep_state_adjust(a1, 0, 1);
    if ( (v5 & 0x80000000) != 0 )
    {
      qdf_trace_msg(61, 2, "%s: [premature rc=0]", "ce_per_engine_service");
      return 0;
    }
    *(_DWORD *)(v4 + 208) = 0;
    *(_BYTE *)(v4 + 184) = 0;
    v7 = sched_clock(v5, v6);
    *(_QWORD *)(v4 + 200) = v7;
    *(_QWORD *)(v4 + 192) = hif_get_ce_service_max_yield_time(v2) + v7;
  }
  raw_spin_lock(v4 + 168);
  v8 = *(_DWORD **)(v4 + 288);
  if ( *(v8 - 1) != -1512672541 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v8)(v2, v3);
  raw_spin_unlock(v4 + 168);
  if ( (hif_target_sleep_state_adjust(v2, 1, 0) & 0x80000000) != 0 )
    qdf_trace_msg(61, 2, "%s: <--[premature rc=%d]", "ce_per_engine_service", *(_DWORD *)(v4 + 208));
  return *(unsigned int *)(v4 + 208);
}
